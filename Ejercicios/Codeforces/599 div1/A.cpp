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
    ll n; cin>>n;
    // quiero obtener los divisores de n 
    vl D;
    for(ll i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            D.pb(i);
            if(i != n / i) D.pb(n / i);
        }
    }

    if(D.size() == 0) {
        cout<<n<<'\n';
    }
    else {
        ll g = D[0];
        for(auto u: D) g = __gcd(g, u);
        cout<<g<<'\n';
    }

    return 0;
}