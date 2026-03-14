#include<iostream>
using namespace std;
class Node{
    int data;
    Node* next;
    Node* prev;
public:
    Node(int val=0){
    data = val;
    next=NULL;
    prev=NULL;
    }
    friend class tree;
};

class tree{
    Node* root;
public:
    tree(){
        root=NULL;
    }
    void append(int);

};

void tree::append(int val){
    Node* newnode= new node(val);
    if(root==NULL){
        root=newnode;
        return;
    }
    Node* temp = root;
    while(1){

    }
    if(val<temp->data){
        if(root->prev==NULL){
            root->prev=newnode;
            return;
        }
        temp=temp->prev;
    }
}

int main(){
    Node* n;
    n->append(5);
    return 0;
}

