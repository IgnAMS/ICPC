#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma") // could make sigill runtime error
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
        int n; cin>>n;
        vl A(n); rep(i, n) cin>>A[i];
        vl B;
        ll curr = 0;
        rep(i, n) {
            ll curr = 0;
            while(i < n and curr * A[i] >= 0) curr += A[i], i++;
            i--;
            B.pb(curr);
        }
        int n2 = B.size();
        vl C(n2 / 2 + (n2 % 2), 0); 
        rep(i, n2 / 2) {
            C[i] = max(0LL, B[2 * i] + B[2 * i + 1]);
        }
        if(n2 % 2) C.back() = B.back();

        vl Crev(C.size());
        Crev.back() = C.back();
        for(int i = C.size() - 2; i >= 0; i--) Crev[i] = C[i] + Crev[i + 1]; 
        ll ans = 0;
        ll bestk = 0;
        curr = 0;
        // rep(i, n2/2 + (n2%2)) cout<<Crev[i]<<' '; cout<<'\n';
        rep(i, n2 / 2 + (n2 % 2)) {
            // cout<<curr<<' '<<B[2 * i]<<' '<<Crev[i]<<'\n';
            if(i + 1 < n2/2 + (n2%2) and curr + B[2 * i] + Crev[i + 1] >= ans) {
                ans = curr + B[2 * i] + Crev[i + 1];
                bestk = curr + B[2 * i];
            }
            else if(i + 1  == n2/2 + (n2%2) and curr + B[2 * i] >= ans) {
                ans = curr + B[2 * i];
                bestk = curr + B[2 * i];
            }
            curr += B[2 * i] + B[2 * i + 1];
        }
        cout<<bestk<<'\n';
    }

    return 0;
}