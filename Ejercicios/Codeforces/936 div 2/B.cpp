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

const ll MOD = 1e9+7;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) {
        int n, k; 
        cin>>n>>k;
        
        ll sum = 0, mx = 0, curr = 0;
        vl A(n);
        rep(i, n) {
            cin>>A[i];
            sum += A[i];
            curr += A[i];
            if(curr < 0) curr = 0;
            mx = max(mx, curr);
        }
        // cout<<sum<<' '<<mx<<'\n';

        ll ans = (sum % MOD + MOD) % MOD;
        
        mx %= MOD;
        rep(_, k) {
            ans += mx;
            ans %= MOD;
            // if(ans >= MOD) ans -= MOD;

            mx += mx;
            // if(mx >= MOD) mx -= MOD;
            mx %= MOD;
        }
        cout<<ans<<'\n';

    }

    return 0;
}