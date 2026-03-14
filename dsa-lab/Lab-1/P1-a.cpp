#include<iostream>
using namespace std;
void display(int a[],int b)
{
    for(int i=0;i<b;i++)
    {
        cout << a[i] << " " ;
    }
    cout << endl ;
}
int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int *arr=new int[n];
    cout << "Enter Elements of Array: " << endl ;
    for(int i=0;i<n;i++)
    {
        cout << "Enter elements " << i+1 << ": " ;
        cin >> arr[i];
    }
    cout << endl << "Array you entered: " << endl ;
    display(arr,n);
    int id;
    cout << endl << "Enter the position to delete(0-" << n-1 <<"): ";
    cin >> id;
    int z=n-1;
    int *newarr=new int[z];
    for(int i=0;i<id;i++)
    {
        newarr[i]=arr[i];
    }
    for(int i=id;i<n;i++)
    {
        newarr[i]=arr[i+1];
    }
    cout << "Array after deletion: " << endl ;
    display(newarr,z);
    delete[] arr;
    int ie,ins;
    cout << "Enter position to insert: ";
    cin >> ie;
    cout << "Enter Element: ";
    cin >> ins;
    int y=z+1;
    int *narr=new int[y];
    for(int i=0;i<ie;i++)
    {
        narr[i]=newarr[i];
    }
    narr[ie]=ins;
    for(int i=ie+1;i<y;i++)
    {
        narr[i]=newarr[i-1];
    }
    cout << "Array after Insertion: " << endl ;
    display(narr,y);
    return 0;
}

