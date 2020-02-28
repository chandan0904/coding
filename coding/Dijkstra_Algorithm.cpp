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
	
	void dijkstra(T source)
	{
		set<pair<int,T>> s;
		unordered_map<T,T> parent;
		unordered_map<T,int> distance;
		
		//
		for(pair<T,list<pti> > adj:adjList)
		{
			distance[adj.first]=INT_MAX;
		}
		
		distance[source]=0;
		s.insert(make_pair(0,source));
		parent[source]=source;
		
		
		//pair<int,T> node;
		while(!s.empty())
		{
			//pair<int,T> node = *(s.begin());
			auto p = *(s.begin());
			int nodeDist = p.first;
			T node = p.second;
			s.erase(s.begin());
			
			//for(pti adj:adjList[node.second])
			for(auto childPair:adjList[node])
			{
				if(nodeDist+childPair.second < distance[childPair.first])
				{
					
					
					
					//typename set<pair<int,T> >:: iterator
					auto f = s.find(make_pair(distance[childPair.first],childPair.first));
					 
					if(f!= s.end())
					{
						
						s.erase(f);
					}
					distance[childPair.first]= nodeDist+childPair.second;
					s.insert(make_pair(distance[childPair.first],childPair.first));
					
					parent[childPair.first]=node; 
						
				}
			}
		}
		
		for(auto d:distance)
		{
			cout<<d.first<<" is located at distance of "<<d.second<<endl;
			/*T p = d.first;
			while(parent[p] != source ){
				cout<<parent[p]<<" - ";
				p = parent[p] ;
			}
			cout<<endl;*/
		}
		
	}
	
};
int main()
{
	Graph<int> g(4);

	g.addedge(1,2,1);
	g.addedge(1,4,7);
	g.addedge(1,3,4);
	g.addedge(2,3,1);
	g.addedge(3,4,2) ;
	//g.addedge(2,6);
	//g.addedge(3,7);

	g.print();
	cout<<endl;
	
	g.dijkstra(1);

	return 0;
}
