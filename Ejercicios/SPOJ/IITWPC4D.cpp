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
void merge(pitem& t, pitem l, pitem r){
	if(!l||!r)t=(l? l : r);
	else if(l->pr>r->pr) merge(l->r,l->r,r),t=l;
	else merge(r->l,l,r->l),t=r;
	upd_cnt(t);
}
pitem kth(pitem t, int k){
	if(!t) return 0;
	if(k == cnt(t->l)) return t;
	return k < cnt(t->l)? kth(t->l,k):kth(t->r,k-cnt(t->l)-1);
}
ll iteraciones = 0;
void printt(pitem t) {
	if(!t or ++iteraciones > 30) return; 
	printt(t->l);
	cerr<<t->key<<' ';
	printt(t->r);
}



int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, q; cin>>n>>q;
    pitem T = 0;
    rep(i, n) {
        ll x; cin>>x;
        pitem l, r;
        split(T, x, l, r);
        merge(l, l, new item(x));
        merge(T, l, r);
    } 
    while(q--) {
        ll t, x; cin>>t>>x;
        // cerr<<"proceso "<<t<<' '<<x<<'\n';
        if(t == 1) {
            pitem l, r;
            split(T, x, l, r);
            ll nw = x + cnt(l);
            merge(T, l, r);
            split(T, nw, l, r);
            merge(l, l, new item(nw));
            merge(T, l, r);
        }
        else if(t == 2) {
            pitem l, r; 
            split(T, x, l, r);
            cout<<cnt(l)<<'\n';
            merge(T, l, r);
        }
        else {
            // iteraciones = 0;
            // printt(T); cerr<<'\n';
            if(!kth(T, x - 1)) cout<<"invalid\n";
            else cout<<kth(T, x - 1)->key<<'\n';
        }
    }


    return 0;
}