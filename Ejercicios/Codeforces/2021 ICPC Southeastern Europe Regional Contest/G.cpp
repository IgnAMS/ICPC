#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i<b; ++i);
#define invrep(i, b, a) for(int i = b; i>=a; --i);
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
#define ff first
#define ss second

int main() {
    int n; cin>>n;
    vector<ii> Mx(2 * n), Mn(2 * n);
    for(int i = 0; i < 2 * n; i++) {
        int a, b; cin>>a>>b;
        Mx[i] = ii(max(a, b), i); 
        Mn[i] = ii(min(a, b), i);
    }
    sort(Mx.begin(), Mx.end(), greater<ii>()); 
    sort(Mn.begin(), Mn.end());
    int i = 0, j = 0;
    set<ll> S;
    ll ans = 0;
    while(i < 2 * n) {
        // cout<<i<<' '<<j<<'\n';
        // cerr<<Mx[j].ff<<' '<<Mx[j].ss<<'\n';
        // cerr<<Mn[i].ff<<' '<<Mn[j].ff<<'\n';
        if(Mx[j].ss == Mn[i].ss) {
            if(abs(Mx[j].ff - Mn[i + 1].ff) <= abs(Mx[j + 1].ff - Mn[i].ff)) { // me conviene agregar mas a i
                S.insert(Mx[j + 1].ss);
                S.insert(Mn[i].ss);
                ans += abs(Mx[j + 1].ff - Mn[i].ff);
            }
            else {
                S.insert(Mx[j].ss);
                S.insert(Mn[i + 1].ss);
                ans += abs(Mx[j + 1].ff - Mn[i].ff);
            }
        }
        else {
            S.insert(Mx[j].ss);
            S.insert(Mn[i].ss);
            ans += abs(Mx[j].ff - Mn[i].ff);
        }
        // cout<<S.count(Mn[i].ss)<<'\n';
        // cout<<S.count(Mx[j].ss)<<'\n';
        while(i < 2 * n and S.count(Mn[i].ss)) i++;
        while(j < 2 * n and S.count(Mx[j].ss)) j++;
    }
    cout<<ans<<'\n';
}