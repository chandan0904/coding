#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef pair<int,pair<int,int> > ppii;

struct Node
{
	int h;
	int i,j;
	int pi,pj;
	
};
struct pNode
{
	int pi,pj;
	bool flag =0;
};

struct setComp{
	bool operator()(Node cell1,Node cell2)
	{
		return cell1.h > cell2.h;
	}
};

bool solve(int maze[10][10],pNode closeList[10][10],priority_queue<Node,vector<Node>,setComp> openList,pii goal,int n)
{
	
	if(openList.empty()){ return false;}

	Node cell = openList.top();
	openList.pop();
	int i,j;
	i=cell.i;
	j=cell.j;
	closeList[i][j].flag=1;
	closeList[i][j].pi=cell.pi;
	closeList[i][j].pj=cell.pj;
	
	if(i==goal.first && j==goal.second)
	{
		stack<pii> path;
		path.push(make_pair(i,j));
		while(closeList[i][j].pi!=-1 && closeList[i][j].pj!=-1)
		{
			int k,l;
			k=closeList[i][j].pi;
			l=closeList[i][j].pj;
			i=k; j=l;
			path.push(make_pair(i,j));
		}
		while(!path.empty())
		{
			cout<<" ->";
			cout<<"["<<path.top().first<<" "<<path.top().second<<"]"<<endl;
			path.pop();
		}
		return true;
	}

	
	if(i<n-1 && maze[i+1][j]!=-1 && !closeList[i+1][j].flag)
	{
		Node temp;
		temp.i=i+1;
		temp.j=j;
		temp.pi=i;
		temp.pj=j;
		temp.h=maze[i+1][j];
		openList.push(temp );
	}
	if(j<n-1 && maze[i][j+1]!=-1 && !closeList[i][j+1].flag)
	{
		Node temp;
		temp.i=i;
		temp.j=j+1;
		temp.pi=i;
		temp.pj=j;
		temp.h=maze[i][j+1];
		openList.push(temp );
	}
	if(i>0 && maze[i-1][j]!=-1 && !closeList[i-1][j].flag)
	{
		Node temp;
		temp.i=i-1;
		temp.j=j;
		temp.pi=i;
		temp.pj=j;
		temp.h=maze[i-1][j];
		openList.push(temp );
	}
	if(j>0 && maze[i][j-1]!=-1 && !closeList[i][j-1].flag)
	{
		Node temp;
		temp.i=i;
		temp.j=j-1;
		temp.pi=i;
		temp.pj=j;
		temp.h=maze[i][j-1];
		openList.push(temp);
	}
	return solve(maze,closeList,openList,goal,n);


}
int main()
{
	int maze[10][10] = {
						{-1,4,2,3,4,2,2,4,-1,-1},
						{-1,5,2,-1,-1,-1,2,5,4,-1},
						{-1,6,1,1,3,4,1,-1,3,-1},
						{-1,5,-1,-1,2,-1,1,-1,3,-1},
						{-1,3,-1,-1,2,-1,2,-1,6,-1},
						{-1,2,-1,-1,2,-1,1, 3, 4, 4},
						{-1, 2, 1, 3, 4,-1, 1,-1, -1, 5},
						{-1,3,-1,-1, 3, 2, 1,-1, -1, 3},
						{-1,2,-1,-1,-1,-1, 1,-1, 2, 2},
						{-1,1, 2, 2, 1, 1, 0,-1, 1,-1}
	};
	priority_queue<Node,vector<Node>,setComp> openList;
	pNode closeList[10][10];
	closeList[0][4].pi=-1;
	closeList[0][4].pj=-1;
	closeList[0][4].flag=1;
	pii goal= make_pair(9,6);
	Node cell;
	cell.i=0;
	cell.j=4;
	cell.pi=-1;
	cell.pj=-1;
	cell.h=4;
	openList.push(cell);
 	solve(maze,closeList,openList,goal,10);
 	/*cout<<"\n=========="<<endl;
 	cout<<"0 1 2 3 4 5 6 7 8 9 "<<endl;
 	for(int k=0;k<10;k++)
 	{
 		for(int l=0;l<10;l++)
 		{
 			cout<<closeList[k][l].flag<<" ";	
		}
		cout<<endl;
	}*/
	return 0;
}
