#include<bits/stdc++.h>
using namespace std;
#define repx(i, a, b) for(int i = a; i < b; i++)
#define rep(i, n) repx(i, 0, n)
typedef long long ll;
typedef vector<ll> vl;


void solve(){
    int n;
    cin >> n;
    int a[n];
    rep(i, n){
        cin >> a[i], --a[i];
    }
    vector<pair<int, int>> ans;
    int it = n/2;
    while(it--){
        bool chk = true;
        int ff = 0;
        rep(i, n){
            if(a[i] != i){
                chk = false;
                ff = i;
                break;
            }
        }

        if(chk){
            break;
        }
        int ff2 = 0;
        for(int i = n-1; i>ff; --i){
            if(a[ff] > a[i]){
                ff2 = i;
                break;
            }
        }
        if(ff > ff2) swap(ff, ff2);
        // cout << " pos " << ff <<  " " << ff2 << "\n";
        ans.push_back({ff, ff2});
        sort(a+ff, a+ff2+1);
    }
    cout << ans.size() << "\n";
    rep(i, ans.size()){
        cout << ans[i].first+1 << " " << ans[i].second+1 << "\n";
    }
}

int main() {    
    ios::sync_with_stdio(0); cin.tie(0);
    
    int t;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}

