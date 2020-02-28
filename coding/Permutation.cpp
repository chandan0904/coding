#include<iostream>
using namespace std;

void Permutation(char str[], int sPos){
    if (str[sPos]=='\0'){
        cout<<str<<endl;
        return;
    }
    for (int i=sPos;str[i]!='\0';i++){
        swap(str[sPos],str[i]);
        Permutation(str, sPos+1);
        swap(str[sPos],str[i]);
    }
}

int main(){
    char str[]="abc";
    Permutation(str,0);
}
