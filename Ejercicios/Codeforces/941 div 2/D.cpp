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

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) {
        ll n, k; cin>>n>>k;

        ll bmax = 0;
        vl Ans;
        ll sum = 0;
        rep(b, 20) {
            if((1<<b) > n) break;
            if((1<<b) <= k and k < (1<<(b + 1))) {
                bmax = b + 1;
                if(sum + 1 < k) Ans.pb(k - sum - 1);
                Ans.pb(k + 1);
                Ans.pb(k + (1<<(b + 1)));
            }
            else {
                Ans.pb(1<<b);
            }
            sum += (1<<b);
        }
        cout<<Ans.size()<<'\n';
        for(auto u: Ans) cout<<u<<' '; cout<<'\n';

    }

    return 0;
}