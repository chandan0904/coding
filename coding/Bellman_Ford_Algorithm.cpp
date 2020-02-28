#include<iostream>
#include<unordered_map>
#include<set>
#include<utility>
#include<list>

using namespace std;


template<typename T>
class Graph{
	typedef pair<T,int> pti;
	int V;
	unordered_map<T,list<pti> > adjList;
	bool bidirectional;
public:
	Graph(int v,bool bid=true)
	{
		V=v;
		bidirectional=bid;
	}
	
	void addedge(T u,T v,int w)
	{
		adjList[u].push_front(make_pair(v,w));
		if(bidirectional)
		{
			adjList[v].push_front(make_pair(u,w));
		}
		adjList[v];
	}
	
	void print()
	{
		for(pair<T,list<pti>> adj:adjList)
		{
			cout<<adj.first<<" : -> ";
			for(pti node:adj.second)
			{
				cout<<"("<<node.first<<", "<<node.second<<")  -> ";
			}
			cout<<endl;
			
			
		}
	}
	
	void bellmanFordSortestD(T src)
	{
		unordered_map<T,int> dis;
		unordered_map<T,T> parent;
		
		for(pair<T,list<pti> > v:adjList)
		{
			dis[v.first] = INT_MAX; 
		}
		dis[src]=0;
		parent[src]=src;
		
		for(int i=0;i<V;i++)
		{
			for(pair<T,list<pti>> p:adjList)
			{
				T u=p.first;
				
				for(pti c:p.second)
				{
					T v= c.first;
					int d = c.second;
					if(dis[u]!=INT_MAX && dis[u]+d < dis[v])
					{
						dis[v]=dis[u]+d;
						parent[v]=u;
					}
					
				}
			}
			
		}
		for(pair<T,list<pti>> p:adjList)
		{
			T u=p.first;
			
			for(pti c:p.second)
			{
				T v= c.first;
				int d = c.second;
				if(dis[u]!=INT_MAX && dis[u]+d < dis[v])
				{
					cout<<"Graph contains negative weight cycle "<<endl;
					return ;
				}
		
			}
		}
		cout<<"Distance : "<<endl;
		for(pti d:dis)
		{
			T c =d.first;
			cout<<d.first<<"  "<<d.second<<endl;
			/*cout<<"path : <-"<<c<<" <-";
			
			while(parent[c] != src)
			{
				cout<<parent[d.first]<<"<- ";
				c=parent[c];
			}
			cout<<parent[c]<<endl;*/
		}
		
		
	}
};
int main()
{
	Graph<int> g(4,false);

	g.addedge(1,2,1);
	g.addedge(1,4,7);
	g.addedge(4,3,-1);
	g.addedge(2,3,1);
	g.addedge(3,1,2) ;
	//g.addedge(2,6);
	//g.addedge(3,7);

	g.print();
	cout<<endl;
	g.bellmanFordSortestD(1);
	return 0;
}
