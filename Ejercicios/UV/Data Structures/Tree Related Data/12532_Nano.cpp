#include<bits/stdc++.h>
using namespace std;

struct SegmentTree{
  vector<int> ST,L;
  map<int,int> mapa;
  int n;
  int cont=0;
  SegmentTree(vector<int> &A){
    n=A.size();
    ST.resize(4*n);
    L.assign(4*n,1);
    build(1,0,n-1,A);
  }
  void build(int node, int l, int r, vector<int> &A){

    cont++;
    if(l==r){
      //cout<<"entre a una hoja tio\n";
      //printf("l vale: %d, r vale: %d\n",l,r);
      if(A[l]>0) ST[node]=1;
      else if(A[l]==0) ST[node]=0;
      else ST[node]=-1;
      mapa.insert(make_pair(l,node));
      return;
    }
    //printf("entre al build num %d\n",cont);
    //printf("vamos a visitar al hijo que va desde %d hasta %d\n",l,(l+r)/2);
    //printf("vamos a visitar al hijo que va desde %d hasta %d\n",(l+r)/2,r);

    build(2*node,l,(l+r)/2,A);
    build(2*node+1,(l+r)/2+1,r,A);
    //Defininmos 1 como positivo, 0 como nulo, -1 como negativo
    if(ST[node*2]*ST[node*2+1]>0) ST[node]=1;
    else if(ST[node*2]*ST[node*2+1]==0) ST[node]=0;
    else ST[node]=-1;
    return;
  }
  int query(int i, int j){
    return queryy(1,0,n-1,i,j);
  }
  int queryy(int node, int l, int r, int i, int j){

    //Caso 1 fuera
    if(j<l || r<i){
      return 1;
    }
    //Caso 2, completamente contenido
    if(i<=l && r<=j){
      //printf("estoy sacando infor del nodo %d y vale: %d\n",node,ST[node]);
      return ST[node];
    }
    //Caso 3, dividir
    return queryy(2*node, l, (l+r)/2, i,j)*queryy(2*node+1, (l+r)/2+1,r, i ,j);
  }
  void update(int i, int x){
    //cout<<"mori en el update?"<<endl;
    int pos=mapa[i];
    ST[pos]=x;
    for(int i=pos/2;i>=1;i/=2){
      if(ST[i*2]*ST[i*2+1]>0) ST[i]=1;
      else if(ST[i*2]*ST[i*2+1]==0) ST[i]=0;
      else ST[i]=-1;
    }
  }
  void printvect(string a){
    cout<<a<<endl;
    for(int i=0;i<ST.size();i++) cout<<ST[i]<<" ";
    cout<<endl;
  }

};


int main(){
  int n,m;
  while(cin>>n>>m){
    vector<int> A(n);
    for(int i=0;i<n;i++) cin>>A[i];
    SegmentTree Tree(A);
    char c;
    int a,b;
    string asd="";
    for(int i=0;i<m;i++){
      cin>>c>>a>>b;
      if(c=='P'){
        a--;
        b--;
        //Tree.printvect("bro momento");
        int val=Tree.query(a,b);
        //cout<<val<<endl;
        if(val>0){
          //cout<<"+";
          asd+="+";
        }
        else if(val==0){
          //cout<<"0";
          asd+="0";
        }
        else{
          //cout<<"-";
          asd+="-";
        }
      }
      else{
        a--;
        Tree.update(a,b);
      }
    }
    cout<<asd<<endl;
    //cout<<endl;




  }

  return 0;
}
