#include<bits/stdc++.h>
using namespace std;
int main(){
  int t,n;
  cin>>t;
  while(t--){
    cin>>n;
    vector<int> num(10,0);
    for(int i=1;i<=n;i++){
      int aux=i;
      while(aux>0){
        int cont=aux%10;
        num[cont]++;
        aux/=10;
      }
    }
    for(int i=0;i<10;i++){
      cout<<num[i];
      if(i<9) cout<<" ";
    }
    cout<<endl;

  }



  return 0;
}
