#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> q;

    // Enqueue
    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Front element: " << q.front() << endl;

    q.pop();
    cout << "After popping, front element: " << q.front() << endl;

    cout << "Queue size: " << q.size() << endl;

    if (!q.empty())
        cout << "Queue is not empty." << endl;

    while (!q.empty())
        q.pop();

    cout << "Queue size after popping all elements: " << q.size() << endl;

    if (q.empty())
        cout << "Queue is empty." << endl;

    return 0;
}