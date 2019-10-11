#include <bits/stdc++.h> //Segment Tree / Query O(log) / Build O(N)
using namespace std;    //Leonardo Su
                       // Github : @Leonardosu
                      // Hacktoberfest

const int INF = 1e8 + 7;
const int MAXN = 50100;

int arvore[4*MAXN],seq[MAXN]; //Segtree of Sum
int N;

int build(int idx, int A, int B)
{
    if (A == B)
        arvore[idx] = seq[A];

    else
    {
        int me = build(idx*2, A, (A+B)/2);
        int md = build(idx*2+1,(A+B)/2+1,B);
        arvore[idx] = me + md;
    }
    return arvore[idx];
}

int query(int idx, int A, int B, int x, int y)
{
    if (B < x || y < A) return 0;
    if (x <= A && B <= y)
        return arvore[idx];

    int me = query(idx*2, A,(A+B)/2, x, y);
    int md = query(idx*2+1,(A+B)/2+1,B,x,y);

    return me + md;
}

int update(int idx, int A, int B, int p, int v)
{
    if (p < A || B < p)
        return arvore[idx];
    if (A == B)
        return (seq[A] = arvore[idx] = v);

    int me = update(idx*2,A,(A+B)/2,p,v);
    int md = update(idx*2+1,(A+B)/2+1,B,p,v);

    return (arvore[idx] = me + md);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);

    cin>>N;
    
    for (int i = 1; i <= N; ++i) // input
        cin>>seq[i];

    build(1,1,N);

    int Q;
    cin>>Q;
    while (Q--) // Queries
    {
        int c, x,y;
        cin>>c>>x>>y;
        if (c == 0) update(1,1,N,x,y);
        else printf("%d\n", query(1,1,N,x,y)); // return sum of interval [x,y]
    }

    return 0;
}
