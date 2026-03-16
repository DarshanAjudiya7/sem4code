#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;
using namespace std::chrono;

// ───── Bubble Sort ─────
void bubbleSort(vector<int> arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}

// ───── Insertion Sort ─────
void insertionSort(vector<int> arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i], j = i - 1;
        while (j >= 0 && arr[j] > key)
            arr[j + 1] = arr[j--];
        arr[j + 1] = key;
    }
}

// ───── Selection Sort ─────
void selectionSort(vector<int> arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[minIdx])
                minIdx = j;
        swap(arr[i], arr[minIdx]);
    }
}

int main() {
    int SIZE = 5000;
    srand(time(0));
    vector<int> data(SIZE);
    for (int i = 0; i < SIZE; i++)
        data[i] = rand() % 10000;

    cout << "\n===== Sorting Time Comparison =====\n";
    cout << "Array size : " << SIZE << " random elements\n\n";

    cout << "First 5000 random values: ";
    for (int i = 0; i < min(5000, SIZE); i++)
        cout << data[i] << " ";
    cout << "\n\n";

    auto t1 = high_resolution_clock::now();
    bubbleSort(data);
    auto t2 = high_resolution_clock::now();
    double bubble = duration<double, milli>(t2 - t1).count();

    auto t3 = high_resolution_clock::now();
    insertionSort(data);
    auto t4 = high_resolution_clock::now();
    double insertion = duration<double, milli>(t4 - t3).count();

    auto t5 = high_resolution_clock::now();
    selectionSort(data);
    auto t6 = high_resolution_clock::now();
    double selection = duration<double, milli>(t6 - t5).count();

    cout << fixed << setprecision(4);
    cout << "Bubble Sort    : " << bubble    << " ms\n";
    cout << "Insertion Sort : " << insertion << " ms\n";
    cout << "Selection Sort : " << selection << " ms\n";
    cout << "===================================\n";

    return 0;
}