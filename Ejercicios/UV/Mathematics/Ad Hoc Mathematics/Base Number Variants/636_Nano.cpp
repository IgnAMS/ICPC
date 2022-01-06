#include<bits/stdc++.h>
using namespace std;
int main(){
  int a;
  while(cin>>a){
    if(a==0) break;

    int base=2;
    int aux=a;
    deque<int> dig;
    int maxdig=0;

    while(aux>0){
      dig.push_front(aux%10);
      maxdig=max(maxdig,aux%10);
      aux/=10;

    }
    int ind=0;
    for(int i=maxdig+1;i<=100;i++){
      unsigned long long asd=0;
      for(int j=0;j<dig.size();j++){
        asd+=dig[j]*pow(i,dig.size()-1-j);
      }
      double raiz=sqrt(asd);
      //cout<<raiz<<endl;
      int rest=raiz;
      if(raiz-rest==0){
        ind=i;
        break;
      }
    }
    cout<<ind<<endl;
  }




  return 0;
}
