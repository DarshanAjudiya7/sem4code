#include<iostream>
#include<cstring>
using namespace std;
template <class T>
class stack{
    int n, tos;
    T *s;
public:
    stack();
    void push(T);
    T pop();
    void display();
    bool check(string);
    string convert_post(string);
    int precedence(char);
};
int main(){
    stack<char> s;
    string str, post;
    cout << "Enter Infix Expression: ";
    cin >> str;
    try{
        if(s.check(str)){
            cout << "Valid Expression!\n";
            post=s.convert_post(str);
            cout << "Infix to Postfix: " << post << endl;
        }
        else{
            cout << "Invalid Expression!\n";
        }

    }
    catch(char const*e){
        cout << e << endl;
    }
    return 0;
}
template <class T> stack<T>::stack(){
    cout << "Enter stack size: ";
    cin >> n;
    s = new T[n];
    tos=-1;
}
template <class T> void stack<T>::push(T x){
    if(tos==n-1) throw "Stack is overflow! no further elements can be inserted.\n";
    else{
        s[++tos]=x;
        cout << x << " pushed into stack.\n";
    }
}
template <class T> T stack<T>::pop(){
    T y;
    if(tos==-1){
        throw "Stack is underflow! No element present in stack!\n";
    }
    else{
        return y=s[tos--];
    }
}
template <class T> bool stack<T>::check(string str){
    for(int i=0; i<str.length(); i++){
        if(str[i]=='{' || str[i]=='[' || str[i]=='('){
            push(str[i]);
        }
        else if(str[i]=='}' || str[i]==']' || str[i]==')'){
            if((str[i]=='}' && s[tos]=='{') || (str[i]==']' && s[tos]=='[') || (str[i]==')' && s[tos]=='(')){
                pop();
            }
            else{
                throw "Invalid Expression!";
            }
        }
    }
    if(tos==-1) return 1;
    else return 0;
}
template <class T> int stack<T>::precedence(char op){
    if(op=='^') return 3;
    if(op=='*' || op=='/') return 2;
    if(op=='+' || op=='-') return 1;
    return 0;
}
template <class T> string stack<T>::convert_post(string str){
    string post;
    for(int i=0; i<str.length(); i++){
        if(str[i]>='A' && str[i]<='Z' || str[i]>='a' && str[i]<='z' || str[i]>=0 && str[i]<=9){
            post+=str[i];
        }
        else if(str[i]=='{' || str[i]=='[' || str[i]=='('){
            push(str[i]);
        }
        else if(str[i]=='}'){
            while(tos!=-1 && s[tos]!='{'){
                post+=s[tos];
                pop();
            }
            pop();
        }
        else if(str[i]==']'){
            while(tos!=-1 && s[tos]!='['){
                post+=s[tos];
                pop();
            }
            pop();
        }
        else if(str[i]==')'){
            while(tos!=-1 && s[tos]!='('){
                post+=s[tos];
                pop();
            }
            pop();
        }
        else{
            while(tos!=-1 && precedence(s[tos])>precedence(str[i]) || precedence(s[tos])==precedence(str[i]) && str[i]!='^'){
                post+=s[tos];
                pop();
            }
            push(str[i]);
        }
    }
    while(tos!=-1){
        post+=s[tos];
        pop();
    }
    return post;
}
template <class T> void stack<T>::display(){
    cout << "Stack: ";
    for(int i=0; i<=tos; i++){
        cout << s[i] << " ";
    }
    cout << endl;
}
