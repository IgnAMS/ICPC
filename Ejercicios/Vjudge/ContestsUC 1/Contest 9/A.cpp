#include<bits/stdc++.h>
using namespace std;
void printvec(vector<int> b,string a){
  cout<<a;
  for(int i=0;i<b.size();i++){
    cout<<b[i]<<" ";
  }
  cout<<endl;
}

struct vectoresxd{
  vector<vector<int> > ST;
  int n;
  vector<int> A;
  vectoresxd(int n2){
    n=n2;
    for(int i=1;i<=n;i++) A.push_back(i),
    ST.assign(4*n,vector<int>() );
    build(1,0,n-1,A);
  }
  void build(int node, int l, int r, vector<int> &A){
    vector<int> aux;
    if(l==r){
      ST[node].push_back(A[l]);
      //printf("entre a la hoja %d la cual vale: %d\n",l,A[l]);
      return;
    }
    //printf("l vale: %d, y r vale: %d\n",l,r);
    build(node*2,l,(l+r)/2,A);
    build(node*2+1,(l+r)/2+1,r,A);
    for(int i=0;i<ST[node*2].size();i++) ST[node].push_back(ST[node*2][i]);
    for(int i=0;i<ST[node*2+1].size();i++) ST[node].push_back(ST[node*2+1][i]);
    //printvec(ST[node],"vamo vamo\n");
    //ST[node].push_back(aux);

    return;
  }
  void printST(string a){
    cout<<a;
    for(int i=0;i<ST.size();i++){
      for(int j=0;j<ST[i].size();j++){
        cout<<ST[i][j]<<" ";
      }
      cout<<endl;
    }
  }
  void changes(int m){

  }


};


int main(){
  int n,m;
  cin>>n>>m;
  double d=log(n)/log(2);
  int meh;
  if(d-(int)d>0) meh=d+1;


  if(m%2==0 || m>2*n-1 || m<meh*2+1){
    cout<<"entre a este if\n";
  }
  vectoresxd hola(n);
  //hola.printST("Imprimeme esta papa: ");

  return 0;
}
