#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s,n;
	cin>>s>>n;
	int q=101;
	int d=256;
	int p=0,t=0,count=0;
	int h=1;
	int z=s.length()-n.length();
	cout<<z<<"\n";
	for(int i=0;i<n.length()-1;i++)
	{
		h=(h*d)%q;
	}
	for(int i=0;i<n.length();i++)
	{
		p=(d*p+s[i])%q;
		t=(d*t+n[i])%q;
		cout<<p<<"  "<<t<<"\n";
	}
	for(int i=0;i<=z;i++)
	{
		if(p==t)
		{
			cout<<"    "<<t<<s[i]<<"\n";
			count=0;
			int j;
			for(j=0;j<n.length();j++)
			{
				if(s[i+j]!=n[j])
				{
				break;
				
				}
				cout<<count<<"\n";
			}
			if(j==n.length())
			cout<<"Pattern found at index "<<i<<"\n";
			
		}
		if(i<z)
		{
			t=(d*(t-s[i]*h)+s[i+n.length()])%q;
			if(t<0)
			{
				t=t+q;
			}
			cout<<"  "<<p<<"  "<<t<<"\n";
		}
	}
}
