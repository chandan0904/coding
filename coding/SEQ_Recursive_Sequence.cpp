#include<iostream>
#include<vector>

using namespace std;
#define ll long long
#define MOD 1000000000

vector<ll> b,c;
int k;

vector<vector<ll>> multiply(vector<vector<ll>> A,vector<vector<ll>> B)
{
	vector<vector<ll>> C(k+1,vector<ll>(k+1));

	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=k;j++)
		{
			for(int l=1;l<=k;l++)
			{
				C[i][j] = (C[i][j] + (A[i][l]*B[l][j])%MOD)%MOD;
			}
			
		}
		
	}
	return C;
	
}

vector<vector<ll>> pow(vector<vector<ll>> T,ll n)
{
	if(n==1)
	{
		return T;
	}
	
	vector<vector<ll>> X = pow(T,n/2);
	X = multiply(X,X);
	
	if(n&1)
	{
		X = multiply(T,X);
	}
	return  X;
	
}

ll sequence(ll n)
{
	vector<ll> F(k+1),C(k+1);
	vector<vector<ll> > T(k+1,vector<ll>(k+1));
 	
 	for(int i=0;i<k;i++)
 	{
 		F[i+1]= b[i];
 		C[i+1]= c[i];
 		
	}
	
 	if(n<=k)
 	{
 		return F[n]	;
	}
 	
	for(int i =1;i<=k;i++)
 	{
 		for(int j=1;j<=k;j++)
		{
			if(i<k)
			{
				if(i+1 ==j)
				{	
					T[i][j]=1;
				
				}
				else
				{
					T[i][j]=0;
				}
				continue;		 	
			}
			T[i][j]= C[k-j+1];
		}	
	}
	T = pow(T,n-1);
	
	ll ans = 0;
	
	for(int i=1;i<=k;i++)
	{
		ans = (ans+ (T[1][i]*F[i])%MOD)%MOD;
	}
	
	return ans;
	
}

int main()
{
	int t;
	cin>>t;
	
	while(t--)
	{
		ll n;
		
		
		cin>>k;
		int d;
		for(int i=0;i<k;i++)
		{
			cin>>d;
			b.push_back(d);
		}
		for(int i=0;i<k;i++)
		{
			cin>>d;
			c.push_back(d);
		}
		
		cin>>n;
				
		cout<<sequence(n)<<endl;
		b.clear();
		c.clear();
		
	}
	
	return 0;
}
