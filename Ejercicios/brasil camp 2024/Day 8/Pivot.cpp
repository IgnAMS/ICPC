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

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    ll A[n];
    ll L[n], R[n];
    L[0] = -1, R[n - 1] = 3000000000LL;
    rep(i, n) {
        cin>>A[i];
        if(i + 1 < n) L[i + 1] = max(L[i], A[i]);
    }
    for(int i = n - 1; i >= 1; i--) {
        R[i - 1] = min(R[i], A[i]);
    }
    set<ll> S;
    rep(i, n) {
        if(L[i] <= A[i] and A[i] <= R[i]) S.insert(A[i]);
    }
    for(auto u: S) cout<<u<<'\n';




    return 0;
}