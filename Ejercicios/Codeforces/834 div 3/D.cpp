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
    int t; cin>>t;
    while(t--) {
        ll n, k; cin>>n>>k;
        ll k_2 = 1, k_5;
        ll mx = 1, mx_ceros = -1;
        ll ans = 0;
        rep(i, 31) {
            k_5 = 1;
            rep(j, 14) {
                if(k_5 * k_2 <= k)  {
                    // cout<<k_5 * k_2<<'\n';
                    ll ceros = 0;
                    ll actual = (k / (k_2 * k_5)) * k_2 * k_5 * n;
                    ll aux = actual;
                    while(aux % 10 == 0) ceros++, aux /= 10;
                    if(ceros > mx_ceros) mx_ceros = ceros, mx = actual;
                    if(ceros == mx_ceros and actual > mx) mx = actual;
                }
                k_5 *= 5;
            }
            k_2 *= 2;
        }
        cout<<mx<<'\n';

    }





    return 0;
}