#include<iostream>
#include<bits/stdc++.h>
/*
#include<set>
#include<list>
#include<unordered_map>
#include<vector>
#include<utility>
*/

using namespace std;
class Graph{
private:
	list<pair<int,int>> *adjlist;
	int V;
	bool bid;

public:
	Graph(int v,bool b=true)
	{
		V = v;
		adjlist = new list<pair<int,int> >[V];
		bid = b;
	}

	void edge(int u,int v,int w)
	{
		if(bid)
		{
			adjlist[v].push_front(make_pair(u,w));
		}
		adjlist[u].push_front(make_pair(v,w));
	}

	void prints(vector<int> &parent,vector<int> &weight)
	{
		int w=0;
		cout<<"Minimum spaning Tree : "<<endl;
		for(int i=0;i<V;i++)
		{
			if(parent[i]!=-1)
			{
				cout<<"u = "<<parent[i]<<" v = "<<i<<" w = "<<weight[i]<<endl;
				w += weight[i];
			}
		}
		cout<<"Totale Cost is : "<<w<<endl;


	}
	void prims(int src)
	{
		set<pair<int,int> > s;
		vector<int> parent(V);
		vector<int> weight(V);
		vector<bool> visited(V);
		for(int i=0;i<V;i++)
		{
			weight[i] = INT_MAX;
			parent[i] = -1;
			visited[i] =false;
		}

		weight[src]=0;
		s.insert(make_pair(0,src));

		while(!s.empty())
		{
			pair<int,int > node = *s.begin();
			s.erase(s.begin());

			//int w = node.first;
			int u = node.second;
			visited[u]= true;
			for(pair<int,int> child: adjlist[u])
			{
				int v = child.first;
				int w = child.second;
				if(weight[v]> w && !visited[v] )
				{
					set<pair<int ,int> >::iterator f = s.find(make_pair(weight[v],v));
					if(f !=s.end())
					{
						s.erase(f);
					}

					weight[v] = w;
					parent[v] = u;
					//cout<<"u = "<<parent[v]<<" v = "<<v<<" w = "<<weight[v]<<endl;
					s.insert(make_pair(w,v));
				}
			}
		}

		prints(parent,weight);
		
	}
};


int main()
{
	Graph g(9);

	
	g.edge(1,3,8);
	g.edge(0,2,8);
	g.edge(0,1,4);
	g.edge(1,2,11);
	
	g.edge(2,4,7);
	g.edge(2,5,1);
	g.edge(3,4,2);
	g.edge(3,6,7);
	g.edge(3,7,4);
	g.edge(4,5,6);
	g.edge(5,7,2);
	g.edge(6,7,14);
	g.edge(6,8,9);
	g.edge(7,8,10);
	g.prims(0);

	return 0;
}