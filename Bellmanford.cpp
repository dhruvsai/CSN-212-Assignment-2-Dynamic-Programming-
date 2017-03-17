//Author Dhruv Pachauri, 13117022
 
#include <bits/stdc++.h>
using namespace std;
 
 
struct EDGE{
	int src,  dest,  wt;
};
 
//Storing edges
vector<EDGE> G;
 
void bellmanFord(int V, int root)
{
    int dist[V];
 
 
    for (int i = 0; i < V; i++){
    	dist[i]   = INT_MAX;
    }
    dist[root] = 0;
 
 
    for (int i = 1; i <V; i++){
        for (auto e: G){
            int u = e.src;
            int v = e.dest;
            int wt = e.wt;
            if (dist[u] != INT_MAX && dist[u] + wt < dist[v])
                dist[v] = dist[u] + wt;
        }
    }
 
    for (auto e: G){
        int u = e.src;
        int v = e.dest;
        int wt = e.wt;
        if (dist[u] != INT_MAX && dist[u] + wt < dist[v])
            cout<<"Graph contains negative weight cycle"<<endl;
 
    }
 
 
 
    return;
}
 
 
 
// Driver program to test above functions
int main()
{
	int V; //No. of vetices
	int E; //No. of edges
 
	cin>>V>>E;
 
    for(int i=0; i<E; i++){
    	int u, v, w;
    	cin>>u>>v>>w;
    	G.push_back({u,v,w});
    }
 
    bellmanFord(V, 0);
 
    return 0;
}
