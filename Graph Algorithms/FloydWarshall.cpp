#include <bits/stdc++.h> //Floyd-Warshall O(N^3)
using namespace std;	//Leonardo Su
 		       // Github : @Leonardosu
		      // Hacktoberfest

const int N = 400;   // Number of vertex
const int INF = 1e9 + 7;

int dist[N][N];
int n,m,q;
int a,b,c;

void start(int n)
{
	for(int i=0;i<=n;++i)
		for(int j=0;j<=n;++j)
			if(i != j)
				dist[i][j] = INF;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);


	cin>>n>>m; //number of vertex and edges
	
	start(n);

	for(int i=1;i<=m;++i) // undirected graph
	{
		cin>>a>>b>>c;
		dist[a][b] = c;
		dist[b][a] = c;
	}

	//Floyd-Warshall Algorithm	
	for(int k=1;k<=n;++k) 
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

	cin>>q; //number of queries

	for(int i=1;i<=q;++i)
	{
		cin>>a>>b;
		if(dist[a][b] != INF)
			cout<<dist[a][b]<<"\n";
		else
			cout<<"-1\n";
	}
}
