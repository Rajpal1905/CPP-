#include<iostream>

using namespace std;

void merge(int arr[] , int s , int e ){
    int mid = (s+e)/2;
    
    int leftArrLen = mid - s + 1;
    
    int rightArrlen = e - mid;
    
    int leftArr[leftArrLen] ;
    int rightArr[rightArrlen] ;
    
    int k = s;
    
    for(int i = 0 ; i < leftArrLen ; i++)
    {
        leftArr[i] = arr[k];
        k++;
    }
    //  not actully effect if tell that k = mid +1

    // k= mid+1;
    for(int i = 0 ; i < rightArrlen ; i++)
    {
        rightArr[i] = arr[k];
        k++;
    }
    
    int leftArrIndex = 0;
    int rightArrIndex = 0;
    int mainArrIndex = s;
    
    while(leftArrIndex<leftArrLen && rightArrIndex<rightArrlen)
    {
        if(leftArr[leftArrIndex]<rightArr[rightArrIndex])
        {
            arr[mainArrIndex] = leftArr[leftArrIndex];
            leftArrIndex++;
            mainArrIndex++;
            
        }
        else{
            arr[mainArrIndex] = rightArr[rightArrIndex];
            rightArrIndex++;
            mainArrIndex++;
        }
        
    }
    
    while(leftArrIndex<leftArrLen)
    {
        arr[mainArrIndex] = leftArr[leftArrIndex];
            leftArrIndex++;
            mainArrIndex++;
    }
    while(rightArrIndex<rightArrlen){
        arr[mainArrIndex] = rightArr[rightArrIndex];
            rightArrIndex++;
            mainArrIndex++;
    }
}

void mergeSort(int arr[], int s , int e)
{
    if(s>=e){
        return ;
    }
    
    int mid = (s+e)/2;
    
    //call for left partition
    
    mergeSort(arr,s,mid);
    
    // call for right partition
    
    mergeSort(arr,mid+1,e);
    
    // actull merge logic
    
    merge(arr,s,e);
    
    
}




int main()
{
    int arr[]={3,2,1,4,9,8,7,0};
    int s = 0;
    int e = (sizeof(arr)/sizeof(arr[0]))-1;
    cout<<"arr before sort : ";
    for(int i = 0 ; i < e +1 ; i++){
        cout<<arr[i]<<" " ;
    }
    
    mergeSort(arr,s,e);
    
    cout<<"\narr after sort : ";
    for(int i = 0 ; i < e +1 ; i++){
        cout<<arr[i]<<" " ;
    }
    
    
    return 0;
}