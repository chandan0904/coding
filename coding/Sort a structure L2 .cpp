#include<iostream>
#include<bits/stdc++.h>

using namespace std;

typedef pair<long long,long long> pll;
class Mysort{
public: 
	
	bool operator()(pll p1,pll p2)
	{
		if( p1.first < p2.first )
			return true;
		
		else if(p1.first == p2.first  &&p2.second<p1.second )
			return true;
		
		return false;
	}
};

int main()
{
	int t,n;
	long  x,y;
	vector<pll> arr;
	Mysort mysort;
	cin>>t;

	
	while(t-- >0)
	{
		scanf("%d",&n);

		arr.resize(n);
		for(int i=0; i<n; i++)
		{
			scanf("%lld%lld",&x,&y);
			arr[i] = make_pair(x,y);
		}
		
		sort(arr.begin(),arr.end(),mysort );
		for(int i=0; i<n; i++)
		{
			printf("%lld %lld\n",arr[i].first,arr[i].second);	
		}
		arr.clear();
	}
	
	return 0;
	
}
