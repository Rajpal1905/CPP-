#include<iostream>

using namespace std;

void quickSort(int arr[],int start , int end)
{
   
//    cout<<"indside this";
   int pivot = end ;
   int  i = start - 1;
   int j = start;

    //
    if(start>=end) return;

   while (j<=pivot)
   {
        if (arr[j]<arr[pivot])
        {
            i++;
            swap(arr[i],arr[j]);
        }
        
        j++;
   }
   i++;
   swap(arr[i],arr[pivot]);

   quickSort(arr, start, i-1);

   quickSort(arr, i, end);
   
}

int main(){
    int arr[] = {991,54,88,46,33,99,1,2,3,4};
    int size = sizeof(arr)/sizeof(arr[0]);
    int s  =  0;
   int end = size-1; 
   for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }
    quickSort(arr,s,end );
cout<<endl;
    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }
    

}