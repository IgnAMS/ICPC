#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef vector<ll> vl;
typedef pair<ll, ll> pll;
#define ff first
#define ss second
#define repx(i, a, b) for(int i = (int)a; i < (int)b; i++)
#define rep(i, n) repx(i, 0, n)
#define pb push_back


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll n, k, mod;
    cin >> k >> n;
    mod = k / n;

    vl F(n + 1, 0);
    vl C1(k);
    rep(i, k) { 
        cin>>C1[i];
        if(C1[i] == -1) C1[i] = 1;
        F[C1[i]]++;
    }
    
    set<pll> S;
    repx(i, 1, n + 1) if(F[i] > 0) S.insert({F[i], i});


    vector<vl> C2(n + 1, vl(n + 1, 0));
    while(!S.empty()) {
        auto [x, i] = *S.begin();
        // cerr<<"entre con "<<x<<' '<<i<<'\n';
        S.erase(S.begin());
        if(x % mod == 0) {
            // Debo pintar estos de dos colores arbitarios 
            C2[i][1] += x;
            continue;
        }

        auto it = S.lower_bound({mod - (x % mod), 0});
        
        // y >= mod - (x % mod)
        auto [y, j] = *it;
        S.erase(*it);
        C2[i][j] += x;
        C2[j][i] += mod - (x % mod);
        if(y > mod - (x  % mod)) S.insert({y - mod + (x % mod), j});
    }
    
    cout<<"Yes\n";
    rep(i, k) {
        // cout<<"veo el indice "<<i<<' '<<C1[i]<<'\n';
        repx(c2, 1, n + 1) {
            if(C2[C1[i]][c2] > 0) {
                C2[C1[i]][c2]--;
                cout<<C1[i]<<' '<<c2<<'\n';
                break;
            }
        }
    }
    
   return 0;
}

