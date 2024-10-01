#include<bits/stdc++.h>
using namespace std;
int main(){
  int t,n,k;
  cin>>t;
  while(t--){
    cin>>n>>k;
    int asd=0;
    int cont=0;
    int dist=n/k;
    int meh=k/2;
    //printf("meh= %d,  a+1= %d,  a= %d,  k-meh= %d\n",meh,dist+1,dist,k-meh);
    cont=meh*(dist+1)+(k-meh)*dist;
    if(cont>n) cont=n;
    if(n%k==0) cont=n;
    cout<<cont<<endl;

  }



  return 0;
}
