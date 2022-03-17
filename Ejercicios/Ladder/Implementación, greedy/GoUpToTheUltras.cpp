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

vi t;
void update(ll l, ll r, ll u, ll pos, ll x) {
    if(l == r) t[u] = x;
    else {
        if(pos <= (l + r ) / 2) update(l, (l + r) / 2, 2 * u, pos, x);
        else update((l + r) / 2 + 1, r , 2 * u + 1, pos, x);
        t[u] = min(t[2 * u], t[2 * u + 1]); 
    }
}

ll query(ll l, ll r, ll i, ll j, ll u) {
    if(r < i or j < l) return 10000000;
    if(i <= l and r <= j) return t[u];
    return min(query(l, (l + r) / 2, i, j, 2 * u), query((l + r) / 2 + 1, r, i, j, 2 * u + 1));
}



int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; 
    while(cin>>n) {
        vi A(n); rep(i, n) cin>>A[i];

        t.assign(4 * n, 10000000);
        rep(i, n) update(0, n - 1, 1, i, A[i]);

        vi mxR(n, 0);
        vi mxL(n, 0);
        vector<ii> S;
        rep(i, n) {
            while(S.size() and S.back().ff <= A[i]) {
                S.pop_back();
            }
            if(!S.size()) mxL[i] = i;
            else mxL[i] = S.back().ss;
            S.push_back({A[i], i});
        }
        S.clear();
        for(int i = n - 1; i >= 0; i--) {
            while(S.size() and S.back().ff <= A[i]) {
                S.pop_back();
            }
            if(!S.size()) mxR[i] = i;
            else mxR[i] = S.back().ss;
            S.push_back({A[i], i});
        }

        vi ans;
        rep(i, n) {
            ll d = A[i];
            if(mxL[i] != i) d = min(d, A[i] - query(0, n - 1, mxL[i], i - 1, 1));
            if(mxR[i] != i) d = min(d, A[i] - query(0, n - 1, i + 1, mxR[i], 1));
            if(d >= 150000) ans.push_back(i);
        }
        rep(i, ans.size()) cout<<ans[i] + 1<<" \n"[i == ans.size() - 1];

    }



    return 0;
}