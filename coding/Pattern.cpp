#include<iostream>
using namespace std;

void PatternPrint (int n){
    if (n==0) return;
    for (int i=1;i<=n;i++) cout<<"*";
    cout<<endl;
    PatternPrint(n-1);

}

int main(){
    PatternPrint(5);
}
