#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<ll, ll> ii;
typedef double db;
typedef vector<ll> vi;
#define ff first
#define ss second
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
// ulimit -s 1000000
// g++ -O2 D.cpp && time ./a.out <input.txt> output.txt

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    vi ind(n, 0), outd(n, 0);
    vector<vi> G(n, vi()), invG(n, vi());
    repx(i, 1, n) {
        string s; cin>>s;
        rep(j, i) {
            if(s[j] == '1') {
                G[i].push_back(j);
                outd[i]++;
                ind[j]++;
            }
            else {
                G[j].push_back(i);
                outd[j]++;
                ind[i]++;
            }
        }
    }
    // rep(i, n) cout<<ind[i]<<' '; cout<<'\n';
    // rep(i, n) cout<<outd[i]<<' '; cout<<'\n';
    
    vi Pos(n, 1);
    ll ans = 0, suma = 0;
    // rep(t, n) {
    //     pair<ll,ll> mn = {1e9, 0};
    //     ll mnind = -1;
    //     rep(i, n) if(Pos[i] == 1 and (mn.ff > ind[i] or (ind[i] == mn.ff and outd[i] > mn.ss))) {
    //         // cout<<outd[i]<<'\n';
    //         mn = {ind[i], outd[i]};
    //         mnind = i;
    //     }
    //     cout<<"consumo a "<<mnind<<'\n';
    //     ans = max(ans, mn.ff);
    //     Pos[mnind] = 0;
    //     for(auto v: G[mnind]) ind[v]--;
    //     for(auto v: invG[mnind]) outd[v]--;
    // }

    rep(t, n) {
        ll mn = 1e9;
        ll mnind = -1;
        rep(i, n) if(Pos[i] == 1 and mn > outd[i]) {
            // cout<<outd[i]<<'\n';
            mn = outd[i];
            mnind = i;
        }
        suma += outd[mnind];
        // cout<<"consumo a "<<mnind<<'\n';
        // cout<<suma - t * (t + 1) / 2<<'\n';
        ans = max(ans, suma - t * (t + 1) / 2);
        // ans += suma - t * (t - 1) / 2;
        Pos[mnind] = 0;
    }
    
    cout<<ans<<'\n';

    return 0;
}