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
        ll aux = (1LL<<8) + 1;
        vl B(aux, 0);
        ll curr = 0;
        B[0] = 1;
        ll ans = 0;
        rep(i, n) {
            curr ^= A[i];
            B[curr] = 1;
            rep(j, aux) if(B[j]) ans = max(ans, curr ^ j);
        }
        cout<<ans<<'\n';
    
    }



    return 0;
}