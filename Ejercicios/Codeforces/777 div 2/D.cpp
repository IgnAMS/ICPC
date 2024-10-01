#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(ll i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<ll, ll> ii;
typedef double db;
typedef vector<ll> vi;
#define ff first
#define ss second
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
//  g++ -O2 D.cpp && time ./a.out < input.txt > output.txt


ll div(ll x) {
    for(ll d = 2; d * d <= x; d++) {
        if(x % d == 0) return d;
    }
    return x;
}



int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) {
        ll x, d; cin>>x>>d;
        if(x % (d * d) == 0) {
            ll p = div(d);
            if(p == d) {
                while(x % d == 0) x /= d; // saco todo
                ll q = div(x);
                if(q == 1 or q == x) { // q es primo o 1
                    cout<<"NO\n";
                }
                else {
                    cout<<"YES\n";
                }
            }
            else {
                ll aux = d, exp = 0;
                while(aux % p == 0) aux /= p, exp++;
                if(aux == 1 and exp == 2) { // d == p * p
                    ll r = x / (d * d);
                    ll q = div(r);
                    if(q == 1 or r == q or r == p * p * p) {
                         cout<<"NO\n";
                    }
                    else {
                        cout<<"YES\n";
                    }
                }
                else { // d != p * p
                    ll r = x / (d * d);
                    ll q = div(r);
                    if(q == 1 or q == r) {
                        cout<<"NO\n";
                    }
                    else {
                        cout<<"YES\n";
                    }
                }
            }
        } 
        else {
            cout<<"NO\n";
        }


    return 0;
}