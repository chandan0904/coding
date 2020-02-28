#include<iostream>
#include<vector>
#include<set>
#include<cstring>
using namespace std;
#define v  vector<int>
#define vv  vector<vector<int>>

set<string> st;
int count=0;
int row[8]={-2,-2,-1,-1,1,1,2,2};
int col[8]={-1,1,-2,2,-2,2,-1,1};

void print(vv bord,int n)
{
	string str = "";
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(bord[i][j]==1)
			{
				string a=to_string(i);
				
				string b=to_string(j);
				//cout<<a<<" "<<b<<endl;
				str += "{"+a+" "+b+"} ";
			}
		}
	}
	str+=" ";
	st.insert(str);
}

bool safe(vv bord,int n,int r,int c)
{
	for(int i=0;i<8;i++)
	{
		if(r+row[i]>=0 && r+row[i]<n && c+col[i]>=0 && c+col[i]<n && bord[r+row[i]][c+col[i]]==1)
		{
			return false;
		}
	}

	return true;
}

void n_knight(vv &bord,int &n,int r,int c,int k)
{
	if(bord[r][c]==0 && safe(bord,n,r,c))
	{
		bord[r][c]=1;
		if(k==1)
		{
			count++;
			print(bord,n);
			bord[r][c]=0;
			return ;
		}
		for(int i=r;i<n;i++)
		{
			for(int j=c+1;j<n;j++)
			{
				n_knight(bord,n,i,j,k-1);
				
			}
		}
		
		for(int i=r+1;i<n;i++)
		{
			for(int j=0;j<=c;j++)
			{
				n_knight(bord,n,i,j,k-1);
				
			}
		}
		
		bord[r][c]=0;
	}
}

int main()
{
	int n;
	cin>>n;
	vv bord(n,v(n,0));
	
	//for(int i=0;i<n;i++)
	//	for(int j=0;j<n;j++)
	//	{
			n_knight(bord,n,0,0,n);	
	//	}
	for(string s:st)
	{
		cout<<s<<endl;
	}		
	
			
	cout<<count<<endl;		
	return 0;
}
