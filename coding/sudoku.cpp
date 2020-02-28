#include <iostream>
#include <bitset>
#include<cmath>

using namespace std;

#define N 9

bitset<N> col[N],row[N];

void print(int grid[N][N])
{
	int a=0,b=0;
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			++a;
			cout<<grid[i][j]<<" ";
			if(a==3)
			{
				cout<<"  ";
				a=0;
			}
			
		}
		cout<<endl;
		++b;
		if(b==3)
		{
			cout<<"\n";
			b=0;
		}
	}	

}
bool isSafe(int grid[N][N],int i,int j,int num,int n)
{
	for(int x=0;x<n;x++)
	{
		if(grid[i][x]==num || grid[x][j]==num)
			return false;
	}
	int nr=sqrt(n);
	int si=(i/nr)*nr;
	int sj=(j/nr)*nr;
	//cout<<nr<<endl;
	for(int k=si;k<si+nr;k++)
	{
		for(int l=sj;l<sj+nr;l++ )
		{
			if(grid[k][l]==num)
				return false;
		}
	}
	return true;
}
bool solveSudoku(int grid[N][N],int r,int c,int n)
{
	if(r==n)
	{
		print(grid);	
		return true;
	}
	if(c==n)
	{
		return solveSudoku(grid,r+1,0,n);
	}
	if(grid[r][c]!=0)
	{
		return solveSudoku(grid,r,c+1,n);
	}
	
	for(int num=1;num<=9;num++)
	{
		if(isSafe(grid,r,c,num,n))
		{
			grid[r][c]=num;
			bool ch= solveSudoku(grid,r,c+1,n);
			
			if(ch)
			return ch;
			
		}
	}
	grid[r][c]=0;
	
	return false;	
}
int main()
{
	int grid[N][N] = {{3, 0, 6, 5, 0, 8, 4, 0, 0}, 
                      {5, 2, 0, 0, 0, 0, 0, 0, 0}, 
                      {0, 8, 7, 0, 0, 0, 0, 3, 1}, 
                      {0, 0, 3, 0, 1, 0, 0, 8, 0}, 
                      {9, 0, 0, 8, 6, 3, 0, 0, 5}, 
                      {0, 5, 0, 0, 9, 0, 6, 0, 0}, 
                      {1, 3, 0, 0, 0, 0, 2, 5, 0}, 
                      {0, 0, 0, 0, 0, 0, 0, 7, 4}, 
                      {0, 0, 5, 2, 0, 6, 3, 0, 0}};
                    
	//print(grid);
	//cout<<endl;

	solveSudoku(grid,0,0,N);
	//print(grid);
	return 0;
}

