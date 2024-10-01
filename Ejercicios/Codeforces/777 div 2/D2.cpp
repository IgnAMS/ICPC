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
 
 
vi Sieve(int n) {
    vector<bool> I(n + 1, 1);
    vi P;
    repx(i, 2, n) if(I[i]) {
        for(ll j = i * i; j < n; j += i) I[j] = 0;
    }
    rep(i, n) if(i > 1 and I[i]) P.push_back(i);
    return P;
}

ll div(ll x) {
    for(ll i = 2; i * i <= x; i++) {
        if(x % i == 0) return i;
    }
    return x;
}
 
 
 
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    vi P = Sieve(320000);
    int t; cin>>t;
    while(t--) {
        ll x, d; cin>>x>>d;
        if(x % (d * d) != 0) {
            cout<<"NO\n";
            continue;
        }
        x /= (d * d);
        ll px = -1;
        for(auto& p: P) {
            ll aux = d;
            while(aux % p == 0) aux /= p;
            if(aux == 1) px = p;
        }
        // cout<<x<<' '<<d<<' '<<px<<'\n';
        if(px == d) while(x % d == 0) x /= d;
        ll cont = 0;
        
        if(px * px != d) for(auto& p: P) if(x % p == 0 and x != p) cont++; 
        if(px * px == d and x != 1 and x != div(x) and x != px * px * px) cont++; // solve for d = px * px
        if(cont) cout<<"YES\n";
        else cout<<"NO\n";
    }
 
 
    return 0;
}
