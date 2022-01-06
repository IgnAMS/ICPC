#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<int,int> ii;
typedef double db;
typedef vector<ll> vi;
#define ff first
#define ss second
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
//  g++ -O2 D.cpp && time ./a.out < input.txt > output.txt

struct Trie{
    static const int MAX = 1e6;
    vector<vi> G = vector<vi>(1, vi(26, -1));
    vi S = vi(1, 0);
    int c = 0;
    ll ans = 0;
    vi V;
    void add(string s, int a = 1){
        int p = 0; S[p] += a;
        for (char l : s) {
            int t = l - 'a';
            if(G[p][t] == -1) {
                G.emplace_back(26, -1);
                S.push_back(0);
                G[p][t] = ++c;
            }
            S[p = G[p][t]] += a;
        }
    }
    
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; 
    while(cin>>n){
        string line;
        vector<string> Lines(n);
        ll suma = 0;
        rep(i, n) { cin>>Lines[i]; suma += Lines[i].length(); }
        Trie T; rep(i, n) T.add(Lines[i]);
        set<int> S;
        ll ans = 0;
        rep(i, n){
            int p = 0;
            ll prev = -1;
            bool padre = 1;
            for (char l : Lines[i]) {
                int t = l - 'a'; 
                p = T.G[p][t];
                if((T.S[p] != prev or padre) and !S.count(p)) { 
                    ans += T.S[p]; 
                    S.insert(p);
                    // cerr<<"aumento en "<<T.S[p]<<" para "<<i<<' '<<l<<'\n';
                }
                prev = T.S[p];
                padre = 0;
            }
        }
        cout<<setprecision(2)<<fixed<<double(ans) / double(n)<<'\n';
    }


    return 0;
}