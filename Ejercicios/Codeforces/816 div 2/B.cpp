#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<ll, ll> ii;
typedef double db;
typedef vector<ll> vi;
#define ff first
#define ss second
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
// g++ -O2 D.cpp && time ./a.out <input.txt> output.txt

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll t; cin>>t;
    while(t--) {
        ll n, k, b, s; cin>>n>>k>>b>>s;
        if(b * k > s or (k - 1) * n + b * k < s) cout<<"-1\n";
        else {
            ll rest = s - b * k;
            vi A(n);
            rep(i, n) {
                ll aux = min(rest, k - 1);
                A[i] = min(rest, aux);
                rest -= aux;
            }
            A[n - 1] += b * k;
            rep(i, n) cout<<A[i]<<' '; cout<<'\n';
        }


    }


    return 0;
}