#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll maxi=0;
struct SegmentTree{
  vector<ll> ST,STsum;
  int n;
  SegmentTree(vector<int> &A){
    n=A.size();
    ST.resize(4*n);
    STsum.resize(4*n);
    build(1,0,n-1,A);
  }
  void build(int nod, int l, int r, vector<int>& A){
    if(l==r){
      ST[nod]=A[r];
      STsum[nod]=0;
      maxi=max(maxi,STsum[nod]);
      return;
    }
    build(2*nod,l,(l+r)/2, A);
    build(2*nod+1,(l+r)/2+1,r, A);
    ST[nod]=max(ST[2*nod+1],ST[2*nod]);
    STsum[nod]=(STsum[nod*2+1]+ST[nod*2+1])+(STsum[nod*2]+ST[nod*2])-ST[nod];
    maxi=max(maxi,STsum[nod]);
  }
  int query(int i, int j){
    return queryy(1,0,n-1, i, j);
  }
  int queryy(int nod, int l, int r, int i, int j){
    //caso 1
    if(i<=l && r<=j){ 
      return ST[nod];
    }
    //caso 2
    if(j<l || r<i){
      return 0;
    }
    //caso 3
    return max(queryy(2*nod,l,(l+r)/2,i,j),queryy(2*nod+1,(l+r)/2+1,r,i,j));
  }
  void calc(int nodel, int ll, int rr, int noder, int lr, int rr){
    while(ll!=rr){
    }

  }

};

int main(){
  ios_base::sync_with_stdio(false);
  int n;
  cin>>n;
  vector<int> vi(n);
  vector<int> acc(n);
  int ind=0;
  for(int i=0;i<n;i++){
    cin>>vi[i];
    ind+=vi[i];
    acc[i]+=ind;
  }
  SegmentTree Tree(vi);
  for(int i=0;i<n;i++){
    for(int j=i;j<n;j++){

    }
  }
  cout<<maxi<<endl;
  return 0;
}
