#pragma GCC optimize("Ofast")
#include<iostream>
#include<vector>
#include<string.h>
#include<set>
#include<map>
#include<algorithm>
#include<unordered_map>
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
// g++ -O2 CollectingNumbers.cpp && time ./a.out <input.txt> output.txt

const int INF = 1e9+1;
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    ll A[n+1], Index[n+1]; 
    rep(i, n) {
        cin>>A[i];
        Index[A[i]] = i;
    }

    ll R[n];
    A[n] = n+1;
    set<pll> S = {{n+1, n}};
    for(int i = n - 1; i >= 0; i--) {
        pll right = *S.lower_bound(pll(A[i], 0));
        R[i] = right.ss;
        S.insert({A[i], i});
    }


    ll curr = 1;
    ll ans = 0;
    while(curr <= n) {
        int i = Index[curr];
        ans++;
        while(A[i] == curr and curr <= n) {
            // cout<<"i: "<<i<<", A[i]: "<<A[i]<<", curr: "<<curr<<"\n";
            i = R[i];
            curr++;
        }
    }
    cout<<ans<<"\n";

    return 0;
}