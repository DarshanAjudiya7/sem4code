#include <iostream>
#include <queue>
using namespace std;

int main() {
    priority_queue<int> pq;

    cout << "Max Priority Queue (Highest to Lowest):" << endl;

    int x;

    // Take 5 inputs
    for (int i = 0; i < 5; i++) {
        cin >> x;
        pq.push(x);
    }

    while (!pq.empty()) {
        cout << "Top: " << pq.top() << endl;
        pq.pop();
    }

    return 0;
}