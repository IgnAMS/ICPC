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

const ll mxN = 2e5 + 5;
ll A[mxN], B[mxN];

struct Median {
    // L puede tener a lo mas 1 mas que R
    multiset<pll> L = {{ll(-1), mxN + 1}}, R = {{ll(1e11), mxN + 2}};
    Median() {}
    multiset<ll> XB;
    void add(ll x, ll i) {
        L.insert({x, i});
        if(L.size() > R.size() + 1) {
            R.insert(*L.rbegin());
            L.erase(*L.rbegin());
        }
        if(L.rbegin()->ff > R.begin()->ff) {
            pll aux = *L.rbegin();
            pll aux2 = *R.begin();
            R.insert(aux);
            L.erase(aux);
            L.insert(aux2);
            R.erase(aux2);
            // swap(L.rbegin(), R.begin());
        }
        if(B[i]) XB.insert(x);
    }

    void erase(ll x, ll i) {
        if(B[i]) XB.erase(x);
        if(L.count({x, i})) L.erase({x, i});
        else R.erase({x, i});
        // balanceo
        if(R.size() > L.size()) {
            L.insert(*R.begin());
            R.erase(*R.begin());
        }
        if(L.size() > R.size() + 1) {
            R.insert(*L.rbegin());
            L.erase(*L.rbegin());
        }
    }
    ll median() {
        return (*L.rbegin()).ff;
    }
    ll best() {
        if(XB.size() == 0) return -1;
        auto it = XB.upper_bound(median());
        if(it == XB.begin()) return -1;
        return *prev(it);
    }
};





int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) {
        int n, k; cin>>n>>k;
        rep(i, n) cin>>A[i];
        rep(i, n) cin>>B[i];
        ll ans = 0;
        Median med;
        
        rep(i, n) {
            med.add(A[i], i);
        }
        vl A2(n);
        rep(i, n) A2[i] = A[i];
        sort(A2.begin(), A2.end());

        vl X;
        rep(i, n) if(B[i]) X.pb(A[i]);
        sort(X.begin(), X.end());
        vl Acc(X.size() + 2, 0);
        Acc[X.size()] = Acc[X.size() + 1] = 0;
        for(int i = ll(X.size()) - 1; i >= 0; i--) {
            Acc[i] = Acc[i + 1] + X[i];
        }
 
        rep(i, n) {
            med.erase(A[i], i);
            if(B[i]) {
                // cout<<"0 "<<A[i] + k + med.median()<<'\n';
                ans = max(ans, A[i] + k + med.median());
            }
            else {
                ll l = 0, r = 1e11;
                while(l < r) {
                    ll m = (l + r + 1) / 2;
                    // x := cantidad de elementos en A menores a m
                    ll x = lower_bound(A2.begin(), A2.end(), m) - A2.begin();
                    if(A[i] < m) x--;
                    // calculo la maxima cantidad de elementos que puedo cubrir
                    ll ind = lower_bound(X.begin(), X.end(), m) - X.begin(); 
                    ll l1 = 0, r1 = ind;
                    while(l1 < r1) {
                        ll m1 = (l1 + r1 + 1) / 2;
                        if(m * m1 - (Acc[ind - m1] - Acc[ind]) <= k) l1 = m1;
                        else r1 = m1 - 1;
                    }

                    ll x2 = l1;
                    if(x - x2 < n / 2) l = m;
                    else r = m - 1;
                }
                ans = max(ans, A[i] + l);
            }
            med.add(A[i], i);
        }
        cout<<ans<<'\n';

    }





    return 0;
}