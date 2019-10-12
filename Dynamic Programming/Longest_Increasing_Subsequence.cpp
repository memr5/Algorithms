#include<bits/stdc++.h>
using namespace std;

	int lis(int array[],int n){
    int dp[n],lis_value = -1;
    for(int i=0;i<n;i++){
        dp[i] = 1;
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(array[i] > array[j] and dp[i] < dp[j]+1){
                dp[i] = dp[j] + 1;
            }
        }
    }
    for(int i=0;i<n;i++){
        if(lis_value < dp[i]){
            lis_value = dp[i];
        }
    }
    return lis_value;
}
int main()
 {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
	int t;
	cin>>t;
	while(t--){
	int n,t,y,r;
	cin>>n;
	int array[n];
	for(int i=0;i<n;i++)  cin>>array[i];
	y=lis(array,n);
	cout<<y<<"\n";
	}
}
