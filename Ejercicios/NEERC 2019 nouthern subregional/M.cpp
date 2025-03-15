#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>

using namespace std;
#define repx(i, a, b) for(int i = a; i < b; i++)
#define rep(i, n) repx(i, 0, n)
typedef long long ll;
typedef pair<ll, ll> pll;

// g++ -O2 A.cpp && time ./a.out <input.txt> output.txt

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    // cout<<2000 * 2000 * 10<<'\n';
    while(t--) {
        int n; cin>>n;
        ll A[n]; 
        rep(i, n) cin>>A[i];
        unordered_map<ll, ll> mp;
        mp.reserve(2000);

        ll ans = 0;
        for(int j = 0; j < n; j++) {
            for(int k = j + 1; k < n; k++) {
                if(mp.count(2 * A[j] - A[k])) ans += mp[2 * A[j] - A[k]];
            }
            if(!mp.count(A[j])) mp[A[j]] = 0;
            mp[A[j]]++;
        } 
        cout<<ans<<'\n';

    }

    return 0;
}


