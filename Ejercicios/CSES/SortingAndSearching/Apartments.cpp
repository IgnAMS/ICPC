#pragma GCC optimize("Ofast")
#include<iostream>
#include<vector>
#include<string.h>
#include<set>
#include<map>
#include <algorithm>
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
// g++ -std=c++17 MissingCoinSum.cpp -o a && ./a <input.txt> output.txt
// ulimit -s 1000000
// g++ -O2 Apartments.cpp && time ./a.out <input.txt> output.txt


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m, k; cin>>n>>m>>k;
    multiset<ll> S;
    int A[n];
    rep(i, n) {
        cin>>A[i];
    }
    rep(i, m) {
        int x; cin>>x; S.insert(x);
    }

    sort(A, A+n);
    ll ans = 0;
    rep(i, n) {
        auto it = S.lower_bound(A[i] - k);
        if(it != S.end() and *it <= A[i] + k) {
            ans += 1;
            S.erase(S.find(*it));
        }
    }
    cout<<ans<<"\n";

    
    return 0;
}