#include<iostream>
using namespace std;

int Factorial(int n){
    if (n==0) return 1;
    int ChotaAns=Factorial(n-1);
    return n* ChotaAns;

}

int main(){
    cout<<Factorial(5);
}

