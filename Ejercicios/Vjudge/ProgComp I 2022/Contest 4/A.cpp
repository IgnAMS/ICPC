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

ll n; 
vi C, H;
ll f(ll m) {
    ll cost = 0;
    rep(i, n) cost += abs(H[i] - m) * C[i];
    return cost;
}

ll min_search(ll l, ll r) { // convex function
    while (l < r) {
        ll m = (l + r) / 2;
        if (f(m + 1) >= f(m)) r = m;
        else l = m + 1;
    }
    return f(l);
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) {
        cin>>n;
        H.assign(n, 0); C.assign(n, 0);
        rep(i, n) cin>>H[i];
        rep(i, n) cin>>C[i];
        cout<<min_search(0, 10001)<<'\n';
    }


    return 0;
}