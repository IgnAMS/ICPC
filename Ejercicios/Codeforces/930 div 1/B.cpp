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
        int n; cin>>n;
        string s; cin>>s;

        vl L(n + 1, 0), R(n + 1, 0);
        rep(i, n) L[i + 1] = L[i] + (s[i] == '>');
        for(int i = n - 1; i >= 0; i--) R[i] = R[i + 1] + (s[i] == '<');

        rep(i, n) {
            // R[i] me dice cuantos hay a mi derecha contandome
            // L[i + 1] me dice cuantos hay a mi izquierda contandome
            ll ans = 0;
            if(s[i] == '<') {
                // voy a la izquierda
                if(L[i] <= R[i + 1]) ans = 2 * L[i];
                // voy a la derecha
                else ans = 2 * R[i + 1] + 1;
            }
            else {
                // s[i] == '>'
                // voy a la izquierda
                if(L[i] <= R[i + 1]) ans = 2 * L[i] + 1;
                else ans = 2 * R[i + 1];
            }
            cout<<ans<<' ';
        }
        cout<<'\n';
        cout<<'\n';


    }


    return 0;
}