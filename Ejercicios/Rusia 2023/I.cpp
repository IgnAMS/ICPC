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
    int n; cin>>n;
    vl A(n, -1);
    repx(i, 1, n + 1) {
        ll curr = 0;
        // cerr<<"iteracion "<<i<<'\n';
        while(curr < n and A[curr] != -1) {
            if(A[curr] / i == 0) {
                // cerr<<"TROLEO\n";
                // cerr<<curr<<' '<<i<<' '<<A[curr]<<'\n';
                return 0;
            }
            curr += A[curr] / i;
        }
        if(curr > n) {
            // cerr<<"TROLEO\n";
            return 0;
        }
        if(curr == n) continue;
        // cerr<<"seteo "<<curr<<" con "<<(n - curr) * i<<'\n';
        A[curr] = (n - curr) * i + i - 1;
    }
    rep(i, n) cout<<(A[i] == -1? 1: A[i])<<' '; cout<<'\n';
    
    return 0;
}