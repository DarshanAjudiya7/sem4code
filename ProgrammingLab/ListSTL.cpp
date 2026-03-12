#include <iostream>
#include <list>
using namespace std;

class ListManager {
    list<int> lst;
public:
    void insert(int position, int value) {
        if (position < 0 || position > lst.size()) {
            cout << "Invalid position!" << endl;
            return;
        }
        auto it = lst.begin();
        advance(it, position);
        lst.insert(it, value);
    }

    void append(int value) {
        lst.push_back(value);
    }

    void remove(int value) {
        auto it = find(lst.begin(), lst.end(), value);
        if (it == lst.end()) {
            cout << "Element not found!" << endl;
            return;
        }
        lst.erase(it);
    }

    void print() const {
        if (lst.empty()) { cout << "The list is empty!" << endl; return; }
        for (int x : lst) cout << x << " ";
        cout << endl;
    }

    void sortList() { lst.sort(); }

    void pop() {
        if (lst.empty()) { cout << "The list is empty!" << endl; return; }
        lst.pop_back();
    }

    void reverseList() { lst.reverse(); }
};