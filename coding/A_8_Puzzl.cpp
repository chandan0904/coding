#include<iostream>
//#include<vector>
#include<bits/stdc++.h>

using namespace std;


#define N  3
//#define	i first 
//#define j second

typedef pair<int,int> pii;



class Node{
public:
	int grid[N][N];
	bool closeList[N][N];
	int h;
	int f;
	int g;
	pii blank;
	Node *parent;
	Node()
	{
		g=0;
		f=0;
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<N;j++)
			{
				closeList[i][j]=0;
			}
		}
	}
};

struct compareNode
{
	bool operator()(Node n1,Node n2)
	{
	   return n1.h+n1.g > n2.h+n2.g;
	}	
};


Node* newNode(Node  currentNode,int x,int y) 
{ 
	Node* node = new Node; 

	// set pointer for path to root 
	node->parent = currentNode.parent; 

	// copy data from parent node to current node 
	memcpy(node->grid,currentNode.grid, sizeof node->grid); 

	// move tile by 1 postion 
	int i=currentNodet.blank.first;
	int j=currentNode.blank.second;
	swap(node->grid[i][j], node->grid[i+x][j+y]); 

	// set number of misplaced tiles 
	node->cost = INT_MAX; 

	// set number of moves so far 
	node->g = currentNode.g+1;; 

	// update new blank tile cordinates 
	node->blank.first = i+x; 
	node->blank.second = j+y; 

	return node; 
} 


int manhattanDistance(Node currentState,map<int,pii> goalState)
{
	int heuristic=0;
	int x;
	int a,b;
  	for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {    
				x = currentState.grid[i][j];
				if(x==0) continue;	
				//cout<<"x = "<<x;
				a = goalState[ x ].first - i;
                b = goalState[ x ].second - j;
           	    a = a<0?-a:a;
                b = b<0?-b:b;  
				//cout<<" a = "<<a<<" b = "<<b<<" distance = "<<(a+b)<<" i = "<<i<<" j = "<<j<<" g_i = "<<goalState[ x ].first<<" g_j = "<<goalState[ x ].second<<endl;                 
                heuristic += (a+b);
			}
        }
    return heuristic;
    //cout<<"distance : "<<currentState.h<<endl;
}

bool isSafe(int i,int j)
{
	return (i>=0 && i<N && j>=0 && j<N);
}

pii findBlank(Node currentState)
{
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			if(currentState.grid[i][j]==0)
			{
				return make_pair(i,j);
			}
		}
	}
}

void printNode(Node node)
{
	cout<<endl;
	for(int i=0;i<3;i++)
    {
    	for(int j=0;j<3;j++)
    	{
    		cout<<node.grid[i][j]<<" ";
		}
		cout<<endl;
	}
	/*cout<<"\ncloseList\n";
	for(int i=0;i<3;i++)
    {
    	for(int j=0;j<3;j++)
    	{
    		cout<<node.closeList[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<"F(h+g) =  "<<node.f<<"  g = "<<node.g<<"  h = "<<node.h<<"\n"<<endl;

	*/
}
int main()
{
	Node node;
	node.grid[0][0]= 8 ; node.grid[0][1]= 0 ; node.grid[0][2]= 6 ;
	node.grid[1][0]= 5 ; node.grid[1][1]= 4 ; node.grid[1][2]= 7 ;
	node.grid[2][0]= 2 ; node.grid[2][1]= 3 ; node.grid[2][2]= 1 ;
	
	map<int,pii> goalState;
	int a=0;
	for(int i=0;i<3;i++)
    {
    	for(int j=0;j<3;j++)
    	{
    		
    		goalState[a] = make_pair(i,j);
    		//cout<<a<<" = ("<<goal_state[a].first<<" "<<goal_state[a].second<<" )"<<endl;
    		a++;
		}
	}

	manhattanDistance(node,goalState);
	//cout<<node.h<<endl;
	findBlank(node);
	//cout<<node.blank.first<<" "<<node.blank.second<<endl;;
	
	node.g=0;
	priority_queue<Node,vector<Node>,compareNode> openlist;
	openlist.push(node);
	//printNode(node);
	Node current ;
	int d =0;
	int i,j;
	while(!openlist.empty())
	{
		d++;
		current = openlist.top();
		openlist.pop();
		i=current.blank.first;
		j=current.blank.second;
		current.closeList[i][j]=1;
		cout<<"   EXTRACT "<<d<<endl;
		cout<<"i = "<<i<<" j = "<<j<<endl;
		
		printNode(current);
		if(current.h==0 ) {
			cout<<"solved : "<<d<<endl;
			printNode(current);
			 return 1;
		}	
		//cout<<current.h<<endl;
		//cout<<current.blank.first<<" "<<current.blank.second<<endl;
		
		if(i<2 && !current.closeList[i+1][j])
		{
			cout<<"DOWN\n";
			
			swap(current.grid[i][j],current.grid[i+1][j]);
		
			manhattanDistance(current,goalState);
			current.blank.first= i+1;
			//current.blank.second=j;
			current.g+=1;
			current.f=current.h+current.g;
			openlist.push(current);
			printNode(current);
			swap(current.grid[i][j],current.grid[i+1][j]);
			current.blank.first= i;
			current.g-=1;
		}
		if(i>0 && !current.closeList[i-1][j])
		{
			cout<<"UP\n";
			swap(current.grid[i][j],current.grid[i-1][j]);
			
			manhattanDistance(current,goalState);
			current.blank.first= i-1;
			current.blank.second=j;
			current.g+=1;
			current.f=current.h+current.g;
			openlist.push(current);
			printNode(current);
			swap(current.grid[i][j],current.grid[i-1][j]);
			current.blank.first= i;
			current.g-=1;
		}
		if(j<2 && !current.closeList[i][j+1])
		{
			cout<<"RIGHT\n";
			swap(current.grid[i][j],current.grid[i][j+1]);
			manhattanDistance(current,goalState);
			//current.blank.first= i;
			current.blank.second=j+1;
			current.g+=1;
			current.f=current.h+current.g;
			openlist.push(current);
			printNode(current);
			swap(current.grid[i][j],current.grid[i][j+1]);
			current.blank.second=j;
			current.g-=1;
		}
		if(j>0 && !current.closeList[i][j-1])
		{
			cout<<"LEFT\n";
			swap(current.grid[i][j],current.grid[i][j-1]);
			manhattanDistance(current,goalState);
			//current.blank.first= i;
			current.blank.second=j-1;
			current.g+=1;
			current.f=current.h+current.g;
			openlist.push(current);
			printNode(current);
			swap(current.grid[i][j],current.grid[i][j-1]);
			current.blank.second=j;
			current.g-=1;
		}
		//current.closeList[i][j]=0;
		/*cout<<" im here"<<endl;
		int a=1;
		while(!openlist.empty())
		{
			cout<<" NODE "<<a++<<"\n"<<endl;
			Node current = openlist.top();
			openlist.pop();
		
			printNode(current);
			
		}*/
		
	}
	
	cout<<"Not Found";
	return 0;
}
