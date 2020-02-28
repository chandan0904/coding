#include<iostream>
#define ll long long int 
using namespace std;

ll comput(ll n)
{
	//ll arr[100005]={0};
	int subarr[100005] = {0};
	subarr[0] =1;
	for(int i=0;i<n;i++)
	{
		ll d;
		scanf("%ld",&d);
		int rem = d%n;
		subarr[rem]++;
		
	}
	ll ans=0;
	for(int i=0;i<n;i++)
	{
		ans += (subarr[i]*(subarr[i]-1))/2;
	}
	
	return ans;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		ll n;
		scanf("%ld",&n);
		ll ans = comput(n);
		printf("%ld \n",ans);
	}
	
	
	return 0;
}
