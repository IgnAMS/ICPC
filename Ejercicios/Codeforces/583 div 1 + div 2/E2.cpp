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
    vector<ii> D(n); rep(i, n) { cin>>D[i].ff; D[i].ss = i + 1; }
    sort(D.begin(), D.end());
    reverse(D.begin(), D.end());
    vector<ii> Ans;
    vi L;
    repx(i, 1, n) Ans.push_back(ii(2 * i - 1, 2 * i + 1));
    rep(i, n) L.push_back(2 * i + 1);
    rep(i, n) {
        Ans.push_back(ii(2 * (i + 1), L[D[i].ff + i - 1]));
        if(D[i].ff + i - 1 == L.size() - 1) L.push_back(2 * (i + 1));
    }
    map<int, int> mp;
    rep(i, n) mp[i] = D[i].ss;
    rep(i, 2 * n - 1) {
        // cerr<<Ans[i].ff<<' '<<(Ans[i].ff - 1) / 2<<' '<<mp[(Ans[i].ff - 1) / 2]<<'\n';
        ll x = 2 * mp[(Ans[i].ff - 1) / 2] - (Ans[i].ff & 1);
        ll y = 2 * mp[(Ans[i].ss - 1) / 2] - (Ans[i].ss & 1);
        cout<<x<<' '<<y<<'\n';
    }
    // for(auto [a, b]: Ans) cout<<a<<' '<<b<<'\n';

    return 0;
}