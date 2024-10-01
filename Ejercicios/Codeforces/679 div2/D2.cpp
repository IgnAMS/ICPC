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

ll Min[1000000], Max[1000000];
void update(int i, int j, int pos, ll x, int u) {
    if(i == j) {
        Min[u] = x, Max[u] = x;
    }
    else{
        if(pos <= (i + j) / 2) update(i, (i + j) / 2, pos, x, 2 * u);
        else update((i + j) / 2 + 1, j, pos, x, 2 * u + 1);
        Min[u] = min(Min[2 * u], Min[2 * u + 1]);
        Max[u] = max(Max[2 * u], Max[2 * u + 1]);
    }
    // cerr<<i<<' '<<j<<' '<<pos<<' '<<u<<' '<<T[u]<<'\n';
}


// l, r son el rango actual. i, j son la query
ii query(int i, int j, int l, int r, int u) {
    // cerr<<"pregunto por el rango "<<i<<' '<<j<<' '<<l<<' '<<r<<' '<<(i <= l and r <= j)<<' '<<u<<'\n';
    if(j < l or i > r) return { 1000000, 0 };
    if(i <= l and r <= j) return { Min[u], Max[u] };
    ii L = query(i, j, l, (l + r) / 2, 2 * u);
    ii R = query(i, j, (l + r) / 2 + 1, r, 2 * u + 1);
    // cerr<<L<<' '<<R<<'\n';
    return { min(L.ff, R.ff), max(L.ss, R.ss) };
} 



int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    vector<ii> A(2 * n);
    rep(i, 1000000) Min[i] = 1000000, Max[i] = 0;
    rep(i, 2 * n) {
        char c; cin>>c;
        A[i].ff = (c == '+');
        if(c == '-') {
            int h; cin>>h;
            A[i].ss = h;
            update(0, 2 * n - 1, i, h, 1);
        }
    }
    
    vi S;
    vi Ans(2 * n, -1);
    rep(i, 2 * n) {
        if(A[i].ff) S.push_back(i);
        else {
            if(S.empty()) { cout<<"NO\n"; return 0; }
            ii q = query(S.back(), i - 1, 0, 2 * n - 1, 1);
            cerr<<A[i].ss<<' '<<q.ff<<' '<<q.ss<<'\n';
            // if(i + 1 < n and !A[i + 1].ff and A[i].ss > A[i + 1].ss) { cout<<"NO\n"; return 0; }
            if(q.ff != 1000000 and A[i].ss < q.ff) { cout<<"NO\n"; return 0; }
            if(q.ss != 0 and A[i].ss < q.ss) { cout<<"NO\n"; return 0; }
            Ans[S.back()] = A[i].ss;
            S.pop_back();
        }
    }   
    cout<<"YES\n";
    rep(i, 2 * n) if(Ans[i] != -1) cout<<Ans[i]<<' '; cout<<'\n';

    return 0;
}