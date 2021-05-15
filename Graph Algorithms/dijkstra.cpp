// Dijakstra code in C++ using STL for undirected and weighted graph

#include <bits/stdc++.h>
using namespace std;

#define mode 1000000007

int v,e;   //v represenr number of vertices
           //e represents number of edges

void djakstra(vector<pair<int,int>> adj[])
{
	  set<pair<int,int>> s;
    vector<int> dist(v,mode);     //initialise distances of all vertices to be INT_MAX
    
    //Source vertex is zero
    dist[0]=0;
    s.insert(mp(0,0));

    //While all vertices are not removed from set
    while(!s.empty())
    {
    	pair<int,int> temp = *(s.begin());
    	s.erase(s.begin());

      //Getting vertex with least weight
    	int u = temp.ss;

    	//Updating distances of its adjacent nodes
      for(int i= 0; i < adj[u].size(); i++)
    	{
    		pair<int,int> curr = adj[u][i];
    	    if(dist[curr.ff] > dist[u] + curr.ss)
    	    {
    	    	if(dist[curr.ff] != mode)
    	      	 s.erase(s.find(mp(dist[curr.ff],curr.ff)));
    	      	s.insert(mp(dist[u] + curr.ss, curr.ff));
    	      	dist[curr.ff] = dist[u] + curr.ss;
    	    }
    	}
    }
    //Printing vertices along with their distance from source 
    ffor(i,0,v) cout<<i<<" "<<dist[i]<<endl;
}

int main() 
{ 
   cout<<"Enter number of vertices and edges"<<endl;
   cin>>v>>e;	
   //adjacency list is used to store vertex and their weights
   cout<<"Enter conecting vertices with their weights"<<endl;
   vector<pair<int,int>> adj[v];
   for(int i = 0;i < e; i++)
   {
   	  int a,b,w; 
      cin>>a>>b>>w;
      
      //a represents vertex1
      //b represents vertex2
      //w represnts weight of edge between a and b

   	  adj[a].pb(mp(b,w));
   	  adj[b].pb(mp(a,w));
   }
   djakstra(adj); //Calling dijakstra function 
}



