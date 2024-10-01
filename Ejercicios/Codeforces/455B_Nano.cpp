#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//vector<ll> nums(100002,0);
//vector<ll> DP(100002,-1);
ll nums[100001];
ll DP[100001];

ll f(ll pos){
  //casos borde
  //se sale del arreglo
  //cout<<pos<<endl;
  if(pos>=100000){
    return 0;
  }
  if((pos+1)==100000){
    //cout<<"deberia entrar aca...\n";
    return (pos+1)*nums[pos];
  }
  //si ya se precomputo antes, entonces simplemente lo extrae
  if(DP[pos] != -1){
    return DP[pos];
  }
  //cout<<"divide and conquer\n"<<pos<<endl;
  //si no se ha calculado evaluamos si es mejor tomar la posicion actual y pasar a dos siguientes
  //o si es mejor tomar el proximo
  return DP[pos]=max(f(pos+1) , f(pos+2) + nums[pos]*(pos+1));
}



int main(){
  ios::sync_with_stdio(0);
  int n,temp;
  memset(DP,-1,sizeof(DP));
  memset(nums,0,sizeof(nums));
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>temp;
    nums[temp-1]+=1;
    //cout<<"mori aca?\n";
  }
  cout<<f(0)<<endl;
  cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";


  return 0;
}
