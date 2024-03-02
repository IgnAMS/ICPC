#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define ar array
#define rep(i, n) for(int i = 0; i<(int)n; ++i)
#define x first
#define y second

const int mxN = 2e5+5, M = 1e9+7;

void solve(){
    pair<ll, ll> a1, a2, b1, b2;
    cin >> a1.x >> a1.y >> a2.x >> a2.y;
    cin >> b1.x >> b1.y >> b2.x >> b2.y;
    ll ans = max((a2.x-a1.x)*(a2.y-a1.y), (b2.x-b1.x)*(b2.y-b1.y));
    //cout << "\n";
    if(min(a2.x, b2.x) >= max(a1.x, b1.x)){
        //cout << "1 : " << (min(a2.y, b2.y)-max(a1.y, b1.y)) << " " << (max(a2.x, b2.x) - min(a1.x, b1.x)) << "\n";
        ans = max(ans, (min(a2.y, b2.y)-max(a1.y, b1.y)) * (max(a2.x, b2.x) - min(a1.x, b1.x)));
    }
    if(min(a2.y, b2.y) >= max(a1.y, b1.y)){
        //cout << "2 : " << (min(a2.x, b2.x) - max(a1.x, b1.x)) << " " << (max(a2.y, b2.y) - min(a1.y, b1.y)) << "\n";
        ans = max(ans, (min(a2.x, b2.x) - max(a1.x, b1.x)) * (max(a2.y, b2.y) - min(a1.y, b1.y)));
    }
    cout << ans << "\n";
}

int main(){
#ifdef _DEBUG
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", " w", stdout);
#endif
    std::ios_base::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        solve();
    }
    
}