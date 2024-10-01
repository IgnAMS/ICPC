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
    int t; cin>>t;
    while(t--) {
        ll n, x; cin>>n>>x;
        vi A(n); rep(i, n) cin>>A[i];
        ll mn = 1000000, mx = 0;
    
        rep(i, n) mn = min(mn, A[i]), mx = max(mx, A[i]);
        ll ans = 0;
        repx(i, 1, n) ans += abs(A[i] - A[i - 1]);
        if(1 < mn) ans += min({2 * (mn - 1), A[0] - 1, A[n - 1] - 1});
        if(x > mx) ans += min({2 * (x - mx), x - A[0], x - A[n - 1]});
        cout<<ans<<'\n';
    }

    return 0;
}