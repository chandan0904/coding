#include<iostream>
#include<vector>

using namespace std;
int p1=0,p2=0;
void  optimal(vector<int> v,int i,int j,bool f)
{
	
	if(i>j)
	{
		return ;
	}
	if(f)
	{
		if(v[i]>v[j])
		{
			p1+=v[i];
			optimal(v,i+1,j,!f);	
		}
		else
		{
			p1+=v[j];
			optimal(v,i,j-1,!f);
		}
	}
	else
	{
		if(v[i]>v[j])
		{
			p2+=v[i];
			optimal(v,i+1,j,!f);	
		}
		else
		{
			p2+=v[j];
			optimal(v,i,j-1,!f);
		}	
	}
	
	
}

int main()
{
	int n;
	cin>>n;
	vector<int > v(n);
	for(int i=0;i<n;i++)
	{
		cin>>v[i];
	
	}
	
	optimal(v,0,n-1,false);
	int ans;
	ans= max(p1,p2);
	cout<<ans<<endl;
	
	return 0;
}

