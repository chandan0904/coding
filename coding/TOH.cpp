#include<iostream>
using namespace std;

void TOH(int n, char fm, char to, char via){
    if (n==0) return;
    TOH(n-1,fm,via,to);
    cout<<"Move ring #"<<n<<" fm:"<<fm<<" to:"<<to<<endl;;
    TOH(n-1,via,to,fm);
}


int main(){
    TOH(3,'A','B','C');
}
