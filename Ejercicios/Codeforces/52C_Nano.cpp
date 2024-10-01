#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll minl(ll a,ll b){
  if(a>b) return b;
  else return a;
}

struct SegmentTree{
  vector<ll> ST, L;
  int n;
  SegmentTree(vector<ll> &A){
    n=A.size();
    ST.resize(n*4);
    L.resize(n*4,0);
    build(1,0,n-1,A);
  }
  void build(int nod,int l, int r, vector<ll> &A){
    if(l==r){
      ST[nod]=A[r];
      return;
    }
    build(nod*2,l,(l+r)/2,A);
    build(nod*2+1,(l+r)/2+1,r,A);
    ST[nod]=minl(ST[nod*2],ST[nod*2+1]);
    return;
  }
  ll query(int i, int j){
    if(i>j){
      return minl(queryy(1,0,n-1,0,j),queryy(1,0,n-1,i,n-1));
    }
    return queryy(1,0,n-1,i,j);
  }
  ll queryy(int nod, int l, int r, int i, int j){
    if(L[nod]!=0){
      ST[nod]+=L[nod];
      //si no es hoja, pasar la marca
      if(l!=r){
        L[2*nod]+=L[nod];
        L[2*nod+1]+=L[nod];
      }
      L[nod]=0;
	  }

    if(i<=l && r<=j){
      return ST[nod];
    }
    if(j<l || r<i){
      return INT_MAX;
    }
    return minl(queryy(2*nod,l,(l+r)/2,i,j),
               queryy(2*nod+1,(l+r)/2+1,r,i,j));

  }

  void update(int i, int j, ll x){
    if(j<i){
      update(1,0,n-1,0,j,x);
      update(1,0,n-1,i,n-1,x);
      return;
    }
    update(1,0,n-1,i,j,x);
    return;
	}
	void update(int node, int l, int r, int i, int j, ll x) {
		// Hay que actualizar
		if(L[node] != 0) {
			ST[node] += L[node];

			// Si no es hoja, pasar la marca
			if(l != r) {
				L[2*node] += L[node];
				L[2*node+1] += L[node];
			}

			L[node] = 0;
		}

		// Caso 1
		if(i <= l && r <= j) {
			ST[node] += x;

			if(l != r) {
				L[2*node] += x;
				L[2*node+1] += x;
			}

			return;
		}

		// Caso 2
		if(j<l || i>r) return;

		// Caso 3
		update(2*node, l, (l+r)/2, i, j, x);
		update(2*node+1, (l+r)/2+1, r, i, j, x);

		ST[node] = minl(ST[2*node], ST[2*node+1]);
	}
	void printvec(){
	  cout<<"el vector ST tiene valores de: \n";
    for(int i=0;i<ST.size();i++) cout<<ST[i]<<" ";
    cout<<"\nY tiene que actualizar los nodos:\n";
    for(int j=0;j<L.size();j++) cout<<L[j]<<" ";
    cout<<endl;
  }
};

int main(){
  //cout<<"long long max: "<<LONG_LONG_MAX<<endl;
  //cout<<"int max: "<<INT_MAX<<endl;
  int n;
  cin>>n;
  vector<ll> A(n);
  for(int i=0;i<n;i++) cin>>A[i];
  SegmentTree ST(A);
  int m;
  cin>>m;
  getchar();
  string linea="";
  for(int i=0;i<m;i++){
    getline(cin,linea);
    vector<ll> comm;
    ll aux=INT_MAX;
    int mult=1;
    for(int j=0;j<linea.length();j++){
      if('0'<=linea[j] && linea[j]<='9'){
        if(aux==INT_MAX) aux=0;
        aux*=10;
        aux+=linea[j]-'0';
      }
      else if(linea[j]=='-'){
        mult=-1;
      }
      else{
        comm.push_back(mult*aux);
        mult=1;
        aux=INT_MAX;
      }
    }
    if(aux!=INT_MAX){
      comm.push_back(mult*aux);
      mult=1;
      aux=INT_MAX;
    }
    //cout<<"elementos de comm:\n";
    //for(int i=0;i<comm.size();i++) cout<<comm[i]<<" ";
    //cout<<endl;
    if(comm.size()==2){
      cout<<ST.query(comm[0],comm[1])<<endl;

    }
    else{
      ST.update(comm[0],comm[1],comm[2]);
      //ST.printvec();
    }
  }

  return 0;
}
