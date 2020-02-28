#include<iostream>
#include<list>
#include<vector>
#include<queue>

using namespace std;

class Graph{

private:
	vector<list<int> > adjList;
	int V;
	bool bi;


	

public:
	Graph(int v,bool b=true)
	{
		V=v;
		bi = b;
		adjList = vector<list<int> >(V);
	}

	void edge(int u,int v)
	{
		if(bi){
			adjList[v].push_front(u);
		}
		adjList[u].push_front(v);
	}


	bool isBipartite(int s)
	{
		int colors[V];
		for(int i=0;i<V;i++)
		{
			colors[i]=-1;
		}


		queue<int> q;
		q.push(s);
		colors[s]=0;

		while(!q.empty())
		{
			int u = q.front();
			q.pop();

			for(int v:adjList[u])
			{
				if(colors[v]==-1)
				{
					colors[v]=1- colors[u];
					q.push(v);
				}
				//cout<<"u = "<<u<<" "<<colors[u]<<" v = "<<v<<" "<<colors[v]<<endl;
				else if(colors[v]==colors[u])
					return false;
			}
		}
		return true;

	}

	
};


int main()
{

	Graph g(8);

	g.edge(1,5);
	g.edge(1,6);
	g.edge(2,5);
	g.edge(2,6);
	g.edge(2,7);
	g.edge(3,5);
	g.edge(3,6);
	g.edge(3,7);
	g.edge(4,5);
	g.edge(4,6);
	g.edge(4,7);
	//g.edge(2,4);

	if(g.isBipartite(1))
	{
		printf("It is bipartite Graph\n");
	}
	else
	{
		printf("It is not bipartite Graph\n");
	}
	
	return 0;
}