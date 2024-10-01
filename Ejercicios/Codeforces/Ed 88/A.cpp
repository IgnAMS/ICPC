#include<bits/stdc++.h>
using namespace std;
int main(){
  int t;
  int n,m,k;
  cin>>t;
  while(t--){
    cin>>n>>m>>k;
    int njokers1=min(m,n/k);
    m-=njokers1;
    n-=n/k;
    int njokers2= m/(k-1);
    if(m%(k-1)!=0) njokers2++;
    cout<<njokers1-njokers2<<endl;
  }


  return 0;
}
