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
    srand(time(0));
    while(t--) {
        int n, m; cin>>n>>m;
        vector<vl> Friends(m, vl());
        vl Cont(n, 0);
        vl Spawn(n, 0);
        ll Assign[m];
        bool pos = 1;
        rep(i, m) {
            ll k; cin>>k;
            Friends[i].resize(k);
            rep(j, k) {
                cin>>Friends[i][j];
                Friends[i][j]--;
                Spawn[Friends[i][j]]++;
            }
        }
        
        vl Ind(m);
        rep(i, m) Ind[i] = i;
        random_shuffle(Ind.begin(), Ind.end());
        sort(Ind.begin(), Ind.end(), [&Friends](const ll& a, const ll& b){
            return Friends[a].size() < Friends[b].size();
        });
        rep(i, m) {
            random_shuffle(Friends[Ind[i]].begin(), Friends[Ind[i]].end());
            ll mn = Friends[Ind[i]][0];
            for(auto f: Friends[Ind[i]]) {
                if(Cont[f] < Cont[mn]) mn = f;
            }
            Cont[mn]++;
            Assign[Ind[i]] = mn;
            if(Cont[mn] >= (m + 1) / 2) pos = 0;
        }
        if(!pos) cout<<"NO\n";
        else {
            cout<<"YES\n";
            rep(i, m) cout<<Assign[i] + 1<<' '; cout<<'\n';
        }
    }
    // Cuando si se puede resolver -> (m - 1) / 2, (m - 1) / 2, 2
    // Necesito al menos  

    return 0;
}