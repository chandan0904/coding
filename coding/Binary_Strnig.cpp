#include<iostream>
using namespace std;
void  Binry_String(char *out,int &count,int f,int n,int j)
{
    if(n==0)
    {
        out[j]='\0';
        count++;
        cout<<out<<endl;
        return ;
    }
    if(f)
    {
        out[j] = '0';
        Binry_String(out,count,1,n-1,j+1);
        out[j] = '1';
        Binry_String(out,count,0,n-1,j+1);
    }
    else
    {
    	 out[j] = '0';
        Binry_String(out,count,1,n-1,j+1);
    }
}
int main() {
    int t;
    cin>>t;
    while(t--)
    {

        int n;
        cin>>n;
        char out[100];
        int count=0;
        out[0]='0';
        Binry_String(out,count,1,n-1,1);
        out[0]='1';
        Binry_String(out,count,0,n-1,1);
        cout<<count<<endl;

    }

	return 0;
}
