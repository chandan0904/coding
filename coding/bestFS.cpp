#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef pair<int,pair<int,int> > ppii;

typedef struct Node
{
	int i,j;
	int pi,pj;
	int h;
};




struct setComp{
	bool operator()(Node cell1,Node cell2)
	{
		return cell1.h < cell2.h;
	}
};




bool solve(int maze[10][10],map<int,pii> &path,bool closeList[10][10],set<Node,setComp> openList,pii goal,int n)
{
	//cout<<"i m here "<<endl;
	if(openList.empty()){ return false;}

	Node cell = *openList.begin();
	int i,j;
	i=cell.i;
	j=cell.j;
	closeList[i][j]=1;
	openList.erase(openList.begin());
	path[i+j] = make_pair(cell.pi,cell.pj);
	
	//cout<<i+j<<endl;
	if(i==goal.first && j==goal.second)
	{
		//print(path);
		stack<pii> pth;
		pth.push(make_pair(i,j));
		pii ij = path[i+j];
		int k,l;
		k=ij.first;
		l=ij.second;
		cout<<"gghsghhhhh"<<endl;
		map<int,pii>::iterator itr;
		for(itr = path.begin();itr!=path.end();itr++)
		{
			//map<int,pii> p = itr;
			cout<<itr->first<<" "<<itr->second.first<<" "<<itr->second.second<<endl;
		}
		
		/*while(k!=-1 && l != -1)
		{
			pth.push(make_pair(i,j));
			ij=path[k+l];
			k=ij.first;
			l=ij.second;
			
		}
		while(!pth.empty())
		{
			cout<<"["<<pth.top().first<<" "<<pth.top().second<<"]"<<"  -> ";
			pth.pop();
		}*/
		return true;
	}

	
	if(i<n-1 && maze[i+1][j]!=-1 && !closeList[i+1][j])
	{
		Node temp;
		temp.i=i+1;
		temp.j=j;
		temp.pi=i;
		temp.pj=j;
		temp.h=maze[i+1][j];
		openList.insert(temp );
	}
	if(j<n-1 && maze[i][j+1]!=-1 && !closeList[i][j+1])
	{
		Node temp;
		temp.i=i;
		temp.j=j+1;
		temp.pi=i;
		temp.pj=j;
		temp.h=maze[i][j+1];
		openList.insert(temp );
		//openList.insert(make_pair(maze[i][j+1],make_pair(i,j+1)) );
	}
	if(i>0 && maze[i-1][j]!=-1 && !closeList[i-1][j])
	{
		Node temp;
		temp.i=i-1;
		temp.j=j;
		temp.pi=i;
		temp.pj=j;
		temp.h=maze[i-1][j];
		openList.insert(temp );
		//openList.insert(make_pair(maze[i-1][j],make_pair(i-1,j)) );
	}
	if(j>0 && maze[i][j-1]!=-1 && !closeList[i][j-1])
	{
		Node temp;
		temp.i=i;
		temp.j=j-1;
		temp.pi=i;
		temp.pj=j;
		temp.h=maze[i][j-1];
		openList.insert(temp );
		//openList.insert(make_pair(maze[i][j-1],make_pair(i,j-1)) );
	}
	bool ch;
	ch = solve(maze,path,closeList,openList,goal,n);
	//path.pop();
	return ch;
	//if(ch){ return ch; }
	//closeList[i][j]==0;
	/*while(!openList.empty())
	{
		return solve(maze,path,closeList,openList,goal,n);
	}*/
	
	return false;


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
						{-1, 2, 1, 3, 4,-1, -1,-1, -1, 5},
						{-1,3,-1,-1, 3, 2, 1,-1, -1, 3},
						{-1,2,-1,-1,-1,-1, 1,-1, 2, 2},
						{-1,1, 2, 2, 1, 1, 0,-1, 1,-1}
	};
	bool closeList[10][10]={0};
	set<Node,setComp> openList;
	
	closeList[0][4]=1;
	//vector<pii> path;
	map<int,pii> path;
	//stack<Node> path;;
	
	pii goal= make_pair(9,6);
	Node cell;
	cell.i=0;
	cell.j=4;
	cell.pi=-1;
	cell.pj=-1;
	cell.h=4;
	openList.insert(cell);
	
 	solve(maze,path,closeList,openList,goal,10);
 	cout<<"\n=========="<<endl;
 	cout<<"0 1 2 3 4 5 6 7 8 9 "<<endl;
 	for(int k=0;k<10;k++)
 	{
 		for(int l=0;l<10;l++)
 		{
 			cout<<closeList[k][l]<<" ";	
		}
		cout<<endl;
	}
	return 0;
}
