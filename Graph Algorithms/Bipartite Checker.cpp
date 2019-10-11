#include <iostream>
#include <cstring>
#include <vector>
#include<stdio.h>
using namespace std;
bool bi;

void Bipartite(int start, int paint, int * vcolor, vector<int> * adj){
     if(vcolor[start] == -1){
        vcolor[start]=paint;
        for(int i=0;i<adj[start].size();i++){
            if(paint==1)Bipartite(adj[start][i],2,vcolor,adj);
            else Bipartite(adj[start][i],1,vcolor,adj);
            }
    }else{
           if((paint != vcolor[start]))bi=false;
    }
 }
int main(){
    int number_of_vertexes,edges,s,d;
    //  Building the graph
    number_of_vertexes=6;
    edges=6;
    vector <int> adj[number_of_vertexes];
    int color[number_of_vertexes];
    memset(color,-1,sizeof color);

    adj[0].push_back(1);
    adj[1].push_back(0);

    adj[1].push_back(2);
    adj[2].push_back(1);

    adj[3].push_back(4);
    adj[4].push_back(3);

    adj[4].push_back(5);
    adj[5].push_back(4);

    adj[5].push_back(3);
    adj[3].push_back(5);

    bi=true;

    for(int i=0;i<number_of_vertexes;i++){
        if(color[i]==-1)Bipartite(i,1,color,adj);
    }
    if(bi)printf("BIPARTITE.\n");
    else printf("NOT BIPARTITE.\n");
    return 0;
}
