#include<iostream>
#include<vector>

using namespace std;
#define ll long long int
#define MOD 1000000007

int k;
ll comput(int n,ll  memo[])
{
    if(n<k) return 1;
    if(n==k) return 2;
	if(memo[n] != 0) return memo[n];
	
	memo[n] = ((comput(n-1,memo))%MOD+(comput(n-k,memo))%MOD)%MOD;
	
	return memo[n];
}
int main()
{
	int t;
	scanf("%d",&t);
	
	while(t--)
	{
		int n,m;
		ll memo[100000] = {0};
		scanf("%d %d",&n,&m);
		k=m;
		for(int i=0;i<m;i++)
		{
			cout<<memo[i]<<" ";
		}
		/*memo[m]=2;
	
		if(n <= m)
		{
			cout<<memo[n]<<endl;
		}
		else{*/
	
			cout<<comput(n,memo)<<endl;
		//}
	
	}
	return 0;
}
