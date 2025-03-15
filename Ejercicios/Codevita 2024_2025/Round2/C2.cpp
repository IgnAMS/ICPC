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

pll change_direction(pll &dir, string instruction) {
    if(instruction == "straight") return dir;
    if(instruction == "back") return pll(-dir.ff, -dir.ss);

    if(dir.ff != 0) {
        if(instruction == "right") return pll(-dir.ss, -dir.ff);
        return pll(dir.ss, dir.ff);
    }
    // dir.ss != 0
    if(instruction == "right") return pll(dir.ss, dir.ff);
    return pll(-dir.ss, -dir.ff);
}

const string pos[] = {"right", "straight", "left", "back"};
unordered_map<string, int> mp = {{"right", 0}, {"straight", 1}, {"left", 2}, {"back", 3}};
pair<string, ll> E[10010];


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    rep(i, n) {
        cin>>E[i].ff>>E[i].ss;
    }

    pll init; cin>>init.ff>>init.ss;
    pll target; cin>>target.ff>>target.ss;

    pll final = init;
    pll in_dir = {0, 1};

    rep(i, n) {
        in_dir = change_direction(in_dir, E[i].ff);
        final.ff += E[i].ss * in_dir.ff;
        final.ss += E[i].ss * in_dir.ss;
    }

    
    pll curr = init;
    pll dir = {0, 1};
    rep(i, n) {
        // cout<<"termino el primer prefijo "<<i<<" en "<<"("<<curr.ff<<", "<<curr.ss<<")"<<" \n";
        pll dif = {final.ff - curr.ff, final.ss - curr.ss};
        rep(k, 4) {
            if(curr.ff + dif.ff == target.ff and curr.ss + dif.ss == target.ss) {
                cout<<"Yes\n";
                cout<<E[i].ff<<" "<<E[i].ss<<'\n';
                ll xd = mp[E[i].ff] + k >= 4? mp[E[i].ff] + k - 4 : mp[E[i].ff] + k;
                cout<<pos[xd]<<' '<<E[i].ss<<'\n'; 
                return 0;
            }
            dif = pll(-dif.ss, dif.ff);
        }
        dir = change_direction(dir, E[i].ff);
        curr.ff += dir.ff * E[i].ss;
        curr.ss += dir.ss * E[i].ss;
    }
    cout<<"No\n";



    return 0;
}