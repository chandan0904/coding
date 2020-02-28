#include<iostream>
using namespace std;


int subString(char str[],int oPos,string out[])
{
    if(str[oPos] == NULL )
    {
        out[0] = '\0';
        return 1;
    }

    int c = subString(str,oPos+1,out);
    for(int i = 0; i<c;i++)
            out[c+i] = str[oPos] + out[i];

    return 2*c;
}






int main()
{
    char str[] = "abc";
    string out[100];

    int c = subString(str,0,out);

    for(int i=0;i<c;i++)
    {
        cout<<""<<out[i];
    }

}
