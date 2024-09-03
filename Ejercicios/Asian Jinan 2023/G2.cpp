#include<bits/stdc++.h>
using namespace std;
#define repx(i, a, b) for(int i = a; i < b; i++)
#define rep(i, n) repx(i, 0, n)
typedef long long ll;
typedef vector<ll> vl;

const int M = 1e9+7, mxN = 1e6+5;

struct DSU{
    ll cc, p[mxN], sz[mxN];
    void init(int n){
        for(int i = 0; i<n; ++i){
            p[i] = i;
            sz[i] = 1;
        }
        cc = n;
    }
    int find(int x){
        if(p[x] == x) return x;
        return p[x] = find(p[x]);
    }
    void unite(int a, int b){
        a = find(a), b = find(b);
        if(a != b){
            cc--;
            if(sz[a] > sz[b]) swap(a, b);
            sz[b] += a;
            p[a] = b;
        }
    }
}dsu;

ll binpow(ll a, ll b, ll m){
    ll res = 1;
    while(b){
        if(b&1){
            res = res*a%m;
        }
        a = a*a%m;
        b >>= 1;
    }
    return res;
}

void solve(){
    int n, m;
    cin >> n >> m;
    dsu.init(n);
    vector<ll> cnt(m, 0);
    vector<string> s(n);
    map<int, vector<int>> mp;
    rep(i, n){
        cin >> s[i];
        rep(j, s[i].size()){
            if(s[i][j] == '1'){
                mp[min(j, m-1-j)].push_back(i);
            }
        }
    }
    bool bad = false;
    for(auto &[pos, vect] : mp){
        if(vect.size() >= 3){
            bad = true;
            break;
        }else if(vect.size() <= 1)  {
            continue;
        }else{
            // cout << vect[0] << " " << vect[1] << " " << pos << "\n";
            if(pos == m/2 && m%2 == 1) { bad = true; break; }
            dsu.unite(vect[1], vect[0]);
        }
    }
    if(bad){
        cout << 0 << "\n";
        return;
    }
    cout << binpow(2LL, dsu.cc, M) << "\n";
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    // cerr << "here";
    int t;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}