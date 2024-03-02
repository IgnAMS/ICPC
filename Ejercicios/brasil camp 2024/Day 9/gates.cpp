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
    ll L; cin>>L;

    int n; cin>>n;
    ll T[n]; rep(i, n) cin>>T[i];
    int g; cin>>g;
    ll G[g]; rep(i, g) cin>>G[i];
    
    ll Acc[n];
    Acc[0] = 0;
    rep(i, n - 1) {
        Acc[i + 1] = Acc[i] + T[i + 1] - T[i];
    }
    ll ans;
    if(g >= n - 1) ans = n - 1;
    else {
        // n - 2
        ll first = Acc[g] + T[0];
        ll last = T[n - 1] + g;
        ans = last - first;
    }
    cout<<ans<<'\n';

    return 0;
}