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
        ll n, m, k; cin>>n>>m>>k;
        if(k == 1) {
            cout<<"1\n";
        }
        else if(k == 2) {
            ll ans = min(n, m) + (m / n) - (m >= n);
            cout<<ans<<'\n';
        }
        else if(k == 3) {
            // m = n -> n - 1 - n + 1 = 0
            // m > n -> m - n - (m / n) + 1 >= 0
            // No multiplos de n y valores mayores a n
            ll ans = max(0LL, m - (m / n) - n + 1);
            cout<<ans<<'\n';
        }
        else cout<<"0\n";

    }


    return 0;
}