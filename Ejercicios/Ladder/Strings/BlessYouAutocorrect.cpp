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

string Auto[100001], Words[100001];
int n, m;

struct Trie {
    static const int MAX = 1e6;
    int N[MAX][26] = {0}, S[MAX] = {0}, c = 0;

    vector<int> Sizes, State, Cost, Trans, Mn = vector<int>(1000000, 1000000), first = vector<int>(1000000, 1000000);
    void add(string s, int ind, int a = 1) {
        int p = 0; 
        Sizes.pb(s.length());
        S[p] += a;
        for(char l : s) {
            int t = l - 'a';
            if(!N[p][t]) N[p][t] = ++c;
            p = N[p][t];
            S[p] += a;
            Mn[p] = min(ind, Mn[p]);
        }
    }
    void init_costs(string &s) {
        Cost.assign(n, 1000000);
        State.assign(s.length(), -1);
        Trans.assign(n, -1);
        Mn[0] = 0;

        int p = 0;
        bool oc = 0;
        rep(i, s.length()) {
            int t = s[i] - 'a';
            if(!N[p][t]) {
                oc = 1;
                Cost[Mn[p]] = Sizes[Mn[p]] - i + 1;
                Trans[Mn[p]] = i;
                break;
            }
            int prev = p;
            p = N[p][t];
            State[i] = p;

            if(prev != 0 and Mn[prev] != Mn[p]) {
                Cost[Mn[prev]] = Sizes[Mn[prev]] - i + 1;
                first[Mn[p]] = i;
                // cerr<<"asigno el costo para cambiar a "<<Mn[prev]<<" de "<<Cost[Mn[prev]]<<'\n';
                Trans[Mn[prev]] = i;
            }
            if(prev == 0) {
                first[Mn[p]] = i;
            }
        }
        if(!oc) {
            Cost[Mn[p]] = Sizes[Mn[p]] - s.length() + 1;
            Trans[Mn[p]] = s.length();
        }
    }
} trie;

int DP[1000005][2];
int dp(int i, int b, string& s) {
    if(i == s.length()) return 0;
    if(DP[i][b] != -1) return DP[i][b];

    int t = s[i] - 'a';
    int u = trie.State[i];
    DP[i][b] = dp(i + 1, 0, s) + 1;
    if(u > 0 and !b and i != trie.first[trie.Mn[u]]) {
        int j = trie.Mn[u];
        DP[i][b] = min(DP[i][b], dp(trie.Trans[j], 1, s) + trie.Cost[j]);
    }
    int indjump = (u > 0? trie.Mn[u]: -1);
    int jump = (u > 0? trie.Trans[trie.Mn[u]]: -1);
    int cost = (u > 0? trie.Cost[trie.Mn[u]]: -1);
    int first = (u > 0? trie.first[trie.Mn[u]]: -1);

    return DP[i][b];
}



int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    // Memory limit: 1MB ~ 10^6 caracteres
    cin>>n>>m;
    rep(i, n) {
        cin>>Auto[i];
        trie.add(Auto[i], i);
    }
    rep(i, m) cin>>Words[i];

    rep(i, m) {
        rep(j, Words[i].length() + 2) rep(b, 2) DP[j][b] = -1;
        trie.init_costs(Words[i]);
        rep(j, Words[i].length()) {
            int u = trie.State[j];
        }
        cout<<dp(0, 0, Words[i])<<'\n';
    }

    return 0;
}