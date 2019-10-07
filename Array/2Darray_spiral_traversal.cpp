#include<iostream>
#include<vector>
using namespace std;
int main(){

int m,n;
//enter rows and column for @D matrix
cin>>m>>n;
vector<vector<int>>v(m,vector<int>(n));
vector <int>a;
//dir1


int s1=0;
int s2=0;
int e1=m-1;
int e2=n-1;
int dir=0;
int i=0,j=0;
//give input for your 2d matrix
for(i=0;i<m;i++)
    for(j=0;j<n;j++)
        cin>>v[i][j];

//print your input array

for(i=0;i<m;i++){
          for(j=0;j<n;j++){
              cout<<v[i][j]<<"\t";}
              cout<<endl;}
cout<<endl;
while(s1<=e1 && s2<=e2)
{
  if(dir==0)
  {
    for(i=s2;i<=e2;i++){
            cout<<v[s1][i]<<"\t";
            a.push_back(v[s1][i]);
          }

    s1++;
    dir=1;
  }
  else if(dir==1)
  {

    for(i=s1;i<=e1;i++){
            cout<<v[i][e2]<<"\t";
            a.push_back(v[i][e2]);}

    e2--;
    dir=2;
  }
  else if(dir==2)
  {
    for(i=e2;i>=s2;i--){
            cout<<v[e1][i]<<"\t";
            a.push_back(v[e1][i]);}

    e1--;

    dir=3;
  }
  else
  {
    for(i=e1;i>=s1;i--){
            cout<<v[i][s2]<<"\t";
            a.push_back(v[i][s2]);}

    s2++;
    dir=0;
  }

}
//print traversal
for(i=0;i<a.size();i++)
        cout<<a[i];
}
