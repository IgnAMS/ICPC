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
// g++ -O2 D.cpp && time ./a.out <input.txt> output.txt

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n, d; cin>>n>>d;
    vector<ii> P(n); rep(i, n) cin>>P[i].ff>>P[i].ss;
    sort(P.begin(), P.end());
    int low = 0;
    ll acc = 0;
    ll ans = 0;
    rep(i, n) {
        acc += P[i].ss;
        while(low < i and P[low].ff + d <= P[i].ff) acc -= P[low++].ss;
        ans = max(ans, acc);
    }
    cout<<ans<<'\n';


    return 0;
}