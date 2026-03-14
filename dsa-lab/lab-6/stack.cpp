#include<iostream>
using namespace std;
class Node{
    int data;
    Node* next;
public:
    friend class stack;
    Node(int val=0){
        data=val;
        next=NULL;
    }
};
class stack{
    Node* tos;
public:
    stack(){
        tos=NULL;
    }
    void push(int val){
        Node* newNode = new Node(val);
        if(isEmpty()){
            tos=newNode;
            newNode->next=NULL;
            cout << tos->data << " pushed into stack.\n";
            return;
        }
        Node* temp=tos;
        newNode->next=tos;
        tos=newNode;
        cout << tos->data << " pushed into stack.\n";
    }
    int pop(){
        if(isEmpty()){
            cout << "Stack is empty!\n";
            return -1;
        }
        int n=tos->data;
        Node* temp=tos;
        tos=tos->next;
        temp->next=NULL;
        delete temp;
        return n;
    }
    int peek(){
        if(isEmpty()){
            cout << "Stack is empty!\n";
            return -1;
        }
        return tos->data;
    }
    bool isEmpty(){
        return tos==NULL;
    }
    void display(){
        if(isEmpty()){
            cout << "Stack is empty!\n";
            return;
        }
        Node* temp=tos;
        cout << "Stack: ";
        while(temp!=NULL){
            cout << temp->data << " ";
            temp=temp->next;
        }
        cout << endl;
    }
};
int main(){
    stack s;
    s.display();
    s.push(10);
    s.push(20);
    cout << "Top of stack: " << s.peek() << endl;
    s.push(30);
    s.display();
    cout << s.pop() << " popped from stack.\n";
    cout << s.pop() << " popped from stack.\n";
    s.display();
    cout << "Top of stack: " << s.peek() << endl;
    return 0;
}
