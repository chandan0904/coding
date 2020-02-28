#include<iostream>
using namespace std;

int SumOfArray(int arr[], int n){
    if (n==0) return 0;
    return arr[n-1]+SumOfArray(arr,n-1);
}

int main(){
    int arr[]={1,2,3,4,5,6,7,8,9,10};
    int n=10;
    cout<<SumOfArray(arr,n);
}
