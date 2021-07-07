#include<bits/stdc++.h>

using namespace std;


bool matching(string s1,string s2)
{
	if(s1!=s2)
		return false;
	return true;
}

int main()
{
	int t;
	cin>>t;

	while(t--)
	{
		string s1,s2;
		cin>>s1>>s2;

		bool ans = matching(s1,s2);

		cout<<ans<<endl;


	}
	return 0;
}