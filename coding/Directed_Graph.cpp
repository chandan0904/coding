#include<iostream>
#include<list>
#include<map>

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
	//g.edge(3,2);
	
	g.print();
	
	return 0;
}
