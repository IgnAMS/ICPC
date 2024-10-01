#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<int,int> ii;
typedef double db;
typedef vector<ll> vi;
#define ff first
#define ss second
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
//  g++ -O2 C.cpp && time ./a.out < input.txt > output.txt

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n, l, k; cin>>n>>l>>k;
    vi X(n+1); rep(i, n) cin>>X[i]; X[n] = l;
    vi V(n); rep(i, n) cin>>V[i];
    ll ans = 0;
    rep(i, n) ans += (X[i+1] - X[i]) * V[i];
    vi L(n), R(n); 
    rep(i, n) L[i] = i-1;
    rep(i, n) R[i] = i+1;
    rep(i, k){
        int x = 0;
        ll mini = 0;
        ll id = -1;
        while(x != n){
            if(x == 0) { x = R[x]; continue; }
            // cout<<X[R[x]] - X[x]<<' '<<V[L[x]] - V[x]<<'\n';
            if((X[R[x]] - X[x]) * (V[L[x]] - V[x]) < mini){
                mini = (X[R[x]] - X[x]) * (V[L[x]] - V[x]);
                id = x;
            }
            x = R[x];
        }
        if(id != -1) {
            ans += mini;
            R[L[id]] = R[id];
        }
        cout<<id<<' '<<ans<<'\n';
    }
    cout<<ans<<'\n';





    return 0;
}