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
		Graph(int v,bool bid=true)
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

	bool isCyclicBfs(T s)
	{
		map<T,bool> visited;
		map<T,T> parent;
		queue<T> q;

		//
		/*//for(int i=0; i<100000;i++)
		for(pair<T,list<T>> i:adjList)
		{
			cout<<parent[i]<<" ";
		}
		cout<<endl;*/
		q.push(s);
		parent[s] = s;

		visited[s] = true;


		while(!q.empty())
		{
			T node = q.front();
			q.pop();

			for(T neighbour:adjList[node])
			{
				//cout<<"node "<<node<<" parent[node]  "<<parent[node]<<" neighbour "<<neighbour<<endl;;
				if(visited[neighbour] && parent[node]!= neighbour)
				{
					return true;
				}
				else if(!visited[neighbour])
				{
					visited[neighbour]=true;
					parent[neighbour]= node;
					q.push(neighbour);
				}
			}
			//cout<<endl;
		}
		return false;
		//cout<<q.front();
	}

	bool dfsHelper(T s,map<T,bool> &visited,map<T,bool> &instack)
    {

        visited[s]=true;
		instack[s]=true;
		
        for(T neighbour:adjList[s])
        {
            if(visited[neighbour] && instack[neighbour] )
            {
                return true;

            }
            if(!visited[neighbour])
            {
                if(dfsHelper(neighbour,instack,visited))
                {
                       return true;
                }
                instack[s]=false;

            }

        }
        return false;
    }
	bool isCyclicDfs(T s)
	{
	    map<T,bool> visited;
		map<T,bool> instack;
		/*visited[s]=true;
		instack[s]=true;
		for(T neighbour:adjList[s])
        {
            if(!visited[s]){
                return dfsHelper(neighbour,instack,visited);

            }

        }*/
		return dfsHelper(s,instack,visited);


	}


};



int main()
{
	Graph<int> g(8,false);

	g.addedge(2,0);
	g.addedge(0,1);
	g.addedge(1,3);
	g.addedge(1,4);
	g.addedge(1,2) ;
	g.addedge(2,6);
	g.addedge(3,7);

	g.print();
	cout<<endl;
	if(g.isCyclicDfs(0))
	{
		cout<<"yes"<<endl;
	}
	else{
		cout<<"not"<<endl;
	}
	return 0;
}
