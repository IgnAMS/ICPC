#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma") // could make sigill runtime error
#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<ll, ll> pll;
typedef double db;
typedef vector<ll> vl;
#define ff first
#define ss second
#define pb push_back
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
// ulimit -s 1000000
// g++ -O2 D.cpp && time ./a.out <input.txt> output.txt


struct Node {
    ll v, cont; 
    Node(ll val, ll cont) {
        v = val;
        cont = cont;
    }
    Node() { v = 0, cont = 0; }
    Node operator + (const Node& p) const { 
        return Node(v + p.v, cont + p.cont); 
    }

};

struct SegmentTree {
	vector<Node> ST;
    vl Lazy;
    vl Lazy2;
	int N; ll Nul = 0;
	SegmentTree(vector<ll> &A) {
		N = A.size();
		ST.resize(4*N+5, Node());
		Lazy.resize(4*N+5, Nul);
        Lazy2.resize(4*N+5, Nul);
		bd(1,0,N-1,A);
	}

	void up(int n, int l, int r) {
		ST[n].v += Lazy[n] * ll(r - l + 1);
		if(l != r) {
            if(Lazy2[2*n]) Lazy2[2*n] += Lazy[n], Lazy[2*n] = Nul;
            else Lazy[2*n] += Lazy[n];
            if(Lazy2[2*n+1]) Lazy2[2*n+1] += Lazy[n], Lazy[2*n+1] = Nul;
            else Lazy[2*n+1] += Lazy[n];
		}
		Lazy[n] = Nul;
	}
    void up2(int n, int l, int r) {
		ST[n].v = Lazy2[n] * ll(r - l + 1);
		if(l != r) {
			Lazy2[n*2] = Lazy2[n];
			Lazy2[n*2+1] = Lazy2[n];
            Lazy[2*n] = Lazy[2*n+1] = Nul;
		}
		Lazy2[n] = Nul;
	}

	void bd(int n, int l, int r, vl &A) {
		if(l == r) {
			ST[n] = Node(A[r], 1);
			return;
		}
        ll m = (l + r) / 2;
		bd(2*n,l,m,A);
		bd(2*n+1,m+1,r,A);
		ST[n] = ST[2*n] + ST[2*n+1];
	}

	Node qry(int n, int l, int r, int i, int j) {
	    if(r < i || j < l) return Node();
        ll m = (l+r)/2;
        if(Lazy[n] != Nul) up(n,l,r);
        if(Lazy2[n] != Nul) up2(n, l, r);

	    if(i <= l && r <= j) {
            // cout<<"el nodo "<<l<<' '<<r<<" contiene "<<ST[n].v<<'\n';
            return ST[n];
        }
        return qry(2*n,l,(l+r)/2,i,j) + qry(2*n+1,(l+r)/2+1,r,i,j);
	}
	
	void upd(int n, int l, int r, int i, int j, ll v) {
		ll m = (l+r)/2;
        if(Lazy[n] != Nul) up(n,l,r); 
        if(Lazy2[n] != Nul) up2(n, l, r);

		if(l > j || r < i) return;
		if(i <= l && r <= j) {
			Lazy[n] += v;
            // cout<<"hago update sobre el segmento "<<l<<' '<<r<<'\n';
			if(Lazy[n] != Nul) up(n, l, r);
			return;
		}

		upd(2*n,l,m,i,j,v);
		upd(2*n+1,m+1,r,i,j,v);
		ST[n] = ST[2*n] + ST[2*n+1];
	}
    void upd2(int n, int l, int r, int i, int j, ll v) {
		ll m = (l+r)/2;
        if(Lazy[n] != Nul) up(n,l,r);
        if(l != r and Lazy[2*n] != Nul) up(2*n, l, m);
        if(l != r and Lazy[2*n+1] != Nul) up(2*n+1, m+1, r); 
        if(Lazy2[n] != Nul) up2(n, l, r);
        if(l != r and Lazy2[2*n] != Nul) up2(2*n, l, m);
        if(l != r and Lazy2[2*n+1] != Nul) up2(2*n+1, m+1, r);
          
		if(l > j || r < i) return;
		if(i <= l && r <= j) {
			Lazy2[n] = v;
			if(Lazy2[n] != Nul) up2(n, l, r);
            return;
		}

		upd2(2*n,l,m,i,j,v);
		upd2(2*n+1,m+1,r,i,j,v);
		ST[n] = ST[2*n] + ST[2*n+1];
	}

    Node qry(int i, int j) { return qry(1,0,N-1,i,j); }
    void upd(int i, int j, ll v) { return upd(1,0,N-1,i,j,v); }
    void upd2(int i, int j, ll v) { return upd2(1,0,N-1,i,j,v); }
};




int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, q; cin>>n>>q;
    vl A(n); rep(i, n) cin>>A[i];
    SegmentTree st(A);
    rep(_, q) {
        ll com, a, b; cin>>com>>a>>b; a--, b--;

        if(com == 1) {
            ll x; cin>>x;
            st.upd(a, b, x);
        }
        else if(com == 2) {
            ll x; cin>>x;
            st.upd2(a, b, x);
        }
        else {
            cout<<st.qry(a, b).v<<'\n';
        }
    }
    // rep(i, n) cout<<st.qry(i, i).v<<' '; cout<<'\n';


    return 0;
}