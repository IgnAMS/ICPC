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
    int n; cin>>n;
    vi A(n); rep(i, n) cin>>A[i];
    vector<set<ll>> P(22); 
    rep(i, n) rep(j, 21) if(A[i] & (1 << j)) P[j].insert(i);
    rep(i, n) {
        rep(j, 22) if(!(A[i] & (1 << j)) and !P[j].empty()) {
            A[i] += (1 << j), 
            A[*P[j].begin()] -= (1 << j);
            P[j].erase(P[j].begin());
            P[j].insert(i);
        }
    }
    // rep(i, n) cout<<A[i]<<' '; cout<<'\n';
    ll ans = 0;
    rep(i, n) ans += A[i] * A[i];
    cout<<ans<<'\n';

    return 0;
}