#include<iostream>
using namespace std;




void subString(string str,char out[],int sPos,int oPos)
{
    if(str[sPos] == '\0')
    {
        out[oPos] = '\0' ;

        cout<<out<<endl;
        return ;
    }
    out[oPos] = str[sPos];

    subString(str,out,sPos+1,oPos+1);

    subString(str,out,sPos+1,oPos);

}

int main()
{
    string str="abc";
    char out[100];

    subString(str,out,0,0);


}
