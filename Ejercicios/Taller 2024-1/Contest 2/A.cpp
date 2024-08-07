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

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, q; cin>>n>>q;
    vl A(n); rep(i, n) cin>>A[i];
    while(q--) {
        int x; cin>>x;
        auto it = lower_bound(A.begin(), A.end(), x);
        if(it == A.end() or *it != x) cout<<"-1\n";
        else {
            int ans = it - A.begin();
            cout<<ans<<'\n';
        }
    }

    return 0;
}