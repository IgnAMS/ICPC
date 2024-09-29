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

struct Median {
    multiset<ll> L, R;
    ll sumL = 0, sumR = 0;
    void balance() {
        if(L.size() > 1 + R.size()) {
            sumL -= *L.rbegin();
            sumR += *L.rbegin();
            R.insert(*L.rbegin());
            L.erase(L.find(*L.rbegin()));
        }
        if(R.size() > L.size()) {
            sumL += *R.begin();
            sumR -= *R.begin();
            L.insert(*R.begin());
            R.erase(R.find(*R.begin()));
        }
        if(L.size() and R.size() and *L.rbegin() > *R.begin()) {
            ll l = *L.rbegin(), r = *R.begin();
            sumL += r - l;
            sumR += l - r;
            L.insert(r);
            L.erase(L.find(l));
            R.insert(l);
            R.erase(R.find(r));
        }
    }
    void add(ll x) {
        L.insert(x);
        sumL += x;
        balance();
    }
    void erase(ll x) {
        if(L.count(x)) {
            L.erase(L.find(x));
            sumL -= x;
        }
        else {
            R.erase(R.find(x));
            sumR -= x;
        }
        balance();
    }
    ll median() {
        return *L.rbegin();
    }
    ll cost() {
        ll med = median();
        return (med * ll(L.size()) - sumL) + (sumR - med * ll(R.size()));
    }
};


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, k; cin>>n>>k;
    ll A[n]; rep(i, n) cin>>A[i];
    Median med;
    rep(i, k) med.add(A[i]);
    cout<<med.cost()<<' ';
    for(int i = k; i < n; i++) {
        med.erase(A[i - k]);
        med.add(A[i]);
        cout<<med.cost()<<' ';
    }
    cout<<'\n';


    return 0;
}