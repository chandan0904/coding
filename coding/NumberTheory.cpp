#include<iostream>
#include<vector>
using namespace std;

void prime()
{
	int num;
	cin>>num;
	bool v[num+1]={0};
	
	for(int i=3;i<=num;i+=2)
	{
		v[i]=1;
	}
	//v[1]=0;
	v[2]=1;
	
	for(int i=3;i<=num; i+=2)
	{
		if(v[i])
		for(int j= i*i; j<=num; j+= 2*i)
		{
			v[j]=0;
		}
	}
	
	for(int i=1;i<=num; i++)
	{
		if(v[i])
			cout<<i<<" ";
	}
}
/////////////////GCD////////////////////
int gcd(int a,int b)
{
	if(b==0)
		return a;
	
	return gcd(b,a%b);
}

int lcm(int a,int b)
{
	return a*b/gcd(a,b);
}

/////////////DIVISBLE SUBARRAY//////////////////////
void divisbleSubarray()
{
	int n,a;
	cin>>n;
	vector<int> arr;
	for(int i=0;i<n;i++)
	{
		cin>>a;
		arr.push_back(a);
	}
	
	vector<int> p(n+1,0);
	int temp=0;
	p[0]=1;
	for(int i=0;i<n;i++)
	{
		temp = (temp+arr[i])%n;
		cout<<temp<<" ";
		p[temp]++;
		
	}
	cout<<endl;
	
	int ans=0;
	for(int i=0;i<=n;i++)
	{
		cout<<p[i]<<" ";
		ans+= (p[i]*(p[i]-1)) /2;
		
		
	}
	cout<<endl;
	cout<<ans;

}


int main()
{
	divisbleSubarray();
	//cout<<gcd(14,10)<<endl;
	//cout<<lcm(14,10)<<endl;
	//prime();
	return 0;
}
