#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;
#define rep(i, n) for(int i = 0; i < n; i++)
#define repx(i, a, b) for(int i = a; i < b; i++)
#define pb push_back

void solve(){
    int n;
    cin >> n;
    vector<int> a(n), freq(n, 0);
    vector<int> v;
    int mn = 1e9;
    rep(i, n){
        cin >> a[i], --a[i];
        freq[a[i]]++;
    }
    rep(i, n){
        if(freq[i]) v.push_back(freq[i]);
    }
    rep(i, n){
        mn = min(mn, freq[a[i]]+1);
    }
    int ans = 1e9;
    for(int s = 2; s<=mn; ++s){ 
        int cnt = 0;
        bool can = true;
        for(int i = 0; i<v.size(); ++i){
            int cnt2 = 1e9;
            bool can2 = false;
            for(int x = 0; x<=v[i]/s; ++x){
                if((v[i] - (x*s)) % (s-1) == 0){
                    cnt2 = min(cnt2, x+((v[i]-(x*s))/(s-1)));
                    can2 = true;
                }
            }
            can &= can2;
            cnt += cnt2;
        }
        if(can){
            ans = min(ans, cnt);
        }
        // if(v[i] % s < s - 1 - (v[i]/s)) {
        //     ans += 
        // }
    }
    cout << ans << "\n";
}

int main() {
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}