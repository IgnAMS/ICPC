#include<bits/stdc++.h>
using namespace std;

int cont=0;
vector<int> visits;
vector<long long> conts;

int jump(int n){
  if(n<0) return 0;
  if(visits[n] == -1) return 0;
  if(visits[n] == 1) return conts[n];
  conts[n]=(jump(n-1)+jump(n-2))%1000000007;
  //cout<<n<<" "<<conts[n]<<endl;
  visits[n]=1;
  return conts[n];
}


int main(){
  int n,m;
  cin>>n>>m;
  int h;
  visits.assign(n+1,0);
  conts.assign(n+1,0);
  visits[0]=1;
  visits[1]=1;
  conts[0]=1;
  conts[1]=1;
  for(int i=0;i<m;i++){
    cin>>h;
    visits[h]=-1;
    conts[n]=0;
  }
  cout<<jump(n)%1000000007<<endl;

  return 0;
}
