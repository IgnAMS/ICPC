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
    int t; cin>>t;
    while(t--) {
        ll n, x; cin>>n>>x;
        ll ans = 0;
        repx(a, 1, min(n, x) + 1) {
            for(int b = 1; b <= n / a and b <= x - a; b++) {
                // a * b <= n
                // c * (a + b) <= n - a * b
                // c <= (n - a * b) / (a + b)
                // c <= x - a - b
                ans += min(x - a - b, (n - a * b) / (a + b));
            }
        }
        cout<<ans<<'\n';
    }


    return 0;
}