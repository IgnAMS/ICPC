#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<ll, ll> ii;
typedef double db;
typedef vector<ll> vi;
#define ff first
#define ss second
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
//  g++ -O2 D.cpp && time ./a.out < input.txt > output.txt

int N = 2 * 1e5 + 4;
vi Min(4 * N);
vi Max(4 * N);
void update(int l, int r, int u, int pos, ll x) {
    if(l == r) Min[u] = x, Max[u] = x;
    else {
        if(pos <= (l + r) / 2) update(l, (l + r) / 2, 2 * u, pos, x);
        else update((l + r) / 2 + 1, r, 2 * u + 1, pos,  x);
        Min[u] = min(Min[2 * u], Min[2 * u + 1]);
        Max[u] = max(Max[2 * u], Max[2 * u + 1]);
    }
}

// l, r son actual, i, j son query
ii query(int i, int j, int l, int r, int u) {
    if(r < i or l > j) return { 1e9, -1e9 };
    if(i <= l and r <= j) return { Min[u], Max[u] };
    ii L = query(i, j, l, (l + r) / 2, 2 * u), R = query(i, j, (l + r) / 2 + 1, r, 2 * u + 1);
    return { min(L.ff, R.ff), max(L.ss, R.ss) };
}



int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) {
        int n, m; cin>>n>>m;
        string s; cin>>s;
        vi A(n); rep(i, n) A[i] = (s[i] == '+'? 1: -1);
        vi Acc(n + 1, 0); rep(i, n) Acc[i + 1] = A[i] + Acc[i];
        rep(i, n + 1) update(0, n, 1, i, Acc[i]);
        rep(_, m) {
            int l, r; cin>>l>>r;
            ii L = query(0, l - 1, 0, n, 1);
            ii R = query(r + 1, n, 0, n, 1);
            ll x = Acc[r] - Acc[l - 1];
            // cerr<<"termine la query: "<<_<<'\n';
            // cerr<<"query L: "<<L.ff<<", "<<L.ss<<'\n';
            // cerr<<"query R: "<<R.ff<<", "<<R.ss<<'\n';
            // cerr<<"x: "<<x<<"\n\n";
            ll mn = min(L.ff, R.ff - x), mx = max(L.ss, R.ss - x);
            cout<<mx - mn + 1<<'\n';
        }
    }



    return 0;
}