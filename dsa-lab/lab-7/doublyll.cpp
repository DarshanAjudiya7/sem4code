#include<iostream>
using namespace std;
class Node{
    int data;
    Node* next;
    Node* prev;
public:
    Node(int val=0){
        data=val;
        next=NULL;
        prev=NULL;
    }
    friend class Doubly;
};
class Doubly{
    Node* head;
    Node* tail;
    public:
    Doubly(){
        head=NULL;
        tail=NULL;
    }
    void append(int);
    void insert_front(int);
    void deleteNode(int);
    void traverse();
};
int main(){
    Doubly ll;
    ll.append(1);
    ll.insert_front(2);
    ll.append(3);
    ll.insert_front(4);
    ll.deleteNode(1);
    ll.insert_front(20);
    cout << "Doubly Linear Linked List: ";
    ll.traverse();
    return 0;
}
void Doubly::append(int val){
    Node* newNode = new Node(val);
    if(head==NULL){
        head=newNode;
        return;
    }
    Node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newNode;
    newNode->prev=temp;
    tail=newNode;
}
void Doubly::insert_front(int val){
    Node* newNode = new Node(val);
    if(head==NULL){
        head=newNode;
        return;
    }
    head->prev=newNode;
    newNode->next=head;
    head=newNode;
}
void Doubly::deleteNode(int val){
    if(head==NULL){
        cout << "LL is empty!\n";
        return;
    }
    Node* temp=head;
    if(head->data==val){
        head=head->next;
        if (head!=NULL) head->prev=NULL;
        temp->next=NULL;
        delete temp;
        return;
    }
    while(temp->data!=val){
        temp=temp->next;
        if(temp==NULL){
            cout << "Node not found!\n";
            return;
        }
    }
    if(temp->next==NULL){
        Node* temp0=temp->prev;
        temp0->next=NULL;
        temp->prev=NULL;
        delete temp;
        return;
    }
    Node* temp1=temp->prev;
    Node* temp2=temp->next;
    temp1->next=temp2;
    temp2->prev=temp;
    temp->next=temp->prev=NULL;
    delete temp;
}
void Doubly::traverse(){
    Node* temp=head;
    cout << "NULL<->";
    while(temp!=NULL){
        cout << temp->data << "<->";
        temp=temp->next;
    }
    cout << "NULL" << endl;
}
