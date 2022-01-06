#include<bits/stdc++.h>
using namespace std;
int main(){
  int a,b;
  while(cin>>a>>b){
    //if(a==0 && b==0) break;
    int low=min(a,b);
    int top=max(a,b);
    int cont=0;
    int maxi=0;
    for(int i=low;i<=top;i++){
      cont=1;
      int aux=i;
      while(aux!=1){
        cont++;
        if(aux%2==1) aux= aux*3+1;
        else aux/=2;
      }
      maxi=max(maxi,cont);
    }
    cout<<a<<" "<<b<<" "<<maxi<<endl;
  }




  return 0;
}
