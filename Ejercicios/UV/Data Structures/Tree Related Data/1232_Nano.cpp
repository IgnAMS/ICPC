#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;

#define OJ                            \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

int anterior=-3;
int preanterior=-4;

struct SegmentTree{
  int n=100000;
  vector<int> maxh,minh,L;
  SegmentTree(vector<int> &A){
    n=100000;
    build();
  }

  void build(){
    minh.assign(100000*4,0);
    maxh.assign(100000*4,0);
    L.assign(n*4,0);
    return;
  }

  int query(int i, int j, int h){
    anterior=-3;
    return queryy(1, 0, n-1, i, j, h);
  }
  int queryy(int node, int l, int r, int i, int j, int h){
    //  printf("node: %d, l: %d, r:%d, i: %d, j: %d",node,l,r,i,j);
    if(L[node]!=0){
      maxh[node]=L[node];
      minh[node]=L[node];
      //si no es hoja, pasar la marca
      if(l!=r){
        L[2*node]=L[node];
        L[2*node+1]=L[node];
      }
      L[node]=0;
	}

    if(minh[node]>h){
      anterior=r;
      return 0;
    }
    if(j<l || r<i){
      return 0;
    }
    if(i<=l && r<=j && maxh[node]<=h){
      //printf("node: %d, l: %d, r:%d, i: %d, j: %d\n",node,l,r,i,j);
      int val=r-l;
      if(anterior==l-1) val++;
      if(maxh[node]<=h){
        if(anterior==l-1)
          update(1, 0, n-1, l, r, h);
        else if(l+1<=r)
          update(1, 0, n-1, l+1,r,h);
      }
      anterior=r;
      //cout<<"RETORNO: "<<val<<endl;
      return val;
    }
    return (queryy(node*2,l,(l+r)/2,i,j,h)+queryy(node*2+1,(l+r)/2+1,r,i,j,h));
  }
  void update(int node, int l, int r, int i, int j, int x) {
  //printf("node: %d, l: %d, r: %d, i: %d, j: %d",node,l,r,i,j);
  //cout<<endl;
	// Hay que actualizar
    if(L[node] != 0) {
        maxh[node] = L[node];
        minh[node] = L[node];
      // Si no es hoja, pasar la marca
      if(l != r) {
        L[2*node] = L[node];
        L[2*node+1] = L[node];
      }

      L[node] = 0;
    }

    // Caso 1
    if(i <= l && r <= j) {
      maxh[node] = x;
      minh[node] = x;
      //printf("actualizo el minnode de %d %d a %d\n",l,r,minh[node]);
      if(l != r) {
        L[2*node] = x;
        L[2*node+1] = x;
        }
        return;
	  }
	  // Caso 2
	  if(j<l || i>r) return;

	  // Caso 3
    update(2*node, l, (l+r)/2, i, j, x);
	  update(2*node+1, (l+r)/2+1, r, i, j, x);
	  minh[node] = min(minh[2*node], minh[2*node+1]);
    maxh[node] = max(maxh[node*2],maxh[node*2+1]);
    //printf("actualizo el minnode %d %d a %d\n",l,r,minh[node]);
    return;
	}

};


int main(){
  OJ;
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    vector<int> A(n,0);
    SegmentTree ST(A);
    int a=0,b=0,h=0;
    int sol=0;
    int val;
    for(int i=0;i<n;i++){
      cin>>a>>b>>h;
      val=ST.query(a-1,b-1,h);
      sol+=val;
      //cout<<val<<endl;
    }
    cout<<sol<<endl;
  }
  cin>>t;   




  return 0;
}

