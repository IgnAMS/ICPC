#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
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

mt19937 gen(chrono::high_resolution_clock::now().time_since_epoch().count());


typedef struct item *pitem;

struct item {
	ll pr,key,cnt;
	ll val, suma;
	pitem l, r;
	item(ll key, ll val):key(key), val(val), suma(val), pr(rand()),cnt(1),l(0),r(0) {}
};
int cnt(pitem t) { return t? t->cnt: 0; }
ll suma(pitem t) { return t? t->suma: 0; }
void upd_cnt(pitem t){
	if(t) {
		t->cnt=cnt(t->l)+cnt(t->r)+1;
		t->suma = suma(t->l) + suma(t->r) + t->val;
	}
}
void split(pitem t, ll key, pitem& l, pitem& r){ // l: < key, r: >= key
	if(!t) l = r = nullptr;
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
	cerr<<t->key<<' '<<t->val<<'\n';
	printt(t->r);
}



int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int q; cin>>q;
    pitem T = nullptr;
    ll L = 0;
    rep(i, q) {
        ll a, v; cin>>a>>v;
        a ^= L, v ^= L;
        pitem A = 0, B = 0, C = 0;
		iteraciones = 0; 
		split(T, a - 1, A, B);
		split(B, a, B, C);
		// A = [0, a - 1], B = [a, a], C = [a + 1, inf]
		// cerr<<'\n';
		// cerr<<a<<' '<<v<<'\n';
		// cerr<<"A:\n";
		// printt(A);
		// cerr<<"B:\n";
		// printt(B);
		// cerr<<"C:\n";
		// printt(C);
		ll sum = suma(A) + suma(B) + v;
		if(B) B->val += v;
		else merge(B, B, new item(a, v));
		merge(T, A, B);
		merge(T, T, C);
		L = sum;
		cout<<a<<' '<<sum<<'\n';
    }





    return 0;
}