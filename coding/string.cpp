#include<iostream>
#include<cstring>
using namespace std;

int main(){
    string str1="Rajesh";
    string str2="Sachdev";
    string str=str1+" " +str2;
    cout<<str<<endl;

    string arr[5];
    arr[0]="Zero";
    arr[1]="One";
    arr[2]="Two";

    cout<<arr[1]<<endl;
    cout<<str1[0]<<str1[1]<<endl;

    cout<<str1.length()<<endl;
}
