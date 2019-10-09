#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;
int main(){

int sum,n;
cin>>n>>sum;
vector<int>array(n);
for(int i=0;i<n;i++)
		cin>>array[i];
unordered_set<int>nums;
for(int num : array){
 int potential_match = sum - num;
 if(nums.find(potential_match)!=nums.end())
	
			cout<<"the two numbers are"<<num<<" "<<potential_match<<endl; 
 else
			nums.insert(num);

	
			
 }

}

