#include<iostream>
using namespace std;
class stack{
    char *s;
    int n, tos=0;
    public:
    stack(bool b=true);
    void reverse(stack&);
    void display();
};
int main(){
    stack a;
    stack b(false);
    a.display();
    cout << "Reverse string: ";
    a.reverse(b);
    b.display();
    return 0;
}
stack::stack(bool b){
    if(b){
        cout << "Enter string size: ";
        cin >> n;
        s = new char[n];
        cout << "Enter string: ";
        for(int i=0; i<n; i++){
            cin >> s[i];
            tos++;
        }
    }
}
void stack::reverse(stack &b){
    b.n=n;
    b.s = new char[b.n];
    for(int i=0; i<b.n; i++){
        b.s[i]=s[tos-1];
        b.tos++;
        tos--;
    }
}
void stack::display(){
    cout << "String: ";
    for(int i=0; i<tos; i++){
        cout << s[i];
    }
    cout << endl;
}