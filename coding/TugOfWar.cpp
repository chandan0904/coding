#include<iostream>
#include<cmath>
using namespace std;

void TOW(int arr[],int n,int sPos,int out[],int cntSofar,int SumSofar,int &TotalSum,
         int &mindiff, int mindiffout[]){
    if (cntSofar==n/2){
        ///find diff
        int d=abs(TotalSum-2*SumSofar);
        ///check with min diff and if yes, copy out to mindiffout
        if (d<mindiff){
            mindiff=d;
            for (int i=0;i<n;i++) mindiffout[i]=out[i];
        }
        return;
    }
    if (sPos>=n) return;
    ///let include current member in team-A
    out[sPos]=1;
    TOW(arr,n,sPos+1,out,cntSofar+1,SumSofar+arr[sPos],TotalSum,
        mindiff,mindiffout);
    out[sPos]=0;
    TOW(arr,n,sPos+1,out,cntSofar,SumSofar,TotalSum,
        mindiff,mindiffout);
}

int main(){
    int arr[]={1,2,3,5,7,8,9,10,11,120,110};
    int n=11;int sum=0;
    for (int i=0;i<n;i++) sum+=arr[i];
    int out[100]={};int mindiff=INT_MAX;
    int mindiffout[100];

    TOW(arr,n,0,out,0,0,sum,mindiff,mindiffout);

    cout<<"Minimum difference is:"<<mindiff<<endl;
    cout<<"Team-A: ";
    for (int i=0;i<n;i++){
        if(mindiffout[i]==1) cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<"Team-B: ";
    for (int i=0;i<n;i++){
        if(mindiffout[i]!=1) cout<<arr[i]<<" ";
    }
    cout<<endl;
}
