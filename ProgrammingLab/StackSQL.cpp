#include <iostream>
#include <stack>

using namespace std;

int main() {
    // Create a stack of integers
    stack<int>s;

    // Push 10,20,30 elements onto the stack
    s.push(10);
    s.push(20);
    s.push(30);
    
    // Display the top element of the stack
    cout<<"top of element: "<<s.top()<<endl;
    
    // Pop the top element from the stack
    s.pop();
    
    // Check if the stack is empty, if not empty display size. else display stack is now empty.
    cout<<"After popping, top element: "<<s.top()<<endl;
    
    if(!s.empty()){
    cout<<"stack is not empty. Size: "<<s.size()<<endl;
    }
    
    // Pop remaining elements
    s.pop();
    s.pop();
    
    // Check again if the stack is empty
    if(s.empty()){
    cout<<"stack is now empty."<<endl;
    }
 
    return 0;
}

