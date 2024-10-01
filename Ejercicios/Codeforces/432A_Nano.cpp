#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,k;
  cin>>n>>k;
  vector<int> xd;
  int h;
  int cont=0;
  for(int i=0;i<n;i++){
    cin>>h;
    xd.push_back(h);
    if(5-h>=k) cont++;
  }
  int asd=cont/3;
  cout<<asd<<endl;



  return 0;
}
