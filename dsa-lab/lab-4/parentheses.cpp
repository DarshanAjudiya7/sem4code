#include <iostream>
using namespace std;

class stack
{
    char *stk;
    int tos;
    int size;

public:
    stack()
    {
        cout << "Enter the size of a stack:";
        cin >> size;
        tos = -1;
        stk = new char[size];
    }
    ~stack()
    {
        delete[] stk;
    }
    bool isFull(int tos, int size)
    {
        return tos >= size;
    }
    bool isEmpty(int tos)
    {
        return tos == -1;
    }
    void push(char ch)
    {
        if (isFull(tos, size))
        {
            cout << "The stack is overflow !" << endl;
            return;
        }
        tos++;
        stk[tos] = ch;
    }
    void pop()
    {
        if (isEmpty(tos))
        {
            cout << "The stack is underflow !" << endl;
            return;
        }
        char x = stk[tos];
        tos--;
    }
    char peek()
    {
        return stk[tos];
    }
    bool check_paranthesis(string s)
    {
        for (int i=0;i<s.length();i++)
        {
            if (s[i] == '{' || s[i] == '[' || s[i] == '(')
            {
                push(s[i]);
            }
            if (s[i] == '}' || s[i] == ']' || s[i] == ')')
            {
                if (s[i] == '}' && (peek() == '[' || peek() == '('))
                    return false;
                else if (s[i] == ']' && (peek() == '{' || peek() == '('))
                    return false;
                else if (s[i] == ')' && (peek() == ']' || peek() == '}'))
                    return false;
                pop();
            }
        }

        if (!isEmpty(tos))
        {
            return false;
        }
        return true;
    }
};

int main()
{
    stack s;
    string st;
    cout << "Enter a string:";
    cin >> st;


    if (s.check_paranthesis(st))
    {
        cout << "Valid Paranthesis !" << endl;
    }
    else
    {
        cout << "Invalid Paranthesis !" << endl;
    }

    return 0;
}
