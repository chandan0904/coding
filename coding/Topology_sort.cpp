#include<iostream>
#include<list>
#include<map>
#include<queue>

using namespace std;

template<typename T>
class Graph{
	int V;
	map<T,list<T> > adjList;
	bool bidirectional;

	public:
		Graph(int v,bool bid)
		{
			V=v;
			bidirectional = bid;	
		}
	void addedge(int u,int v)
	{
		adjList[u].push_front(v);
		adjList[v];
		if(bidirectional)
		{
			adjList[v].push_front(u);
		}
	}
	void print()
	{
		typename map<T,list<T> >::iterator itr;
		//for( itr:adjList)
		for( itr = adjList.begin();itr!=adjList.end();itr++)
		{
			cout<<itr->first<<"-> ";
			for(T i:itr->second)
			{
				cout<<i<<", ";
			}
			cout<<endl;
		}
		cout<<endl;
	}
	
	void dfsHelperToplg(T vertex,map<T,bool> &visited,list<T> &ordered)
	{
		visited[vertex]=true;
		
		for(T neighbour :adjList[vertex])
		{
			if(!visited[neighbour])
			{
				dfsHelperToplg(neighbour,visited,ordered);
			}
		}
		ordered.push_front(vertex);
	}
	void dfsTopologySort()
	{
		list<T> ordered;
		map<T,bool> visited;
		typename map<T,list<T> >::iterator itr;
		for(itr=adjList.begin();itr!=adjList.end();itr++)
		{
			T vertex = itr->first;
			if(!visited[vertex])
			{
				dfsHelperToplg(vertex,visited,ordered);
			}
		}
		
		printOrderd(ordered);
	}
	
	void printOrderd(list<T> ordered)
	{
		
		for(T vertex:ordered)
		{
			cout<<vertex<<"-> ";
		}
		cout<<"\n\n";
	}
	void bfsHelperToplg(queue<T> &q,map<T,bool> &visited,map<T,int> &indegree)
	{
		while(!q.empty())
		{
			T node = q.front();
			q.pop();
			cout<<node<<"-> ";
			visited[node]=true;
			for(T i:adjList[node])
			{
				if(!visited[i])
				{
					indegree[i]--;
					if(indegree[i]==0)
					{
						q.push(i);
					}
				}				
			}
		}
		
	}
	void bfsTopologySort()
	{
		map<T,bool> visited;
		map<T,int> indegree;
		queue<T> q;
		for(pair<T,list<T> > i:adjList)
		{
			indegree[i.first]=0;
		}
		for(pair<T,list<T> > node:adjList)
		{
			for(T i:node.second)
			{
				indegree[i]++;
			}
			
		}
		for(pair<T,list<T> > i:adjList)
		{
			if(indegree[i.first]==0)
			{
				q.push(i.first);
			}
		}
		
		bfsHelperToplg(q,visited,indegree);
	}
	
};

	



int main()
{
	Graph<int> g(6,false);
	
	g.addedge(0,2);
	g.addedge(1,2);
	g.addedge(1,4);
	g.addedge(2,3);
	g.addedge(4,5);
	g.addedge(3,5);
	//g.addedge(5,0);
	
	g.print();
	g.dfsTopologySort();
	g.bfsTopologySort();
	return 0;
}
