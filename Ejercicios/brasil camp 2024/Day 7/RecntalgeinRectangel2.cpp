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

struct P {
    ll x, y; 
    P(): x(0), y(0) {}
    P(ll x, ll y): x(x), y(y) {}
};

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) {
        ll x1, y1, x2, y2; cin>>x1>>y1>>x2>>y2;
        P a1 = P(x1, y1);
        P a2 = P(x2, y2);
    
        ll ans = (x2 - x1) * (y2 - y1);
        cin>>x1>>y1>>x2>>y2;
        P b1 = P(x1, y1);
        P b2 = P(x2, y2);
        
        ans = max(ans, (x2 - x1) * (y2 - y1));


        if(min(a2.x, b2.x) >= max(a1.x, b1.x)) {
            ans = max(
                ans,
                (min(a2.y, b2.y) - max(a1.y, b1.y)) * (max(a2.x, b2.x) - min(a1.x, b1.x))
            );
        }
        if(min(a2.y, b2.y) >= max(a1.y, b1.y)) {
            ans = max(
                ans,
                (min(a2.x, b2.x) - max(a1.x, b1.x)) * (max(a2.y, b2.y) - min(a1.y, b1.y))
            );
        }
        cout<<ans<<'\n';
    }

    return 0;
}