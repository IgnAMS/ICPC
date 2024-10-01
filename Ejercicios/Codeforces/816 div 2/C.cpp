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
// g++ -O2 D.cpp && time ./a.out <input.txt> output.txt

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n, m; cin>>n>>m;
    vi A(n); rep(i, n) A[i] = i + 1;
    ll ans = 0;
    repx(i, 1, n + 1) ans += i * (i + 1) / 2;
    // cout<<ans<<'\n';
    rep(i, n) {
        ll h; cin>>h;
        if(i and A[i] == A[i - 1] and h != A[i - 1]) {
            // cout<<"i+: "<<i<<", "<<(i)<<' '<<(n - i)<<'\n';
            ans += (i) * (n - i);
        }
        if(i < n - 1 and A[i] == A[i + 1] and h != A[i + 1]) {
            // cout<<"i+: "<<i<<", "<<(i + 1)<<' '<<(n - i - 1)<<'\n';
            ans += (i + 1) * (n - i - 1);
        }
        
        if(i and A[i] != A[i - 1] and h == A[i - 1]) {
            // cout<<"i-: "<<i<<", "<<(i) <<' '<<(n - i)<<'\n';
            ans -= (i) * (n - i);
        }
        if(i < n - 1 and A[i] != A[i + 1] and h == A[i + 1]) {
            // cout<<"i-: "<<i<<", "<<(i + 1)<<' '<<(n - i - 1)<<'\n';
            ans -= (i + 1) * (n - i - 1);
        }
        A[i] = h;
    }
    rep(j, m) {
        ll i, h; cin>>i>>h; i--;
        if(i and A[i] == A[i - 1] and h != A[i - 1]) {
            // cout<<"i+: "<<i<<", "<<(i)<<' '<<(n - i)<<'\n';
            ans += (i) * (n - i);
        }
        if(i < n - 1 and A[i] == A[i + 1] and h != A[i + 1]) {
            // cout<<"i+: "<<i<<", "<<(i + 1)<<' '<<(n - i - 1)<<'\n';
            ans += (i + 1) * (n - i - 1);
        }
        
        if(i and A[i] != A[i - 1] and h == A[i - 1]) {
            // cout<<"i-: "<<i<<", "<<(i) <<' '<<(n - i)<<'\n';
            ans -= (i) * (n - i);
        }
        if(i < n - 1 and A[i] != A[i + 1] and h == A[i + 1]) {
            // cout<<"i-: "<<i<<", "<<(i + 1)<<' '<<(n - i - 1)<<'\n';
            ans -= (i + 1) * (n - i - 1);
        }
        A[i] = h;
        cout<<ans<<'\n';
    }




    return 0;
}