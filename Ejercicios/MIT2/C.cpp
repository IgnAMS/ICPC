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
    map<ll, ll> mp;
    ll n, m; cin>>n>>m;
    vl A(n * m);
    vl F(1000001, 0);

    rep(i, n * m) {
        cin>>A[i];
        if(!mp.count(A[i])) mp[A[i]] = 0;
        mp[A[i]]++;
    }
    

    repx(i, 1, n + 1) {
        ll x = i, d = 0;
        string ans = "";
        for(auto& [num, freq]: mp) {
            ll digitos = freq / x;

            rep(j, min(m - d, digitos)) cout<<num<<' ';
            d += digitos;
            if(d >= m) break;
            
            x -= freq - digitos * x;
        }
        cout<<'\n';
    }


    return 0;
}