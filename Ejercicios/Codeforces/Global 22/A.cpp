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
// g++ -O2 D.cpp && time ./a.out <input.txt> output.txt

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        vi A(n); rep(i, n) cin>>A[i];
        vi D1, D2; 
        rep(i, n) {
            ll h; cin>>h;
            if(A[i]) D1.push_back(h);
            else D2.push_back(h);
        }
        sort(D1.begin(), D1.end());
        sort(D2.begin(), D2.end());
        ll ans = 0;
        ll mn = min(int(D1.size()), int(D2.size())) - 1;
        // cerr<<D1.size()<<' '<<D2.size()<<' '<<mn<<'\n';
        rep(i, mn) { // D1.size() - mn + 1 - 1 = D1.size() - mn 
            ans += 2 * D1[D1.size() - i - 1] + 2 * D2[D2.size() - i - 1];
        }
        // cout<<D1.size()<<' '<<D2.size()<<' '<<mn<<'\n';
        if(D1.size() and D2.size() and D1.size() == D2.size()) {
            // cout<<D1[D1.size() - mn - 1]<<' '<<D2[D2.size() - mn - 1]<<'\n';
            ans += 2 * max(D1[D1.size() - mn - 1], D2[D2.size() - mn - 1]);
            ans += min(D1[D1.size() - mn - 1], D2[D2.size() - mn - 1]);
            rep(i, D1.size() - mn - 1) ans += D1[i];
            rep(i, D2.size() - mn - 1) ans += D2[i];
        }
        else if(D1.size() and D2.size() and D1.size() != D2.size()) {
            // cout<<D1[D1.size() - mn - 1]<<' '<<D2[D2.size() - mn - 1]<<'\n';
            // ans += 2 * max(D1[D1.size() - mn - 1], D2[D2.size() - mn - 1]);
            // ans += min(D1[D1.size() - mn - 1], D2[D2.size() - mn - 1]);
            ans += 2 * D1[D1.size() - mn - 1] + 2 * D2[D2.size() - mn - 1];
            rep(i, D1.size() - mn - 1) ans += D1[i];
            rep(i, D2.size() - mn - 1) ans += D2[i];
        }
        else {

            rep(i, D1.size()) ans += D1[i];
            rep(i, D2.size()) ans += D2[i];
        }
        cout<<ans<<'\n';
    }




    return 0;
}