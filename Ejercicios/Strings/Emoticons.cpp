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
//  g++ -O2 Emoticons.cpp && time ./a.out < input.txt > output.txt

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; 
    while(cin>>n>>m and n) {
        vector<string> E(n); rep(i, n) cin>>E[i];
        string nul; 
        getline(cin, nul);
        vector<string> A(m); rep(i, m) getline(cin, A[i]);
        vector<vector<ii>> P(m, vector<ii>());
        rep(i, m) rep(j, n){ // m lineas, n emoticones
            // 32 - 3 = 29, pero 29 puede ser un inicio para [29, 30, 31], por eso el +1
            rep(k, int(A[i].size()) - int(E[j].size()) + 1){ // string que empieza en k
                bool oc = 1;
                rep(h, E[j].size()) if(A[i][k + h] != E[j][h]) { oc = 0; break; }
                if(oc) P[i].push_back(ii(k, k + E[j].size() - 1));
            }
        }
        rep(i, m) sort(P[i].begin(), P[i].end());
        // rep(i, m){
        //     rep(j, P[i].size()) cout<<"("<<P[i][j].ff<<", "<<P[i][j].ss<<"), ";
        //     cout<<'\n';
        // }
        cerr<<"estoy vivo\n";
        ll ans = 0;
        rep(i, m) { // tamano de P
            int j = 0, x = 0;
            while(j < P[i].size()) {
                int right = P[i][j].ss;
                while(x < P[i].size() and P[i][x].ff <= right) {
                    right = min(right, P[i][x].ss);
                    x++;
                }
                // cout<<right<<'\n';
                // cout<<"avanzo de "<<j<<" hasta "<<x<<'\n';
                ans++;
                j = x;
                x++;
            }
        }

        cout<<ans<<'\n';

    }

    return 0;
}