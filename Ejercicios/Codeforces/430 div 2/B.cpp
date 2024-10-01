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
    ll r, d; cin>>r>>d;
    ll n; cin>>n;
    vi X(n), Y(n), R(n); rep(i, n) cin>>X[i]>>Y[i]>>R[i];
    ll ans = 0;
    rep(i, n) {
        if(sqrt(X[i] * X[i] + Y[i] * Y[i]) - R[i] + 1e-6 >= r - d and
            sqrt(X[i] * X[i] + Y[i] * Y[i]) + R[i] <= r + 1e-6) ans++; 
    }
    cout<<ans<<'\n';

    return 0;
}