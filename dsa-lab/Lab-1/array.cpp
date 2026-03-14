#include<iostream>
using namespace std;
void display(int a[], int n){
    for(int i=0; i<n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}
int main(){
    int n, x, y;
    cout << "Enter size of an array: ";
    cin >> n;
    int *a = new int[n];
    cout << "Enter " << n << " elements:\n";
    for(int i=0; i<n; i++){
        cout << "a[" << i << "]: ";
        cin >> a[i];
    }
    cout << "Entered array: ";
    display(a, n);
    int d;
    cout << "Enter position to delete its element: ";
    cin >> d;
    x=n-1;
    int *na = new int[x];
    for(int i=0; i<d-1; i++){
        na[i]=a[i];
    }
    for(int i=d-1; i<x; i++){
        na[i]=a[i+1];
    }
    delete[] a;
    cout << "Array after deletion: ";
    display(na, x);
    int p, ie;
    cout << "Enter position to insert: ";
    cin >> p;
    cout << "Enter element: ";
    cin >> ie;
    y=x+1;
    int *narr = new int[y];
    for(int i=0; i<p-1; i++){
        narr[i]=na[i];
    }
    narr[p-1]=ie;
    for(int i=p; i<y; i++){
        narr[i]=na[i-1];
    }
    cout << "Array after insertion: ";
    display(narr, y);
    return 0;
}
