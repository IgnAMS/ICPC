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

struct SegmentTree {
	vl ST; int N;
	SegmentTree(vl &A){
		N = A.size();
		ST.assign(4*N, 0);
		bd(1,0,N-1,A);
	}
	ll op(ll x, ll y) { return max(x,y); }
	void bd(int n, int l, int r, vl &A){
		if(l == r){
			ST[n] = A[r];
			return;
		}
        int m = (l + r) / 2;
		bd(2 * n, l, m, A);
		bd(2*n+1, m+1, r, A);
		ST[n] = op(ST[2*n], ST[2*n+1]);
	}
	ll qry(int i, int j){
		return qry(1,0,N-1,i,j);
	}
	ll qry(int n, int l, int r, int i, ll j){
		if(r < i || j < l) return 0;
		if(i <= l && r <= j) return ST[n];
		return op(qry(2*n,l,(l+r)/2,i,j), qry(2*n+1,(l+r)/2+1,r,i,j));
	}
	void upd(int i, ll v){
		return upd(1,0,N-1,i,v);
	}
	void upd(int n, int l, int r, int i, ll v){
		if(i < l || r < i) return;
		if(l == r){
			ST[n] = v;
			return;
		}
		upd(2*n,l,(l+r)/2,i,v);
		upd(2*n+1,(l+r)/2+1,r,i,v);
		ST[n] = op(ST[2*n], ST[2*n+1]);
	}
};


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n, s; cin>>n>>s;
    vector<vl> S(n, vl(3));
    rep(i, n) cin>>S[i][0]>>S[i][1]>>S[i][2];
    sort(S.begin(), S.end());

    ll DP[n];
    vl Aux(n, 0);
    SegmentTree ST1(Aux), ST2(Aux);
    ll ans = 0;
    for(int i = n - 1; i >= 0; i--) {
        if(i == n - 1) {
            DP[i] = max(0LL, (S[i][1] + 1 - S[i][0]) * s - S[i][2]);
        }
        else {
            vl aux = {S[i][1] + 1, 0, 0};
            int k = lower_bound(S.begin(), S.end(), aux) - S.begin();
            DP[i] = max(0LL, (S[i][1] + 1 - S[i][0]) * s - S[i][2]);
            // i < j < k -> ST2query - S[i][0] * s - S[i][2]
            if(i + 1 <= k - 1) DP[i] = max(DP[i], ST2.qry(i + 1, k - 1) - S[i][0] * s - S[i][2]);
            if(k <= n - 1) DP[i] = max(DP[i], ST1.qry(k, n - 1) + (S[i][1] + 1 - S[i][0]) * s - S[i][2]);
        }
        ST1.upd(i, DP[i]);
        ST2.upd(i, DP[i] + s * S[i][0]);    
        ans = max(ans, DP[i]);
    }
    cout<<ans<<'\n';




    return 0;
}