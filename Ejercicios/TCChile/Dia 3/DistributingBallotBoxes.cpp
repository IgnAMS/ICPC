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
    int n, b;
    while(cin>>n>>b and n != -1) {
        ll l = 0, r = 0;
        vl A(n); 
        rep(i, n) { 
            cin>>A[i]; 
            r = max(r, A[i]);
        }
        while(l < r) {
            ll m = (l + r) / 2;
            ll suma = 0;
            rep(i, n) {
                suma += (A[i] + m - 1) / m;
            }
            if(suma <= b) r = m;
            else l = m + 1;
        }
        cout<<l<<'\n';
    }


    return 0;
}