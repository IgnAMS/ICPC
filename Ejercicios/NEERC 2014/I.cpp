#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef vector<ll> vl;
#define ff first
#define ss second
#define repx(i, a, b) for(int i = (int)a; i < (int)b; i++)
#define rep(i, n) repx(i, 0, n)
#define pb push_back

void solve(){
    int n;
    cin >> n;
    multiset<int> ms;
    rep(i, n){
        int x;
        cin >> x;
        ms.insert(x);
    }
    ll f = *ms.rbegin();
    ms.erase(ms.find(*ms.rbegin()));
    int ans = 1;
    while(ms.size() && f >= *ms.begin()){
        f -= *ms.begin();
        ms.erase(ms.find(*ms.begin()));
        ans++;
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
}

