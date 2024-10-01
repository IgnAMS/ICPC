#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;

vector<vll> sum(500,vll(500,0));
vector<vll> marc(500,vll(500,0));

struct SegmentTree{
  vector<vll> ST,L;
  int n,m;

  SegmentTree(vector<vll> &A){
    n=A.size();
    m=A[0].size();
    ST.resize(4*m*n);
    L.assign(2*n,vll(2*m));
    build(1,1,0,0,n-1,m-1,A);
  }
  void build(int nodei, int nodej, int lowi, int lowj, int topi, int topj, vector<vll> &A){
    //estamos en la misma fila y misma columna
    if(lowi==topi && lowj==topj){
      ST[nodei][nodej]=A[lowi][lowj];
      return;
    }
    //en caso de que este en la misma fila, pero no en la misma columna
    if(lowi==topi){
      buildcol(nodei, nodej,lowi,lowj,topj,A);
      ST[nodei][nodej]=ST[nodei][2*nodej]+ST[nodei][2*nodej+1];
    }
    //en caso de que estemos en dif filas
    build(nodei*2, nodej, lowi,(lowi+topi)/2,lowj,topj,A);
    build(nodei*2+1, nodej, (lowi+topi)/2+1,topi,lowj,topj,A);
    ST[nodei][nodej]=ST[nodei*2][nodej]+ST[nodei*2+1][nodej];
    return;
  }
  void buildcol(int nodei, int nodej, int i, int lowj, int topj, vector<vll> &A){
    //estoy en una hoja
    if(lowj==topj){
      ST[nodei][nodej]=A[i][lowj];
      return;
    }
    //necesito dividirme
    buildcol(nodei, nodej*2, i, lowj, (lowj+topj)/2,A);
    buildcol(nodei, nodej*2+1, i, (lowj+topj)/2+1, topj,A);
    ST[nodei][nodej]=ST[nodei][nodej*2]+ST[nodei][nodej*2+1];
    return;
  }
  void query(int lowi, int topi, int lowj, int topj){
    queryy()
  }
  void queryy(int nodei, int nodej, int lowi, int topi, int lowj, int topj){

  }

};

void change(int i,int j, int x){
  marc[i][j]+=x;
}


int main(){
  int n;
  cin>>n;
  vector<vll> mat(n,vll (n,0));
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cin>>mat[i][j];
    }
  }
  SegmentTree Tree(mat);
  int m, v;
  int x1,y1,x2,y2;
  char c;
  cin>>c;
  if(ch=='q'){
    cin>>x1>>y1>>x2>>y2;

  }
  else{
    cin>>x1>>y1>>v;
  }


  return 0;
}
