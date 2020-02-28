#include<iostream>
using namespace std;

int power(int x, int n){
    if (n==0) return 1;
    ///return x* power(x,n-1);
    int chotaPower=power(x,n/2);
    if (n%2==0) return chotaPower*chotaPower;
        else return chotaPower*chotaPower*x;
}

int main(){
    cout<<power(2,10);
}
