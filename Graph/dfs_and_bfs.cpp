// LANGUAGE: C++
// ENV: gcc
//AUTHOR: Proma Roy
//GITHUB: https://github.com/promaroy


// implementing a undirected graph data structure  using adjacency list and traversals...

#include<bits/stdc++.h>
using namespace std;
vector<int> v[6]; //an array of vectors to store the nodes connected to a node...
int vis[6]={0}; // a hash array to keep track of the nodes which are already visited
queue<int> q;//to implement bfs..
int level[6]={0};
void add_edge(int a,int b)// function to add an edge
{
  v[a].push_back(b);
  v[b].push_back(a);
}
void dfs(int in)//function to run dfs traversal
{
  vis[in]=1;
  cout<<in<<" ";
  for(int i=0;i<v[in].size();i++)
  {
    if(vis[v[in][i]]==0)
    {
      dfs(v[in][i]);
    }
  }
}
void bfs(int in)//function to run a bfs traversal
{
  q.push(in);
  vis[in]=1;
  cout<<in<<" ";
  level[1]=0;
  while(!q.empty())
  {
    int s=q.front();
    cout<<s<<" ";
    q.pop();
    for(int i=0;i<v[s].size();i++)
    {
      if(vis[v[s][i]]==0)
      {
        q.push(v[s][i]);
        vis[v[s][i]]=1;
        level[v[s][i]]=level[s]+1;//level of each node
      }
    }
  }
}
int main()
{
  int n=5; // number of nodes
  add_edge(1,2);
  add_edge(1,3)
  add_edge(2,3);
  add_edge(3,4);
  add_edge(2,5);

  for(int i=1;i<=5;i++)
  {
    if(vis[i]==0)
    {
      dfs(i);// running a dfs traversal from every node..
    }
  }

  cout<<endl;
  bfs(1);//bfs from 1....
  cout<<endl;

}
