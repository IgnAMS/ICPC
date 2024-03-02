#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define ar array
#define rep(i, n) for(int i = 0; i<(int)n; ++i)
#define x first
#define y second
#define int ll

const int mxN = 2e5+5, M = 1e9+7;
int a[mxN], pref[mxN], suff[mxN];

signed main(){
#ifdef _DEBUG
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", " w", stdout);
#endif
    std::ios_base::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

    int n;
    cin >> n;
    memset(pref, 0, sizeof(pref));
    memset(suff, 0, sizeof(suff));
    rep(i, n) cin >> a[i];

    if(n == 1){
        cout << "YES\n1\n1\n";
        return 0;
    }
    if(n == 2){
        cout << "NO\n";
        return 0;
    }
    for(int i = 1; i<n; ++i){
        pref[i] = pref[i-1] + (a[i]-a[i-1])*i;
    }
    for(int i = n-2; i>=0; --i){
        suff[i] = suff[i+1] + (a[i+1]-a[i])*(n-1-i);
    }
    vector<int> ans;
    for(int i = 1; i<n-1; ++i){
        if(pref[i] == suff[i]){
            ans.push_back(i);
        }
    }
    if(ans.size()){
        cout << "YES\n" << ans.size() << "\n";
        for(int i = 0; i<ans.size(); ++i){
            cout << ans[i]+1;
            if(i != ans.size()-1) cout << " ";
        }
        cout << "\n";
    }else{
        cout << "NO\n";
    }
}