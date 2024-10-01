#include<bits/stdc++.h>
using namespace std;

int main(){
  int m,n,e,t;
  cin>>m>>n>>e;
  vector< pair <pair<int,int>, pair<int,int> > > mov;
  int a,b,c,d;
  for(int i=0;i<e;i++){
    cin>>a>>b>>c>>d;
    pair<int,int> p1(a,b);
    pair<int,int> p2(c,d);
    mov.push_back(pair< pair<int,int>, pair<int,int> > (p1,p2));
  }
  cin>>t;
  int dado;
  int posi=0, posj=0;
  while(t--){
    cin>>dado;
    if(posi%2==0 && dado+posj<n){
      posj+=dado;
    }
    else if(posi%2==0 && dado+posj>=n){
      a=(dado+posj)/n;
      posi+=a;
      if(a%2==0){
        posj= (posj+dado)%n;
      }
      else{
        posj= n- (posj+dado)%n-a;
      }
    }
    else if(posi%2==1 && posj-dado>=0){
      posj=posj-dado;
    }
    else if(posi%2==1 && posj-dado<0){
      a=(n-posj+dado)/n;
      posi+=a;
      if((a)%2==0){
        posj= n-posj+dado -a*n;
      }
      else{
        posj= (n-posj+dado)%n-a;
      }
    }
    for(int i=0;i<e;i++){
      if(posi==mov[i].first.first && posj==mov[i].first.second){
        posi=mov[i].second.first;
        posj=mov[i].second.second;
      }
    }
    if(posi>n-1){
      break;
    }
    //cout<<posi<<" "<<posj<<endl;
  }
  cout<<posi<<" "<<posj<<endl;




  return 0;
}
