#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

int precedance(char ch){
    if(ch == '+' || ch == '-') return 1;
    if(ch == '*' || ch == '/') return 2;
    if(ch == '^' return 3;
}

string infxtopost(string exp){
    stack<char> st;
    string postfix='';

    for(char ch:exp){
        if(isalnum(s[i])){
                post+=s[i];
            }
            else if(s[i]=='('){
                st.push(s[i]);
            }
            else if(s[i]==')'){
                while(!st.empty() && st.top() != '('){
                        post += st.top();
                        st.pop();
                      }
                      st.pop();
    }



    }
