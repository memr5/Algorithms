// C++ program for activity selection problem. 
// Prints a maximum set of activities that can be done by a single 
// person, one at a time. 
// n --> Total number of activities 
// s[] --> An array that contains start time of all activities 
// f[] --> An array that contains finish time of all activities 

#include<iostream>
#include<algorithm>
using namespace std;

bool mycompare(pair<int, int> p1, pair<int, int> p2)
{
	return p1.second<p2.second;
}

int main()
{
	int n, start, finish;
	cin>>n;

	pair<int, int> act[n];

	for(int i = 0 ; i < n ; i++)
	{
		cin>>start>>finish;

		act[i].first = start;
		act[i].second = finish;
	}

	sort(act, act+n, mycompare);

	int i = 0;

	cout<<i;

	for(int j = 0 ; j < n ; j++)
	{
		if(act[j].first>=act[i].second)
		{
			cout<<j;
			i = j;
		}
	}

}
