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

struct Trie {
    static const int MAX = 1e6 + 4e5;
    int N[MAX][26] = {0}, S[MAX] = {0}, C[MAX][26], ID[MAX], c = 0;
    void add(string s, int i, int a = 1)
    {
        int p = 0; S[p] += a;
        for (char l : s) {
            int t = l - 'a';
            if (!N[p][t]) {
                N[p][t] = ++c;
                rep(i, 26) C[c][i] = C[p][i];
                C[c][t]++;
                ID[c] = -1;
            }
            S[p = N[p][t]] += a;
        }
        ID[c] = i;

    }
} trie;




int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    vector<string> S;
    rep(i, n) {
        string s; cin>>s;
        S.pb(s);
        trie.add(s, i);
    }

    int q; cin>>q;
    while(q--) {
        vl C(26, 0);
        string s; cin>>s;
        for(auto c: s) C[c - 'a']++;

        queue<int> q;
        vector<int> D(1400000, 100);
        D[0] = 0; q.push(0);
        string Sans;
        while(!q.empty()) {
            int p = q.front(); q.pop();
            rep(i, 26) {
                int next = trie.N[p][i];
                if(next and C[i] - trie.C[p][i] > 0) {
                    q.push(next);
                    D[next] = D[p] + 1;
                    // cout<<"ahora tengo a "<<trie.ID[next]<<" con distancia "<<D[p] + 1<<'\n';
                    if(trie.ID[next] != -1 and S[trie.ID[next]].size() > Sans.size()) {
                        Sans = S[trie.ID[next]];
                    }
                }
            }
        }
        if(Sans.size() == 0) cout<<"IMPOSSIBLE\n";
        else cout<<Sans<<'\n';
    }





    return 0;
}