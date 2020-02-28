#include<iostream>
using namespace std;
void arrParentheses(char *out,int l,int r,int j)
{
	if(l==0&& r==0)
	{
		out[j]='\0';
		cout<<out<<endl;
	}
	if(l>0)
	{
		out[j]='(' ;
		arrParentheses(out,l-1,r,j+1);

	}
	if(r>l && l>=0)
	{
		out[j]=')' ;
		arrParentheses(out,l,r-1,j+1);

	}
	
	
	
}
int main()
{
	int n;
	cin>>n;
	char out[100];
	arrParentheses(out,n,n,0);
	return 0;
}
