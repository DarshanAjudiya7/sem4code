#include<iostream>
using namespace std;

const int order = 4;

class node
{
public:
    int keys[order-1];
    node* child[order];
    int count;
    bool isleaf;
    node* next;

    node(bool leaf=false) : count(0),isleaf(leaf),next(nullptr)
    {
        for(int i=0; i<order; i++)child[i]=nullptr;
    }

};

class BPlusTree {
private:
    node* root;

    node* findLeaf(int key) {
        if (!root) return nullptr;
        node* current = root;
        while (!current->isleaf) {
            int i = 0;
            while (i < current->count && key >= current->keys[i]) i++;
            current = current->child[i];
        }
        return current;
    }

    void insertIntoLeaf(node* leaf, int key) {
        int i = leaf->count - 1;
        while (i >= 0 && leaf->keys[i] > key) {
            leaf->keys[i+1] = leaf->keys[i];
            i--;
        }
        leaf->keys[i+1] = key;
        leaf->count++;
        if (leaf->count == order - 1) {
            splitLeaf(leaf);
        }
    }

    void splitLeaf(node* leaf) {
        node* newLeaf = new node(true);
        int mid = (order - 1) / 2;
        for (int i = mid + 1; i < order - 1; i++) {
            newLeaf->keys[i - mid - 1] = leaf->keys[i];
            newLeaf->count++;
        }
        leaf->count = mid + 1;
        newLeaf->next = leaf->next;
        leaf->next = newLeaf;
        int promote = newLeaf->keys[0];
        if (leaf == root) {
            node* newRoot = new node(false);
            newRoot->keys[0] = promote;
            newRoot->count = 1;
            newRoot->child[0] = leaf;
            newRoot->child[1] = newLeaf;
            root = newRoot;
        } else {
            insertIntoParent(leaf, promote, newLeaf);
        }
    }

    void insertIntoParent(node* left, int key, node* right) {
        node* parent = findParent(root, left);
        if (!parent) return;
        int i = parent->count - 1;
        while (i >= 0 && parent->keys[i] > key) {
            parent->keys[i+1] = parent->keys[i];
            parent->child[i+2] = parent->child[i+1];
            i--;
        }
        parent->keys[i+1] = key;
        parent->child[i+2] = right;
        parent->count++;
        if (parent->count == order - 1) {
            splitInternal(parent);
        }
    }

    void splitInternal(node* internal) {
        node* newInternal = new node(false);
        int mid = (order - 1) / 2;
        int promote = internal->keys[mid];
        for (int i = mid + 1; i < order - 1; i++) {
            newInternal->keys[i - mid - 1] = internal->keys[i];
            newInternal->count++;
        }
        for (int i = mid + 1; i < order; i++) {
            newInternal->child[i - mid - 1] = internal->child[i];
            internal->child[i] = nullptr;
        }
        internal->count = mid;
        if (internal == root) {
            node* newRoot = new node(false);
            newRoot->keys[0] = promote;
            newRoot->count = 1;
            newRoot->child[0] = internal;
            newRoot->child[1] = newInternal;
            root = newRoot;
        } else {
            insertIntoParent(internal, promote, newInternal);
        }
    }

    node* findParent(node* current, node* child) {
        if (current->isleaf || !current) return nullptr;
        for (int i = 0; i <= current->count; i++) {
            if (current->child[i] == child) return current;
            node* p = findParent(current->child[i], child);
            if (p) return p;
        }
        return nullptr;
    }

public:
    BPlusTree() { root = nullptr; }

    void insert(int key) {
        if (!root) {
            root = new node(true);
            root->keys[0] = key;
            root->count = 1;
            return;
        }
        node* leaf = findLeaf(key);
        insertIntoLeaf(leaf, key);
    }

    bool search(int key) {
        node* leaf = findLeaf(key);
        if (!leaf) return false;
        for (int i = 0; i < leaf->count; i++) {
            if (leaf->keys[i] == key) return true;
        }
        return false;
    }

    void display() {
        displayHelper(root, 0);
    }

    void displayHelper(node* current, int level) {
        if (!current) return;
        for (int i = 0; i < level; i++) cout << "  ";
        cout << "[";
        for (int i = 0; i < current->count; i++) {
            cout << current->keys[i];
            if (i < current->count - 1) cout << ",";
        }
        cout << "]" << (current->isleaf ? " (leaf)" : "") << endl;
        if (!current->isleaf) {
            for (int i = 0; i <= current->count; i++) {
                displayHelper(current->child[i], level + 1);
            }
        }
    }

    void inorder() {
        if (!root) return;
        node* current = root;
        while (!current->isleaf) {
            current = current->child[0];
        }
        while (current) {
            for (int i = 0; i < current->count; i++) {
                cout << current->keys[i] << " ";
            }
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    BPlusTree tree;
    tree.insert(10);
    tree.insert(20);
    tree.insert(5);
    tree.insert(15);
    tree.insert(25);
    tree.insert(30);
    tree.insert(35);

    cout << "B+ Tree Display:" << endl;
    tree.display();

    cout << "\nInorder Traversal: ";
    tree.inorder();

    cout << "\nSearch 15: " << (tree.search(15) ? "Found" : "Not Found") << endl;
    cout << "Search 100: " << (tree.search(100) ? "Found" : "Not Found") << endl;

    return 0;
}


