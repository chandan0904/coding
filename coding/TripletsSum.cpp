#include<bits/stdc++.h>

using namespace std;

int solve(vector<double> v,int n)
{
	double a,b,c;
	if(n<3)
	{
		return -1;
	}
	a=v[0], b=v[1], c=v[2];
	double m;
	double sum=a+b+c;
	for(int i=3;i<n;i++)
	{
		if(sum<2 && sum>1) return 1;
		
		else if(sum>=2)
		{
			
			m = max(a,max(b,c));
			m==a?a=v[i]:(m==b?b=v[i]:c=v[i]);
			//cout<<"here1 "<<m<<endl;
			sum-=m;
			sum += v[i];		
		}
		else if(sum<=1)
		{
			
			m = min(a,min(b,c));
			m==a?a=v[i]:(m==b?b=v[i]:c=v[i]);
			//cout<<"000000"<<m<<endl;
			sum-=m;
			sum+=v[i];
		}
	}
	if(sum<2 && sum>1) return 1;
	return -1;
	
}

int main()
{
	vector<double> v;
	int n;
	double a;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a;
		v.push_back(a);
	}
	
	cout<<solve(v,n);
}

//5 0.6 0.7 0.8 1.2 0.4
