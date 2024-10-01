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
        ll n; cin>>n;
        vl A(n); rep(i, n) cin>>A[i];
        ll shelf = 0;
        ll impares = 0;
        ll suma = 0;
        rep(i, n) {
            ll prev = impares;
            if(A[i] % 2 == 1) impares += 1;
            suma += (A[i] - (A[i] & 1));
            // cout<<"impares: "<<impares<<' '<<(impares - 2) % 3<<'\n';
            if(prev != impares and impares >= 2 and (impares - 2) % 3 == 0) {
                // cout<<"entre en "<<i<<'\n';
                suma += 2; 
            }
            if(i == 0) cout<<A[0]<<' ';
            else cout<<suma<<' ';
        }
        cout<<'\n';

    }





    return 0;
}