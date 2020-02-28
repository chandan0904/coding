#include<iostream>
#include<vector>

using namespace std;

#define v vector<int>
#define vv vector<v>
#define vs vector<string>
#define p(x) printf("%s",x)
#define s(x) scanf("%s",&x)

int n,m;

bool rat_maze(vs &maze,int i,int j,vv &path)
{
	if(i==n-1 && j==m-1)
	{
		path[i][j]=1;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				cout<<path[i][j]<<" ";
			}
			cout<<endl;
		}
		
		return true;
	}
	
	path[i][j]=1;
	if(j+1<m && maze[i][j+1]!='X' && rat_maze(maze,i,j+1,path)) return true;
	if(i+1<n && maze[i+1][j]!='X' && rat_maze(maze,i+1,j,path))  return true;
	path[i][j]=0;
	return false;	
}

int main()
{

	//s(n),s(m);
	cin>>n>>m;
	vs maze(n);
	vv path(n,v(m,0));
	for(int i=0;i<n;i++)
	{
		cin>>maze[i];
		
	}
	/*cout<<endl;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(maze[i][j]!='X')
				cout<<maze[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;*/
	if(!rat_maze(maze,0,0,path))
		cout<<-1;
	return  0;
}
