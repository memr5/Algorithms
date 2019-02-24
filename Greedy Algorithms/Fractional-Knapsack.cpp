#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
int main() {

  std::cout << "Enter number of objects available = ";
  int n;
  std::cin>>n;

  std::cout << "Enter Value and Weight of all objects:" << '\n';
  std::vector<std::pair<double,double> > v(n);
  for(int i=0;i<n;i++){
    std::cout<<"Value["<<i<<"] : ";
    std::cin>>v[i].first;
    std::cout<<"Weight["<<i<<"] : ";
    std::cin>>v[i].second;
  }

  std::cout<<"Enter Capacity of Bag : ";
  double W;
  std::cin>>W;

  std::vector<std::pair<double,int> > valbwe(n); //value by weight
  for(int i=0;i<n;i++){
    valbwe[i].first = v[i].first/v[i].second;
    valbwe[i].second = i;
  }
  sort(valbwe.rbegin(),valbwe.rend());

  std::vector<bool> Selected(n,false);
  double profit=0;
  for(int i=0;i<n;i++){
    if(W>0){
      if(W>v[valbwe[i].second].second){
        profit+=v[valbwe[i].second].first;
        W-=v[valbwe[i].second].second;
      }
      else{
        profit+=(v[valbwe[i].second].first * (W))/v[valbwe[i].second].second;
        W = 0;
      }
      Selected[valbwe[i].second] = true;
    }
    else{
      break;
    }
  }

  std::cout << "Selected Objects :" << '\n';
  for(int i=0;i<n;i++){
    if(Selected[i]){
      std::cout << i <<" ";
    }
  }

  std::cout << "\nProfit = " << profit << '\n';

  return 0;
}
