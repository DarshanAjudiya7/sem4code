#include<iostream>
using namespace std;

class Node{
    int data;
    Node* next;
    Node* prev;

    Node(int val){
        data = val;
        prev = NULL;
        next = NULL;
        }

        void append(Node*);
        void insertAfter(int,int);
        void insertBefore(int,int);
        Node* deleteNode(int);
        void traverse();
};

void Node :: append(Node* newNode){
    Node* trav = this;
    while(trav->next!=NULL){
        trav = trav -> next;
    }
    trav -> next = newNode;
}

void Node::insertAfter(int key,int val){
    Node* trav = this;
    while(trav!=NULL){
        if(trav->no==key){
            Node* newNode = new Node(val);
            newNode->next = trav->next;
            trav->next-newNode;
        }
        trav=trav->next;
    }
    cout<<"element not found!\n";
}


int main(){
    Node* first = NULL;
    int ch,val,key;
    do{
        cout<<"\n 1.Append \n 2.Insert After \n 3.Insert Before \n 4.Delete Node \n 5.Traverse \n 6.Exit";
        cout<<"enter choice";
        cin>>ch;

        switch(ch){
    case 1:
        cout<<"enter value:";
        cin>>val;
        if(first==NULL){
            first= new Node(val);
        }
        else{
            first->append(new Node(val));
            cout<<val<<"appended!\n";
        }
        break;

    case 2:
        if(first==NULL){
            cout<<"list is empty!\n";
        }
        else{
            cout<<"enter existing value and new value:\n";
            cin>>key>>val;
            first->insertAfter(key,val);
        }
        break;

    case 3:
        if(first==NULL){
            cout<<"list is empty!\n";
        }
        else{
            cout<<"enter existing value and new value:\n";
            cin>>key>>val;
            first->insertBefore(key,val);
        }
        break;
    case 4:
        if(first==NULL){
            cout<<"list is empty!\n";
        }
        else{
            cout<<"enter value:\n";
            cin>>val;
            first->first->deleteNode(val);
            cout<<val<<"deleted!\n";
        }
        break;

    case 5:
        first->traverse();
        break;

    case 6:
        cout<<"exit...";
        break;

    default:
        cout<<"invalid choice";
    }
    }
    while(ch!=6)
    return 0;
    }


