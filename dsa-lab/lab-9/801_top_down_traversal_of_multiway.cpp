#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

class MultiwayTreeNode {
public:
    string value;
    vector<MultiwayTreeNode*> children;
    int order;

    MultiwayTreeNode(string val, int ord) {
        value = val;
        order = ord;
    }

    void addChild(MultiwayTreeNode* child) {
        if ((int)children.size() < order) {
            children.push_back(child);
        } else {
            cout << "Cannot add more than " << order << "children to this node.\n";
        }
    }
};


class MultiwayTree {
public:
    MultiwayTreeNode* root;
    int order;

    MultiwayTree(int ord) {
        root = nullptr;
        order = ord;
    }

    MultiwayTreeNode* insert(string val, MultiwayTreeNode* parent = nullptr) {
        MultiwayTreeNode* newNode = new MultiwayTreeNode(val, order);
        if (root == nullptr) {
            root = newNode;
            return root;
        }

        if (parent == nullptr) {
            cout << "Parent node required for insertion (except root).\n";
            return nullptr;
        }

        parent->addChild(newNode);
        return newNode;
    }

    void topDownTraversal() {
        if (!root) {
            cout << "Tree is empty.\n";
            return;
        }

        queue<MultiwayTreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            MultiwayTreeNode* node = q.front();
            q.pop();
            cout << node->value << " ";

            for (auto child : node->children) {
                q.push(child);
            }
        }
        cout << endl;
    }

    MultiwayTreeNode* findNode(string val) {
        if (!root) return nullptr;
        queue<MultiwayTreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            MultiwayTreeNode* node = q.front();
            q.pop();
            if (node->value == val) return node;
            for (auto child : node->children) {
                q.push(child);
            }
        }
        return nullptr;
    }
};

int main() {


    MultiwayTree tree(3);

    string rootVal;
    cout << "Enter root value: ";
    cin >> rootVal;
    MultiwayTreeNode* root = tree.insert(rootVal);

    char choice;
    do {
        cout << "Do you want to add a child? (y/n): ";
        cin >> choice;
        cin.ignore();
        if (choice == 'n') break;

        string parentVal;
        cout << "Enter parent value: ";
        cin >> parentVal;

        MultiwayTreeNode* parentNode = tree.findNode(parentVal);
        if (parentNode) {
            string childVal;
            cout << "Enter child value: ";
            cin >> childVal;
            cin.ignore();
            tree.insert(childVal, parentNode);
        } else {
            cout << "Parent not found!\n";
        }

    } while (true);

    cout << "\nTop-down traversal of the tree:\n";
    tree.topDownTraversal();

    return 0;

}
