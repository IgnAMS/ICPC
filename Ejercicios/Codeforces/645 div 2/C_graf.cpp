#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int t;
  cin>>t;
  while(t--){
    int x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    ll ind=0;
    ll sum=0;
    ll suma2=0;
    if(x2-x1 >0 && y2-y1>0){
      for(int i=0;i<x2-x1;i++){
       ind+=2;
       sum+=ind;
      }
      for(int j=0;j<y2-y1;j++){
        ind+=1;
        sum+=ind;
      }
      ind=0;
      for(int j=0;j<y2-y1;j++){
        ind+=1;
        suma2+=ind;
      }
      for(int i=0;i<x2-x1;i++){
        ind+=2;
        suma2+=ind;
      }

    }
    //cout<<suma2<<" "<<sum<<endl;
    cout<<sum-suma2+1<<endl;
  }

  return 0;
}
