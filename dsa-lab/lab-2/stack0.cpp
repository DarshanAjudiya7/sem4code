#include<iostream>
using namespace std;
class stack{
    int *s, n, tos=0;
public:
    stack();
    void push();
    void pop();
    void display();
};
int main(){
    stack s;
    int ch;
    bool run=true;
    while(run){
        cout << "1: Push an element\n";
        cout << "2: Pop an element\n";
        cout << "3: Display Stack\n";
        cout << "4: Exit\n";
        cout << "Enter your choice: ";
        cin >> ch;
        switch (ch){
        case 1:
            s.push();
            break;
        case 2:
            s.pop();
            break;
        case 3:
            s.display();
            break;
        case 4:
            run=false;
            break;
        default:
            cout << "Invalid choice!\n";
            break;
        }
    }
    return 0;
}
stack::stack(){
    cout << "Enter stack size: ";
    cin >> n;
    s = new int[n];
}
void stack::push(){
    if(tos==n-1){
        cout << "Stack is overflow!\n";
    }
    else{
        int a;
        cout << "Enter value: ";
        cin >> a;
        s[tos]=a;
        tos++;
    }
}
void stack::pop(){
    if(tos==0){
        cout << "Stack is empty!\n";
    }
    else{
        s[tos]=0;
        tos--;
        cout << "Popped successfully!\n";
    }
}
void stack::display(){
    cout << "Stack: ";
    for(int i=0; i<tos; i++){
        cout << s[i] << " ";
    }
    cout << endl;
}