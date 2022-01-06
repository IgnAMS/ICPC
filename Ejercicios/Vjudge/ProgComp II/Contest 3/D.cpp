#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;


struct ST{
	vector<ll> st, L;
	int N;

	ST(int n){  //le da los  elementos para construir el objeto
		N = n;

		st.assign(4*N,0);
		L.resize(4*N,0);
	}

	int query(int i, int j) {
		return query(1, 0, N-1, i, j);
	}

	int query(int node, int l, int r, int i, int j) {
	  if(L[node]!=0){
		st[node]+=L[node];
		//si no es hoja, pasar la marca
		if(l!=r){
			L[2*node]+=L[node];
			L[2*node+1]+=L[node];
		}
		L[node]=0;
	  }
		//Caso 1
		if(i <= l && r <= j) return st[node];

		//Caso 2
		if(j < l || r < i) return INT_MAX; // INT_MAX ES INFINITO
		//Caso 3
		return min(query(2*node, l, (l+r)/2, i, j),
					query(2*node+1, (l+r)/2+1, r, i, j)); //va a comparar el menor de los nodos hijos
	}

	void update(int i, int j, int x){
        update(1,0,N-1,i,j,x);
	}

	void update(int node, int l, int r, int i, int j, ll x) {
		// Hay que actualizar
		if(L[node] != 0) {
			st[node] += L[node];

			// Si no es hoja, pasar la marca
			if(l != r) {
				L[2*node] += L[node];
				L[2*node+1] += L[node];
			}
			L[node] = 0;
		}

		// Caso 1
		if(i <= l && r <= j) {
			st[node] += x;
			if(l != r) {
				L[2*node] += x;
				L[2*node+1] += x;
			}
			return;
		}

		// Caso 2
		if(i > r || j < l) return;

		// Caso 3
		update(2*node, l, (l+r)/2, i, j, x);
		update(2*node+1, (l+r)/2+1, r, i, j, x);

		st[node] = min(st[2*node], st[2*node+1]);
	}

};


int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin>>t;
    while(t--){
        int n,u; cin>>n>>u;
        ST seg= ST(n);
        ll i,j,v;
        while(u--){
            cin>>i>>j>>v;
            seg.update(i,j,v);
        }
        int q; cin>>q;
        while(q--){
            cin>>i;
            cout<<seg.query(i,i)<<"\n";
        }
    }



    return 0;
}