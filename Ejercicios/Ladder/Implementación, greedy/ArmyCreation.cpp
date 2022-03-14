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


void Merge(vi& A, vi& B, vi& X) {
    ll a = 0, b = 0;
    X.assign(A.size() + B.size(), 0);
    rep(i, A.size() + B.size()) {
        if(a < A.size() and b < B.size() and A[a] <=B[b]) X[i] = A[a++];
        else if(a < A.size() and b < B.size()) X[i] = B[b++];
        else if(a == A.size()) X[i] = B[b++];
        else X[i] = A[a++];
    } 
}


vector<vi> T(400005, vi());
void ST(ll l, ll r, ll u, vi& B) {
    if(l == r) T[u] = {B[l]};
    else {
        ST(l, (l + r) / 2, 2 * u, B);
        ST((l + r) / 2 + 1, r, 2 * u + 1, B);
        vi& A = T[2 * u];
        vi& B = T[2 * u + 1];
        Merge(A, B, T[u]);
    }
}

// l, r son actuales
ll query(ll l, ll r, ll i, ll j, ll u, ll x) {
    if(l > j or r < i) return 0;
    if(i <= l and r <= j) return lower_bound(T[u].begin(), T[u].end(), x) - T[u].begin();
    ll L = query(l, (l + r) / 2, i, j, 2 * u, x);
    ll R = query((l + r) / 2 + 1, r, i, j, 2 * u + 1, x);
    return L + R;
}




int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, k; cin>>n>>k;
    vi A(n); rep(i, n) cin>>A[i];
    map<ll, deque<ll>> mp;
    vi B(n, -1);
    rep(i, n) {
        if(!mp.count(A[i])) mp[A[i]] = deque<ll>();
        if(mp[A[i]].size() == k) {
            B[i] = mp[A[i]].front();
            mp[A[i]].pop_front();
        }
        mp[A[i]].push_back(i);
    }
    // rep(i, n) ST(0, n - 1, 1, i, B[i]);
    ST(0, n - 1, 1, B);
    ll last = 0;
    int q; cin>>q;
    rep(_, q) {
        ll x, y; cin>>x>>y;
        ll l = (x + last) % n + 1, r = (y + last) % n + 1;
        if(l > r) swap(l, r);
        last = query(0, n - 1, l - 1, r - 1, 1, l - 1);
        cout<<last<<'\n';
    }



    return 0;
}