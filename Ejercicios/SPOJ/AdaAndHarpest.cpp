#pragma GCC optimize("Ofast")
// #pragma GCC target("avx,avx2,fma")
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



typedef struct item *pitem;

struct item {
	ll pr,key,cnt;
	ll val, suma;
	pitem l, r;
	item(ll key):key(key), pr(rand()),cnt(1),l(0),r(0) {}
};
int cnt(pitem t) { return t? t->cnt: 0; }
void upd_cnt(pitem t){
	if(t) {
		t->cnt=cnt(t->l)+cnt(t->r)+1;
	}
}
void split(pitem t, ll key, pitem& l, pitem& r){ // l: < key, r: >= key
	if(!t) l = r = 0;
	else if(key < t->key) split(t->l,key,l,t->l),r=t;
	else split(t->r,key,t->r,r),l=t;
	upd_cnt(t);
}
void insert(pitem& t, pitem it){
	if(!t) t = it;
	else if(it->pr > t->pr) split(t,it->key,it->l,it->r),t=it;
	else insert(it->key<t->key?t->l:t->r,it);
	upd_cnt(t);
}
void merge(pitem& t, pitem l, pitem r){
	if(!l||!r)t=(l? l : r);
	else if(l->pr>r->pr) merge(l->r,l->r,r),t=l;
	else merge(r->l,l,r->l),t=r;
	upd_cnt(t);
}
ll iteraciones = 0;
void printt(pitem t) {
	if(!t or ++iteraciones > 30) return; 
	printt(t->l);
	cerr<<t->key<<'\n';
	printt(t->r);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, q; cin>>n>>q;
    set<ll> S;
    vl A(n);
    rep(i, n) cin>>A[i];
    vector<pll> E(q);
    rep(i, q) {
        cin>>E[i].ff>>E[i].ss;
        S.insert(E[i].ss);
    }
    rep(i, n) S.insert(A[i]);
    map<int, int> mp;
    ll auxi = 0;
    for(auto u: S) mp[u] = auxi++;
    
    pitem Roots[S.size()];
    rep(i, S.size()) Roots[i] = 0;
    rep(i, n) {
        pitem L, R;
        ll u = mp[A[i]];
        split(Roots[u], i, L, R);
        merge(Roots[u], L, new item(i));
        merge(Roots[u], Roots[u], R);   
    }
    rep(i, q) {
        pitem L, M, R;
        ll u = mp[A[E[i].ff]], v = mp[E[i].ss];
        // cerr<<"Arbol a dividir "<<u<<":\n";
        // printt(Roots[u]);

        split(Roots[u], E[i].ff - 1, L, M);
        split(M, E[i].ff, M, R);
        if(u == v) {
            cout<<cnt(L)<<'\n';
            merge(Roots[u], L, M);
            merge(Roots[u], Roots[u], R);
        }
        else {
            merge(Roots[u], L, R);
            pitem LL, RR;
            split(Roots[v], E[i].ff, LL, RR);
            cout<<cnt(LL)<<'\n';
            merge(Roots[v], LL, new item(E[i].ff));
            merge(Roots[v], Roots[v], RR);
            A[E[i].ff] = E[i].ss;
        }

    }



    return 0;
}