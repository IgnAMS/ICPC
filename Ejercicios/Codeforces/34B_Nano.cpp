#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,m;
  cin>>n>>m;
  int arr[n];
  vector<int> asd;
  for(int i=0;i<n;i++){
    cin>>arr[i];
    asd.push_back(arr[i]);
  }
  sort(asd.begin(),asd.end());
  //cout<<asd[0]<<" "<<asd[1]<<endl;
  int cont=0;
  for(int i=0;i<m;i++){
    if(asd[i]>0) break;
    cont-=asd[i];
  }
  cout<<cont<<endl;


  return 0;
}
