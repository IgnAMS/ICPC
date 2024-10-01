#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  vector<unsigned long long> xd;
  int h;
  unsigned long long sum=0;
  for(int i=0;i<n;i++){
    cin>>h;
    xd.push_back(h);
  }

  sort(xd.begin(),xd.end());
  long long ind=2;
  if(xd.size()==1) ind=1;
  for(int i=0;i<(int)xd.size();++i){
    long long aux=ind*xd[i];
    sum+=aux;

    //cout<<aux<<endl;
    ind++;
    if(i==xd.size()-2) ind--;
  }
  cout<<sum<<endl;

  return 0;
}
