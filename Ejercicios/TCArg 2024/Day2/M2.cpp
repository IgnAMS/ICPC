#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<ll, ll> pll;
typedef double db;
typedef vector<ll> vl;
#define ff first
#define ss second
#define pb push_back
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
// ulimit -s 1000000
// g++ -O2 D.cpp && time ./a.out <input.txt> output.txt

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;

    while(t--) {
        int n, m; cin>>n>>m;
        vector<vl> Friends(m, vl());
        vector<vl> InvFriends(n, vl());
        vl Cont(n, 0);
        ll Assign[m];
        ll mx = 0;
        rep(i, m) {
            ll k; cin>>k;
            Friends[i].resize(k);
            rep(j, k) {
                cin>>Friends[i][j];
                Friends[i][j]--;
                InvFriends[Friends[i][j]].pb(i);
            }
            Assign[i] = Friends[i][0];
            Cont[Friends[i][0]]++;
            if(Cont[Friends[i][0]] > Cont[mx]) mx = Friends[i][0];
        }

        for(auto i: InvFriends[mx]) {
            if(Cont[mx] <= (m + 1) / 2) break;
            for(auto v: Friends[i]) if(v != mx and Cont[v] + 1 <= (m + 1) / 2) {
                Assign[i] = v;
                Cont[v]++;
                Cont[mx]--;
                break;
            }
        }
        bool pos = 1;
        rep(i, n) if(Cont[i] > (m + 1) / 2) pos = 0;

        if(!pos) {
            cout<<"NO\n";
        }
        else {
            cout<<"YES\n";
            rep(i, m) cout<<Assign[i] + 1<<' '; cout<<'\n';
        }



    }
    return 0;
}