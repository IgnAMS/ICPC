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
    vector<vl> D(10, vl());
    repx(i, 1, 10) {
        ll num = i;
        D[i].pb(num);
        rep(_, 10) {
            num = num * 10LL + (ll)i;
            D[i].pb(num);
        }
    }
    
    int n; cin>>n;
    ll ans = (n < 10? 0: -1);
    ll aux = n;
    while(aux > 0) aux /= 10, ans++;
    repx(i, 1, 10) {
        ll curr = upper_bound(D[i].begin(), D[i].end(), n) - D[i].begin();
        // cout<<curr<<'\n';
        ans += curr;
    }
    cout<<ans<<'\n';



    return 0;
}