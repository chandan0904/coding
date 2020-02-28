#include<iostream>
#include<sstream>
using namespace std;



void allpossible(string str,int sPos,char out[],int oPos)
{
    if(str[sPos] == '\0' )
    {
        out[oPos] = '\0';
        cout<<out<<endl;
        return ;
    }




    out[oPos] =((int)str[sPos]) +48;

    allpossible(str,sPos+1,out,oPos+1);
    stringstream sn(str.substr(sPos,2));
    int num;
    sn>>num;

    if(num < 27&& str[sPos+1]!='\0')
    {
        out[oPos] = (num+96);

        allpossible(str,sPos+2,out,oPos+1);


    }


}

int main()
{
    string str = "1123";
    char out[20]="";
    allpossible(str,0,out,0);
}

