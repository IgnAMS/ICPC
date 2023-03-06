#include <bits/stdc++.h>
using namespace std;
 
#define ll long long 
#define ar array
#define rep(i, n) for(int i = 0; i<(int)n; ++i)

const int mxN = 305, M = 1e9+7;

void solve(){
    vector<ll> f;
    ll n;
    cin >> n;
    for(ll i = 1; i*i<=n; ++i){
        if(n%i != 0) continue;
        f.push_back(i);
        if(i*i != n){
            f.push_back(n/i);
        }
    }
    sort(f.begin(), f.end());
    
    ll sum = 0;
    ll cur = 1;
    for(int i = 0; i<f.size(); ++i){
        
        if(f[i] != cur && sum<f[i] && f[i]!=sum+1){
            break; 
        }
        cur++; 
        sum += f[i]; 
    }
    if(sum+1 >= n){
        cout << "Yes\n";
    }else{
        cout << "No\n";
    }
}

int main(){
#ifdef _DEBUG
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    std::ios_base::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);
    
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}