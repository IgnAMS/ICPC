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
    ll n, a, b; cin>>n>>a>>b;
    ll ans = 1000;
    repx(i, 0, 1001) repx(j, 0, 1001) {
        if(i + j > 0 and (a * i + b * j) % n == 0) ans = min(ans, (ll)i + j);
    }
    cout<<ans<<'\n';

    return 0;
}