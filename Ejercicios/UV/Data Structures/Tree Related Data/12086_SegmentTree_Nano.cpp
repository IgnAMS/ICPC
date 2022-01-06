#include<bits/stdc++.h>
using namespace std;

struct SegmentTree{
  vector<int> ST;
  int n;
  SegmentTree(vector<int> &A){
    n=A.size();
    ST.resize(4*n);
    build(1,0,n-1,A);
    //for(int i=0;i<ST.size();i++) cout<<ST[i]<<" ";
    //cout<<endl;
  }
  void build(int nod, int l, int r, vector<int>& A){
    if(l==r){
      ST[nod]=A[r];
      return;
    }
    build(2*nod,l,(l+r)/2, A);
    build(2*nod+1,(l+r)/2+1,r, A);
    ST[nod]=ST[2*nod+1]+ST[2*nod];
  }

  int size(){
    return n*2;
  }
  int query(int i, int j){
    return queryy(1,0,n-1, i, j);
  }
  int queryy(int nod, int l, int r, int i, int j){
    //caso 1
    if(i<=l && r<=j){ //
      return ST[nod];
      //printf("entre en el caso 1, i: %d, j: %d\n",i,j);
    }
    //caso 2
    if(j<l || r<i){
      return 0;
    }
    //caso 3
    return queryy(2*nod,l,(l+r)/2,i,j)+queryy(2*nod+1,(l+r)/2+1,r,i,j);
  }
  void mod(int nod, int x){
    nod--;

    int low=0;
    int top=n-1;
    int mid=(low+top)/2;
    int pos=1;
    while(low!=top){
      //printf("pos vale: %d y mid vale: %d\n",pos,mid);
      mid=(low+top)/2;
      if(nod<=mid){
        top=mid;
        //cout<<"pos vale: "<<pos<<endl;
        pos*=2;
      }
      else{
        pos= pos*2+1;
        low=mid+1;
      }
    }
    //printf("la posicion del elemento %d es el elemento  %d en el grafo\n",nod+1,pos);
    ST[pos]=x;
    for(int i=pos/2;i>=1;i/=2){
      ST[i]=ST[2*i]+ST[2*i+1];
    }
    //for(int i=0;i<ST.size();i++) cout<<ST[i]<<" ";
    //cout<<endl;
  }

};

int main(){
  ios_base::sync_with_stdio(false);
  int n;
  vector<vector<int> > ans;
  bool primer=true;
  int cas=0;
  while(cin>>n){
    if(n==0) break;

    if(primer){
      primer=false;
    }
    else{
      cout<<endl;
    }
    cas++;
    cout<<"Case "<<cas<<":"<<endl;
    //printf("Case %d:\n",cas);

    vector<int> caso;
    vector<int> A(n);
    for(int i=0;i<n;i++) cin>>A[i];
    SegmentTree ST(A);

    string op;
    int x,y;
    while(cin>>op){
      if(op=="END") break;
      cin>>x>>y;
      if(op=="M"){
        x--;
        y--;
        //cout<<"entro aca chaval\n";
        //printf("query: %d\n",ST.query(x,y));
        //caso.push_back(ST.query(x,y));
        cout<<ST.query(x,y)<<endl;
      }
      else if(op=="S"){
        ST.mod(x,y);
      }
    }
    //ans.push_back(caso);
  }
  /*
  for(int i=0;i<ans.size();i++){
    cout<<"Case "<<i+1<<":\n";
    for(int j=0;j<ans[i].size();j++){
      cout<<ans[i][j]<<endl;
    }
    if(i<ans.size()-1) cout<<endl;
  }
  */
  return 0;
}
