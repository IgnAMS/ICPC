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
//  g++ -O2 D.cpp && time ./a.out < input.txt > output.txt

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll t; cin>>t;
    while(t--) {
        ll n; cin>>n;
        if(__builtin_popcountll(n) == 1) {
            cout<<"-1\n";
            continue;
        }
        ll x = n;
        while(x % 2 == 0) x /= 2;
        cout<<min(x, 2 * n / x)<<'\n';
    }


    return 0;
}