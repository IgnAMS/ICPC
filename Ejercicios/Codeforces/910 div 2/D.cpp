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

int rand_num(int n) {
    ll num = 0;
    rep(i, 5) {
        num = num * 10 + (rand() % 10);
    }
    return num % n;
}


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        ll A[n], B[n], D[n]; 
        rep(i, n) cin>>A[i];
        rep(i, n) cin>>B[i];
        rep(i, n) D[i] = abs(A[i] - B[i]);
        
        ll suma = 0;
        rep(i, n) suma += D[i];
        // cout<<suma<<'\n';

        ll best[4];
        rep(i, 4) best[i] = -1e15;
        ll ans = suma;
        
        rep(i, n) {            
            best[0] = max(best[0], A[i] + B[i] - D[i]);
            best[1] = max(best[1], A[i] - B[i] - D[i]);
            best[2] = max(best[2], -A[i] - B[i] - D[i]);
            best[3] = max(best[3], -A[i] + B[i] - D[i]);
            
            ll x = suma + max({
                    best[0] - A[i] - B[i] - D[i],
                    best[1] + A[i] - B[i] - D[i],
                    best[2] + A[i] + B[i] - D[i],
                    best[3] - A[i] + B[i] - D[i]
            });
            ans = max(ans, x);

            // cout<<best[0] - A[i] - B[i] - D[i]<<' '<<best[1] + A[i] - B[i] - D[i]<<' '<<best[2] + A[i] + B[i] - D[i]<<' '<<best[3] - A[i] + B[i] - D[i]<<'\n';
            // cout<<best[0]<<' '<<best[1]<<' '<<best[2]<<' '<<best[3]<<'\n';
        }
        
        cout<<ans<<'\n';
    }


    return 0;
}