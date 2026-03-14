#include<iostream>
using namespace std;
class Node{
    int no;
    Node *next;
public:
    Node(int n=0){
        no=n;
        next=NULL;
    }
    void append(Node*);
    void insertAfter(int,int);
    Node* insertBefore(int,int);
    Node* deleteNode(int);
    void traverse();
};
int main(){
    Node *First = NULL;
    int ch, val, key;
    do{
        cout << "\n1: Append\n2: Insert After\n3: Insert Before\n4: Delete\n5: Traverse\n6: Exit\n";
        cout << "Enter choice: ";
        cin >> ch;
        switch(ch){
        case 1:
            cout << "Enter value: ";
            cin >> val;
            if(First==NULL) First= new Node(val);
            else First->append(new Node(val));
            cout << val << " appended!\n";
            break;
        case 2:
            if(First==NULL) cout << "LIst is empty!\n";
            else{
                cout << "Enter existing value & new value:\n";
                cin >> key >> val;
                First->insertAfter(key,val);
            }
            break;
        case 3:
            if(First==NULL) cout << "List is empty!\n";
            else{
                cout << "Enter existing value & new value:\n";
                cin >> key >> val;
                First->insertBefore(key,val);
            }
            break;
        case 4:
            if(First==NULL) cout << "List is empty!\n";
            else{
                cout << "Enter value to delete: ";
                cin >> val;
                First=First->deleteNode(val);
                cout << val << " deleted!\n";
            }
            break;
        case 5:
            First->traverse();
            break;
        case 6:
            cout << "Exiting program...\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    }
    while(ch!=6);
    return 0;
}
void Node::append(Node* newNode){
    Node *trav=this;
    while(trav->next!=NULL){
        trav=trav->next;
    }
    trav->next=newNode;
}
void Node::insertAfter(int key, int val){
    Node* trav=this;
    while(trav!=NULL){
        if(trav->no==key){
            Node *newNode = new Node(val);
            newNode->next=trav->next;
            trav->next=newNode;
            return;
        }
        trav=trav->next;
    }
    cout << "Element not found!\n";
}
Node* Node::insertBefore(int key, int val){
    if(this->no==key){
        Node *newNode = new Node(val);
        newNode->next=this;
        return newNode;
    }
    Node* prev=NULL;
    Node* curr=this;
    while(curr!=NULL && curr->no!=key) {
        prev=curr;
        curr=curr->next;
    }
    if(curr==NULL){
        cout << "Element not found!\n";
        return this;
    }
    Node *newNode = new Node(val);
    newNode->next=curr;
    prev->next=newNode;
    return this;
}
Node* Node::deleteNode(int n){
    Node* curr=this;
    Node* prev=NULL;
    if(curr->no==n){
        Node* newFirst=curr->next;
        delete curr;
        return newFirst;
    }
    while(curr->next!=NULL && curr->no!=n){
        prev=curr;
        curr=curr->next;
    }
    if(curr->no!=n){
        cout << "Node not found!\n";
        return this;
    }
    prev->next=curr->next;
    delete curr;
    return this;
}
void Node::traverse(){
    cout << "Linked List: ";
    Node* trav=this;
    while(trav!=NULL){
        cout << trav->no  << "->";
        trav=trav->next;
    }
    cout << "NULL\n";
}
