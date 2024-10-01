#pragma GCC optimize("Ofast")
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
//  g++ -O2 D.cpp && time ./a.out < input.txt > output.txt

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, l, r, x; cin>>n>>l>>r>>x;
    vi A(n); rep(i, n) cin>>A[i];
    ll ans = 0;
    rep(i, (1<<n)) {
        ll suma = 0;
        ll mn = 1000000, mx = 0;
        rep(j, n) if(i & (1 << j)) {
            suma += A[j];
            mn = min(mn, A[j]), mx = max(mx, A[j]);
        }
        if(l <= suma and suma <= r and mx - mn >= x) ans++;
    }
    cout<<ans<<'\n';





    return 0;
}