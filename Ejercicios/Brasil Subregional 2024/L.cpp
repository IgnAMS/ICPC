#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef pair<ll, ll> pll;
#define repx(i, a, b) for(int i = a; i < b; i++)
#define rep(i, n) repx(i, 0, n)

void solve(){
    int n;
    cin >> n;
    vector<int> freq(36, 0);
    rep(i, n){
        ll x;
        cin >> x;
        rep(bit, 36){
            if(x & (1LL<<bit)){
                freq[bit]++;
            }
        }
    }
    rep(i, n){
        ll num = 0;
        rep(bit, 36){
            if(freq[bit]){
                freq[bit]--;
                num += (1<<bit);
            }
        }
        cout << num << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    
    solve();

    return 0;
}