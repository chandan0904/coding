#include<iostream>
#include<cstring>
using namespace std;

int SubStr(char str[],int sPos,string out[]){
    if (str[sPos]=='\0'){
        out[0]="0";
        return 1;
    }
    int c=SubStr(str, sPos+1, out);
    for (int i=0;i<c;i++){
        out[c+i]=out[i]+str[sPos];
    }
    return 2*c;
}

int main(){
    char str[]="abc";
    string out[100];
    int c=SubStr (str,0,out);
    for (int i=0;i<c;i++){
        cout<<out[i]<<endl;
    }

}
