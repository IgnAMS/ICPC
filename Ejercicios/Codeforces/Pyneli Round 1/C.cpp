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
// g++ -O2 D.cpp && time ./a.out <input.txt> output.txt

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        string mat[n]; rep(i, n) cin>>mat[i];
        vi suma(n, 0); 
        rep(j, n) rep(i, n) suma[j] += mat[i][j] - '0';
        vector<ii> P;
        rep(i, n) P.push_back({suma[i], i});
        sort(P.begin(), P.end());
        vector<set<int>> S(n, set<int>()); rep(i, n) S[i].insert({i + 1});
        for(auto& [a, j]: P) { 
            rep(i, n) if(mat[i][j] == '1') S[j].insert({i + 1});
        }
        rep(i, n) {
            cout<<S[i].size(); for(auto u: S[i]) cout<<' '<<u; cout<<'\n';
        }
    }





    return 0;
}