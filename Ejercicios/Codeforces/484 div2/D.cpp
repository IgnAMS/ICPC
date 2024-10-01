#pragma GCC optimize("Ofast")
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

struct DSU {
    vl p; DSU(int N) : p(N, -1) {}
    int get(int x) { return p[x] < 0 ? x : p[x] = get(p[x]); } 
    bool sameSet(int a, int b) { return get(a) == get(b); }
    int size(int x) { return -p[get(x)]; }
    void unite(int x, int y) {
        if ((x = get(x)) == (y = get(y))) return;
        if (p[x] > p[y]) swap(x,y);
        p[x] += p[y], p[y] = x;
    }
};



int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    vl A(n);
    vector<pll> X(n);
    rep(i, n) {
        cin>>A[i];
        X[i] = {A[i], i};
    }
    sort(X.begin(), X.end());
    

    ll prev = -1;
    multiset<ll> S1, S2;
    vector<bool> V(n, 0);
    ll best_size = 0;
    ll best_k = -1;
    DSU dsu(n);
    rep(i, n) S1.insert(1);
    rep(i, n) {
        if(X[i].ff != prev) {
            if(S2.size() and *S2.begin() == *S2.rbegin() and best_size < S2.size()) {
                best_size = S2.size();
                best_k = prev + 1;
            }
            prev = X[i].ff;
        }

        // cout<<"los tamanos de los conjuntos son:\n";
        // for(auto u: S1) cout<<u<<", "; cout<<'\n';
        // for(auto u: S2) cout<<u<<", "; cout<<'\n';
        
        ll ind = X[i].ss;
        if(!V[ind]) {
            S1.erase(S1.find(1));
            S2.insert(1);
            V[ind] = 1;
        }
        if(ind >= 1 and A[ind - 1] <= A[ind]) {
            S2.erase(S2.find(-dsu.p[dsu.get(ind)]));
            if(!V[ind - 1]) S1.erase(S1.find(-dsu.p[dsu.get(ind - 1)]));
            else S2.erase(S2.find(-dsu.p[dsu.get(ind - 1)]));

            V[ind] = V[ind - 1] = 1;
            dsu.unite(ind, ind - 1);
            S2.insert(-dsu.p[dsu.get(ind)]);
        }
        if(ind + 1 < n and A[ind + 1] < A[ind]) {
            S2.erase(S2.find(-dsu.p[dsu.get(ind)]));
            if(!V[ind + 1]) S1.erase(S1.find(-dsu.p[dsu.get(ind + 1)]));
            else S2.erase(S2.find(-dsu.p[dsu.get(ind + 1)]));

            V[ind] = V[ind + 1] = 1;
            dsu.unite(ind, ind + 1);
            S2.insert(-dsu.p[dsu.get(ind)]);
        }
    }
    if(S2.size() and *S2.begin() == *S2.rbegin() and best_size < S2.size()) {
        best_size = S2.size();
        best_k = prev + 1;
    }

    cout<<best_k<<'\n';
    return 0;
}