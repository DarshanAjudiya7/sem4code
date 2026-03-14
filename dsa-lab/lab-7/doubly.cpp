#include<iostream>
using namespace std;

class Node{
    int data;
    Node* next;
    Node* prev;
public:
    Node(int val=0){
    data = val;
    prev=NULL;
    next=NULL;
    }

    append (Node* head,int val){
    Node* newnode = new Node(val);
    if(head==NULL){
        head=newnode;
        return 0;
    }
    Node* temp= head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next= newnode;
    newnode->prev = temp;
    }

    
    insertfront(Node* head,int val){

    }

    display(Node* head){
        Node* temp = head;
        while(temp!=NULL){
            cout<<temp->data<<"<->";
            temp=temp->next;
        }
        cout<<"NULL\n";
    }

};

int main(){
    Node* n;
    Node* head;
    n->append(head,10);
    n->append(head,20);
    n->append(head,30);
    n->insertfront(head,70);


    n->display(head);
    return 0;
    }
