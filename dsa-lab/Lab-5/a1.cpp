#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
template <class T>
class stack{
    int n, tos;
    T *s;
public:
    stack();
    void push(T);
    T pop();
    bool check(string);
    string convert_post(string);
    int precedence(char);
    string convert_pre(string);
    string reversestr(string);
    void evaluate_pre(string);
};
int main(){
    stack<char> s;
    stack<int> r;
    string str, pre;
    cout << "Enter Infix Expression: ";
    cin >> str;
    try{
        if(s.check(str)){
            cout << "Valid Expression!\n";
            pre=s.convert_pre(str);
            cout << "Infix to Prefix: " << pre << endl;
        }
        else cout << "Invalid Expression!\n";
    }
    catch(char const*e){
        cout << e << endl;
    }
    r.evaluate_pre(pre);
    return 0;
}
template <class T> stack<T>::stack(){
    cout << "Enter stack size: ";
    cin >> n;
    s = new T[n];
    tos=-1;
}
template <class T> void stack<T>::push(T x){
    if(tos==n-1) throw "Stack is overflow! No further elements can be inserted.\n";
    else{
        s[++tos]=x;
        cout << x << " pushed into stack.\n";
    }
}
template <class T> T stack<T>::pop(){
    T y;
    if(tos==-1) throw "Stack is underflow! No element is present in stack!\n";
    else return y=s[tos--];
}
template <class T> bool stack<T>::check(string str){
    for(int i=0; i<str.length(); i++){
        if(str[i]=='{' || str[i]=='[' || str[i]=='(') push(str[i]);
        else if(str[i]=='}' || str[i]==']' || str[i]==')'){
            if((str[i]=='}' && s[tos]=='{') || (str[i]==']' && s[tos]=='[') || (str[i]==')' && s[tos]=='(')) pop();
            else throw "Invalid Expression!\n";
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
        if(str[i]>='A' && str[i]<='Z' || str[i]>='a' && str[i]<='z' || str[i]>='0' && str[i]<='9') post+=str[i];
        else if(str[i]=='{' || str[i]=='[' || str[i]=='(') push(str[i]);
        else if(str[i]=='}'){
            while(tos!=-1 && s[tos]!='{'){
                post+=pop();
            }
            pop();
        }
        else if(str[i]==']'){
            while(tos!=-1 && s[tos]!='['){
                post+=pop();
            }
            pop();
        }
        else if(str[i]==')'){
            while(tos!=-1 && s[tos]!='('){
                post+=pop();
            }
            pop();
        }
        else{
            while(tos!=-1 && precedence(s[tos])>precedence(str[i]) || precedence(s[tos])==precedence(str[i]) && str[i]=='^'){
                post+=pop();
            }
            push(str[i]);
        }
    }
    while(tos!=-1){
        /*char x=pop();
        if(x!='(') post+=x;*/
        post+=pop();
    }
    return post;
}
template <class T> string stack<T>::convert_pre(string str){
    string pre=reversestr(str);
    pre=convert_post(pre);
    pre=reversestr(pre);
    return pre;
}
template <class T> string stack<T>::reversestr(string str){
    int i=0, j=str.length()-1;
    while(i<j){
        char temp=str[i];
        str[i]=str[j];
        str[j]=temp;
        i++;
        j--;
    }
    for(int i=0; i<str.length(); i++){
        if(str[i]=='(') str[i]=')';
        else if(str[i]==')') str[i]='(';
    }
    return str;
}
template <class T> void stack<T>::evaluate_pre(string pre){
    pre=reversestr(pre);
    for(int i=0; i<pre.length(); i++){
        char ch=pre[i];
        if(ch>='0' && ch<='9') push(ch-'0');
        else{
            int a=pop();
            int b=pop();
            if(ch=='+') push(a+b);
            if(ch=='-') push(a-b);
            if(ch=='*') push(a*b);
            if(ch=='/') push(a/b);
            if(ch=='^') push(pow(a,b));
        }
    }
    cout << "Result=" << pop();
}
