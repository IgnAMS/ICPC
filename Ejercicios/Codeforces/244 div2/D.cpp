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


vl L[2], F[2], C[2];

void LCP(string &p, string& t) {
    rep(b, 2) {
        int n = p.length(); 
        L[b].assign(n, 0), F[b].assign(n, 0), C[b].assign(n, 0);
        rep(j, n - 1) {
            int i = L[b][j];
            while(p[i] != p[j + 1] and i) i = L[b][i - 1];
            L[b][j + 1] = (p[i] == p[j + 1] ? i + 1 : 0);
            F[b][j + 1] = L[b][j + 1] == 0? j + 1: F[b][L[b][j + 1] - 1];
        }
        rep(i, n) if(L[b][i] != 0) C[b][L[b][i] - 1]++;
        for(int i = n - 1; i > 0; i--) {
            if(L[b][i] != 0) C[b][L[b][i] - 1] += C[b][i];
        }
        rep(i, n) C[b][i]++;
        swap(p, t);
    }
}


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    string s1, s2; cin>>s1>>s2;
    int n = s1.length();
    int ans = 1e4;
    rep(i, n) {
        string aux = s1.substr(i, n - i);
        aux += '#';
        aux += s2;
        string aux2 = s1.substr(i, n - i);
        aux2 += '#';
        aux2 += s1;

        LCP(aux, aux2);
        
        // rep(b, 2) {
        //     cout<<aux<<'\n';
        //     rep(j, L[b].size()) cout<<L[b][j]<<' '; cout<<'\n';
        //     rep(j, L[b].size()) cout<<F[b][j]<<' '; cout<<'\n';
        //     rep(j, L[b].size()) cout<<C[b][j]<<' '; cout<<'\n';
        //     cout<<"\n";
        //     swap(aux, aux2);
        // }
        rep(j, n - i) {
            if(C[0][j] == 2 and C[1][j] == 2) {
                // cout<<"entre con "<<aux.substr(0, j + 1)<<'\n';
                ans = min(ans, j + 1); 
            }
        }
    }
    cout<<(ans == 1e4? -1: ans)<<'\n';



    return 0;
}