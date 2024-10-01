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
        ll n, k; cin>>n>>k; 
        vl C(n + 1, 0);
        vl A(n); 
        rep(i, n) {
            cin>>A[i];
            C[A[i]] = 1;
        }
        ll falta = 0;
        rep(i, n + 1) if(C[i] == 0) falta = i;
        A.pb(falta);
        ll offset = (-(k % (n + 1)) + (n + 1)) % (n + 1); 
        rep(i, n) {
            cout<<A[(i + offset) % (n + 1)]<<' '; 
        }
        cout<<'\n';
    }





    return 0;
}