#include<iostream>
using namespace std;

int power(int a,int b)
{
	if(b==0)
		return 1;
		
	int ans = power(a,b/2);
	ans *= ans;
	if(b&1)
	{
		ans *= a;
	}
	return ans;
	
}
int main()
{
	int a,b;
	cin>>a>>b;
	
	cout<<power(a,b);
	
	return 0;
}
