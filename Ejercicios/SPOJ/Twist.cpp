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


// https://github.com/mhunicken/icpc-team-notebook-el-vasito/blob/master/data_structures/treap_implicit.cpp

// example that supports range reverse and addition updates, and range sum query
// (commented parts are specific to this  problem)
typedef struct item *pitem;
struct item {
	int pr,cnt,val;
//	int sum; // (paramters for range query)
    bool rev;int add; // (parameters for lazy prop)
	pitem l,r;
	item(int val): pr(rand()),cnt(1),val(val),l(0),r(0), rev(0) /*,sum(val),rev(0),add(0)*/ {}
};
void push(pitem it){
	if(it){
		if(it->rev){
			swap(it->l,it->r);
			if(it->l) it->l->rev^=1;
			if(it->r) it->r->rev^=1;
			it->rev=0;
		}
        /*
		it->val+=it->add;it->sum+=it->cnt*it->add;
		if(it->l)it->l->add+=it->add;
		if(it->r)it->r->add+=it->add;
		it->add=0*/
	}
}
int cnt(pitem t){return t?t->cnt:0;}
// int sum(pitem t){return t?push(t),t->sum:0;}
void upd_cnt(pitem t){
	if(t){
		t->cnt=cnt(t->l)+cnt(t->r)+1;
		// t->sum=t->val+sum(t->l)+sum(t->r);
	}
}
void merge(pitem& t, pitem l, pitem r){
	push(l); push(r);
    if(!l||!r) t = (l? l : r);
	else if(l->pr>r->pr)merge(l->r,l->r,r),t=l;
	else merge(r->l,l,r->l),t=r;
	upd_cnt(t);
}
void split(pitem t, pitem& l, pitem& r, int sz){ // sz:desired size of l
	if(!t){l=r=0;return;}
	push(t);
	if(sz<=cnt(t->l))split(t->l,l,t->l,sz),r=t;
	else split(t->r,t->r,r,sz-1-cnt(t->l)),l=t;
	upd_cnt(t);
}
void output(pitem t){ // useful for debugging
	if(!t)return;
	push(t);
	output(t->l);printf("%d ",t->val);output(t->r);
}
// use merge and split for range updates and queries

void printt(pitem T) {
    if(!T) return;
    push(T);
    printt(T->l);
    cout<<T->val<<' ';
    printt(T->r); 
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin>>n>>m;
    pitem T = 0;
    rep(i, n) {
        merge(T, T, new item(int(i + 1)));
    }
    rep(i, m) {
        int l, r; cin>>l>>r;
        pitem A, B, C; 
        // A: [1, l - 1], B: [l, r], C: [r + 1, n]
        split(T, A, B, l - 1); 
        split(B, B, C, r - l + 1);
        push(B);
        B->rev = 1;
        merge(T, A, B);
        merge(T, T, C);
    }
    printt(T); cout<<'\n';

    return 0;
}