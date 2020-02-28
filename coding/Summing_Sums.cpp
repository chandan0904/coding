#include<iostream>
#include<vector>
#include<cassert>

using namespace std;
#define ll long long int 
#define MOD  98765431

vector<vector<ll> > multiply(vector<vector<ll> > A,vector<vector<ll> > B)
{
	int r = A.size(), c = A[0].size(),r1 = B.size(),c1 = B[0].size();
	
	assert(c==r1);
	vector<vector<ll> > res(r,vector<ll>(c1,0));
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c1;j++)
		{
			for(int k=0;k<r1;k++)
			{
				res[i][j]= (res[i][j]+ (A[i][k]*B[k][j])%MOD)%MOD;
			}
		}
	}
	
	return res;
}

vector<vector<ll> > pow(vector<vector<ll> > T,ll n)
{
	if(n==1)
		return T;
	vector<vector<ll> > X = pow(T,n/2);
	X = multiply(X,X);
	if(n&1)
	{
		X = multiply(T,X);
		
	}
	return X;
}
int main()
{
	ll n,t;
	cin>>n>>t;
	vector<ll> v(n);
	ll sum = 0;
	for(ll i=0; i<n;i++)
	{
		cin>>v[i];
		sum = (sum+v[i])%MOD;
	}
	vector<vector<ll> > T(2,vector<ll>(2));
	
	T[0][0] = 1,T[1][0]=2,T[0][1]=1, T[1][1]=0;
	
	T = pow(T,t);
	
	vector<vector<ll> > M(2,vector<ll>(2));
	
	for(ll i=0;i<n;i++)
	{
		M[0][0]=(sum-v[i])%MOD, M[0][1]= v[i], M[1][0]=12,M[1][1]=123;
		
		cout<<multiply(M,T)[0][1]<<endl;
	}
	
	return 0;
}
