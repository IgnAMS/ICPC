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
        vl F(30, 0);
        rep(i, n) rep(b, 30) if(A[i] & (1<<b)) F[b]++;
        
        // rep(b, 30) cout<<F[b]<<' '; cout<<'\n';

        repx(i, 1, n + 1) {
            bool pos = 1;
            rep(b, 30) if(F[b] % i != 0) pos = 0;
            if(pos) cout<<i<<' ';
        }
        cout<<'\n';
    }





    return 0;
}