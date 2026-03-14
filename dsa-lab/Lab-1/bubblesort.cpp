#include<iostream>
using namespace std;
int main(){
    int n;
    cout << "Enter size of an array: ";
    cin >> n;
    int *a = new int[n];
    cout << "Enter " << n << " elements:\n";
    for(int i=0; i<n; i++){
        cout << "a[" << i << "]: ";
        cin >> a[i];
    }
    cout << "Entered array: ";
    for(int i=0; i<n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
    cout << "Sorted array: "; // bubble sort (ascending)
    for(int i=0; i<n; i++){
        for(int j=0; j<n-i-1; j++){
            if(a[j]>a[j+1]){
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    for(int i=0; i<n; i++){
        cout << a[i] << " ";
    }
    return 0;
}
