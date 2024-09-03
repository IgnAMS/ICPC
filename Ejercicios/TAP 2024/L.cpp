#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef double db;
#define repx(i, a, b) for(int i = a; i < b; i++)
#define rep(i, n) repx(i, 0, n)
#define pb push_back

const int mxN = 2e5+5;
ll pref1[mxN], pref2[mxN], prefones[mxN];

void solve(){
    int n, q;
    cin >> n >> q;
    vector<ll> a(n);
    memset(pref1, 0, sizeof(pref1));
    memset(pref2, 0, sizeof(pref2));
    memset(prefones, 0, sizeof(prefones));
    rep(i, n){
        cin >> a[i];
        if(__builtin_popcount(a[i]) == 1 && a[i] != 1){
            pref1[i] = a[i];
        }
        if(a[i]%2 == 1 && a[i] != 1){
            pref2[i] = a[i];
        }
        if(a[i] == 1){
            prefones[i] = 1;
        }
        if(i){
            pref1[i] += pref1[i-1];
            pref2[i] += pref2[i-1];
            prefones[i] += prefones[i-1];
        }
    }
    while(q--){
        int l, r;
        cin >> l >> r, --l, --r;
        ll ans1 = pref1[r] - (l == 0 ? 0 : pref1[l-1]);
        ll ans2 = pref2[r] - (l == 0 ? 0 : pref2[l-1]);
        ll cntones = prefones[r] - (l == 0 ? 0 : prefones[l-1]);
        ans1 += (cntones+1)/2;
        ans2 += cntones/2;
        if(ans1 == ans2){
            cout << "E\n";
        }else if(ans1 > ans2){
            cout << "A\n";
        }else{
            cout << "B\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    solve();


    return 0;
}

