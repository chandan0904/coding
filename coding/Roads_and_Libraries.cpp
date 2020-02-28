#include <bits/stdc++.h>

using namespace std;
int dfs(int s,vector<vector<int> > &cities,vector<bool> &visited,int n )
{
    visited[s]=true;
    vector<int>::iterator itr;
    for(itr = cities[s].begin();itr!=cities[s].end();itr++)
    {
        if(!visited[*itr])
        {
            
             n = dfs(*itr,cities,visited,n+1);
        }
    }
    //cout<<"\nN is "<<n<<endl;
    return n;
}

long roadsAndLibraries(int n, int c_lib, int c_road, vector<vector<int> > cities) {

    vector<bool> visited(n+1,0);
    long cost =0;
    int n_comp;
    for(int i=1;i<=n;i++)
    {
        if(!visited[i])
        {
            
            n_comp = dfs(i,cities,visited,1);
            if(c_lib<=c_road)
            {
                cost += n_comp*c_lib;
            }
            else 
            {
                cost +=( (n_comp-1)*c_road + c_lib );
            }
        
        }
        
    }
    //cout<<"\ncost is "<<cost<<endl;
    return cost;
}

int main()
{
    int n,m,c_lib,c_road;
    int u,v;
    
    
        cin>>n>>m;
        cin>>c_lib>>c_road;
        
        vector<vector<int>> cities(n+1);
        
        for (int i = 0; i < m; i++) {
            //cout<<"\nhhh  "<<1<<" u "<<u<<" v "<<v<<endl;
            cin>>u;
            cin>>v;
            cities[u].push_back(v);
            cities[v].push_back(u);
        }
       
        long result = roadsAndLibraries(n, c_lib, c_road, cities);
        cout<<"cost : " <<result << "\n";
    



    return 0 ;
}
