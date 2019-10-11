#include <bits/stdc++.h> //Fenwick (Binary Indexed) Trees 
using namespace std;    //Leonardo Su
					   // Github : @Leonardosu
                      // Hacktoberfest

typedef long long int ll;
const int N = 100002;

ll BIT[N];
int n,x;
int t;

void update(int id,int value)
{
    for(int i = id; i < 100002; i += (i & -i))
        BIT[i] += value;    
}

ll query(int id)
{
    ll sum = 0;
    for(int i = id; i > 0; i -= (i & -i))
        sum += BIT[i];

    return sum;
}

int main()
{
    memset(BIT, 0, sizeof(BIT));

    cin>>n;

    for(int i=1;i<=n;++i)
    {
    	cin>>x;
    	update(i,x);
    }
    
    return 0;
}
