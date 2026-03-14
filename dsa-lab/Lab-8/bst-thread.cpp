#include<iostream>
using namespace std;
class Node{
    int data;
    Node* left;
    Node* right;
    bool isThread;
public:
    Node(int val=0){
        data=val;
        left=NULL;
        right=NULL;
        isThread=true;
    }
    friend class Tree;
};
class Tree{
    Node* root;
public:
    Tree(){
        root=NULL;
    }
    void insert(int);
    void inorder();
    bool search(int);
    void display();
    bool isEmpty(){
        return root==NULL;
    }
};

void Tree::insert(int key){
    Node* ptr = root;
    Node* p = NULL;

    while(ptr!=NULL){
        if(key==ptr->data){
            cout<<"Duplicate key";
            return;
        }
        p = ptr;
        if(key<ptr->data){
            ptr=ptr->left;
        }
        else{
            if(ptr->isThread==false){
                ptr=ptr->right;
            }
            else{
                break;
            }
        }

    Node* newNode = new Node(key);

    if(p==NULL){
        root=newNode;
        newNode->isThread=false;
        newNode->right=NULL;
    }
    else if(key<p->data){
        p->left=newNode;
        newNode->right=NULL;
    }
    else{
        newNode->right=p->right;
        p->right=newNode;
        p->isThread=false;
    }
    }
}
void Tree::inorder(){
    if(root==NULL){
        cout<<"tree is empty";
        return;
    }

    Node* ptr = root;

    while(ptr->left != NULL){
        ptr=ptr->left;
    }

    while(ptr!=NULL){
        cout<<ptr->data<<" ";

        if(ptr->isThread) ptr = ptr->right;
        else{
            ptr=ptr->right;
            while(ptr&&ptr->left != NULL){
                ptr=ptr->left;
            }
        }
    }
}

bool Tree::search(int key){
    Node* ptr = root;
    while(ptr!=NULL){
        if(key==ptr->data){
            return true;
        }
        if(key<ptr->data) ptr=ptr->left;
        else{
            if(ptr->isThread) return false;
            ptr = ptr->right;
        }
    }
    return false;
}

void Tree::display(){
    cout<<"inorder display:";
    inorder();
    cout<<endl;
    }

int main(){
    Tree t;
    t.insert(50);
    t.insert(30);
    t.insert(70);
    t.insert(20);
    t.insert(40);
    t.insert(60);
    t.insert(80);

    t.display();

    if(t.search(30)){
        cout<<"found\n";
    }
    else{
        cout<<"Not found\n";
    }
    return 0;
}
