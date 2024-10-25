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

map<string, ll> mp;
map<ll, string> invmp;
vl G[400010];
string P;
int N;

void dfs(int u) {
    while(G[u].size()) {
        int v = G[u].back();
        G[u].pop_back();
        dfs(v);
    }
    P.pb(invmp[u][1]);
}

bool euler_path() { 
    int n = mp.size();
    vl in(n, 0), out(n, 0);
    rep(u, n) {
        for(auto v: G[u]) out[u]++, in[v]++;
    }
    ll s = -1, t = -1;
    rep(i, n) {
        if(out[i] - in[i] == 1) {
            if(s != -1) return 0;
            s = i;
        } 
        else if(out[i] - in[i] == -1) {
            if(t != -1) return 0;
            t = i;
        }
        else if(out[i] - in[i] != 0) return 0;
    }
    if(s == -1) {
        rep(i, n) if(out[i]) {
            s = i;
            break;
        }
    }
    dfs(s);
    reverse(P.begin(), P.end());
    P = invmp[s][0] + P;
    if(P.length() != N + 2) return 0;
    return 1;
}




int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>N;
    string S[N];
    rep(i, N) {
        cin>>S[i];
        string s1 = S[i].substr(0, 2), s2 = S[i].substr(1, 2);
        if(!mp.count(s1)) {
            invmp[mp.size()] = s1;
            mp[s1] = mp.size();
        }
        if(!mp.count(s2)) {
            invmp[mp.size()] = s2;
            mp[s2] = mp.size();
        }
        G[mp[s1]].pb(mp[s2]);
    }

    if(!euler_path()) cout<<"NO\n";
    else {
        cout<<"YES\n";
        cout<<P<<'\n';
    }

    return 0;
}