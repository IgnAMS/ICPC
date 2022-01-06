#include<bits/stdc++.h>
using namespace std;

#define OJ                            \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);


struct SegmentTree{
  int n;
  //vector<int> maxh,minh;
  int maxh[100000*4];
  int minh[100000*4];
  SegmentTree(vector<int> &A){
    n=100000*4;
    build();
  }

  void build(){
    //minh.assign(100000*4-1,0);
    //maxh.assign(100000*4-1,0);
    //cout<<"hice el build\n";
    memset(minh,0,sizeof(minh));
    memset(maxh,0,sizeof(maxh));
    return;
  }

  int query(int i, int j, int h){
    printf("hare una query desde %d hasta %d\n",i,j);
    printf("n vale: %d\n",n-1);
    return queryy(1, 0, 100000*4-1, i, j, h);
  }
  int queryy(int node, int l, int r, int i, int j, int h){
    printf("node: %d, l: %d, r: %d, i: %d, j: %d\n");
    if(minh[node]>h){
      return 0;
    }
    if(j<l || r<i){
      return 0;
    }
    if(i<=l && r<=j && maxh[node]<=h){
      cout<<"lo contiene en su totalidad\n";
      if(maxh[node]<h){
        update(node, l, r, h);
      }
      return r-l;
    }
    return (queryy(node*2,l,(l+r)/2,i,j,h)+queryy(node*2+1,(l+r)/2+1,r,i,j,h));
  }
  void update(int node, int l, int r, int x){
    minh[node]=x;
    maxh[node]=x;
    //si no es hoja, divide and conquer
    update(node*2, l, (l+r)/2,x);
    update(node*2+1,l,(l+r)/2,x);
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
    cout<<"mori antes de ingreasr\n";
    vector<int> A(n,0);
    SegmentTree ST(A);
    cout<<"morisi aca?\n";
    int a,b,h;
    int sol=0;
    int val;
    for(int i=0;i<n;i++){
      cin>>a>>b>>h;
      val=ST.query(a-1,b-1,h);
      sol+=val;
      cout<<val<<endl;
    }
    cin>>a;
    cout<<sol<<endl;
  }




  return 0;
}

