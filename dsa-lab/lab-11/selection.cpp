#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

void selectionsort(int arr[],int n)
{
    for(int i=0; i<n-1; i++)
    {
        int min=i;
        for(int j=1+i; j<n; j++)
        {
            if(arr[j]<arr[min])
                min= j;
        }

        if(min!=i)
        {
            int temp=arr[i];
            arr[i]=arr[min];
            arr[min]=temp;
        }
    }
};

void display(int arr[],int n)
{
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<"";
        if(i<n-1) cout<<",";

    }
    cout<<endl;
}
int main()
{
    int n=10;
    int arr[10];

    srand(time(0));
    for(int i=0; i<10; i++)
    {
        arr[i] = rand() % 100 +1 ;

    }

    cout<<"before sorting:";
    display(arr,n);
    clock_t start = clock();
    selectionsort(arr,n);
    clock_t end = clock();

    double timeTaken = (double)(end-start)/CLOCKS_PER_SEC;


    cout<<"\nafter sorting:";
    display(arr,n);

    cout<<"\ntime taken:"<<timeTaken<<" "<<timeTaken*1000<<" "<<timeTaken*10000000000000;

}
