#include<iostream>
#include<cstdlib>
#include<ctime>
#include<chrono>
using namespace std;
using namespace std::chrono;

void bubblesort(int arr[],int n)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n-1-i; j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}

void display(int arr[],int n)
{
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";

    }
    cout<<endl;
}
int main()
{
    int n=10000;
    int arr[10000];

    srand(time(0));
    for(int i=0; i<100; i++)
    {
        arr[i] = rand() % 100 +1 ;

    }

    cout<<"before sorting:";
    display(arr,n);

    auto start = high_resolution_clock::now();
    bubblesort(arr,n);
    auto end=high_resolution_clock::now();

    cout<<"after sorting:";
    display(arr,n);

    auto us = duration_cast<microseconds>(end-start).count();
    auto ns = duration_cast<nanoseconds>(end-start).count();
    cout<<"\ntime taken in microseconds:"<<us<<endl;
    cout<<"\ntime taken in nanoseconds:"<<ns<<endl;

}
