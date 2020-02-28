#include<bits/stdc++.h>
using namespace std;

int maxCostRod(int arr[],int n,int rod)
{
	if(rod<=0) return 0;
	
	int ans=0;
	for(int i=0;i<n;i++)
	{
		if(rod>=arr[i])
		{
			ans = max(ans,maxCostRod(arr,n,rod-arr[i]) +arr[i]) ;
		}
	}
	return ans;
}
int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	int rod;
	cin>>rod;
	cout<<maxCostRod( arr,n,rod);
	return 0;
}
