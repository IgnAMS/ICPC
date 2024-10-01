#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<int,int> ii;
typedef double db;
typedef vector<ll> vi;
#define ff first
#define ss second
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
//  g++ -O2 D.cpp && time ./a.out < input.txt > output.txt


ll buscar(ll x, ll l, ll r, vector<vi>& A) {
    auto L = lower_bound(A[x].begin(), A[x].end(), l);
    auto R = lower_bound(A[x].begin(), A[x].end(), r);

    ll ans = x;
    ll lx = l;
    if(L != A[x].begin()) {
        lx = *prev(L);
    }
    if(L != A[x].begin()) {
        L = prev(L);
        auto L2 = lower_bound(A[x + 1].begin(), A[x + 1].end(), *L);
        if(L2 == A[x + 1].end() or *L2 > r) lx = *L;
    }
    else ans = max(ans, x + 1);
    if(R != A[x].end()) {
        auto L2 = lower_bound(A[x + 1].begin(), A[x + 1].end(), l);
        if(L2 == A[x + 1].end() or *L2 > *R) ans = max(ans, buscar(x + 1, l, *R, A)); 
    }
    else ans = max(ans, x + 1);

    return ans;
}



int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    vi A(n); rep(i, n) cin>>A[i];
    vector<vi> B(n + 1, vi());
    rep(i, n) B[A[i]].push_back(i);
    ll ans = 0;
    if(B[1].size() == n) { cout<<"0\n"; return 0; }
    if(B[1].size() == 0) { cout<<"1\n"; return 0; }
    for(auto u: B[1]) ans = max(ans, buscar(2, u, u, B));
    cout<<ans<<'\n';




    return 0;
}