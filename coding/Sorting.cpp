#include<iostream>
using namespace std;

void SelectionSort(int arr[],int n){
    if (n<=1) return;
    int smallestindex=0, i;
    for (i=1; i<n;i++){
        if (arr[i]<arr[smallestindex]) smallestindex=i;
    }
    swap(arr[0],arr[smallestindex]);
    SelectionSort(arr+1,n-1);
}

void BubbleSort(int arr[],int n){
    if (n<=1) return;
    for (int i=0;i<n-1;i++){
        if (arr[i]>arr[i+1]) swap(arr[i],arr[i+1]);
    }
    BubbleSort(arr,n-1);
}

void Merge(int arr[], int sPos, int ePos){
    int mid=(sPos+ePos)/2;
    int temp[100];
    for (int i=sPos;i<=ePos;i++) temp[i]=arr[i];
    int i=sPos, j=mid+1, k=sPos;
    while (i<=mid && j<=ePos){
        if (temp[i]<temp[j]) {
            arr[k]=temp[i];
            k++;i++;
        } else {
            arr[k]=temp[j];
            k++;j++;
        }
    }
    while (i<=mid){
        arr[k]=temp[i];
        k++;i++;
    }
    while (j<=ePos){
        arr[k]=temp[j];
        j++;k++;
    }
}

void MergeSort(int arr[], int sPos, int ePos){
    if (sPos>=ePos) return;
    int mid=(sPos+ePos)/2;
    MergeSort(arr,sPos,mid);
    MergeSort(arr,mid+1,ePos);
    Merge(arr,sPos, ePos);
}

int main(){
    int arr[]={5,8,3,0,1,4,9,6,7,2};
    int n=10;
    ///SelectionSort(arr,n);
    ///BubbleSort(arr,n);
    MergeSort(arr,0,n-1);

    for (int i=0;i<n;i++) cout<<arr[i]<<" "; cout<<endl;
}
