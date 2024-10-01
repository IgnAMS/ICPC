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
        int n; cin>>n;
        vl A(n); rep(i, n) cin>>A[i];
        rep(i, n) A[i] = -A[i];
        ll curr = 0, last = 0;
        ll best = 0, bestL = 0;
        rep(i, n) {
            curr += A[i];
            if(curr < 0) {
                curr = 0;
                last = i + 1;
            }
            if(curr > best) best = curr, bestL = last;
        }
        ll ans = 0;
        rep(i, bestL) ans -= A[i];
        cout<<ans<<'\n';
    }

    return 0;
}