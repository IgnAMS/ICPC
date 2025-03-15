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

vl L;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    string s; cin>>s;
    int n = s.length();

    vector<int> Ans(n + 1, n + 1);
    rep(i, n) {
        string aux = "";
        L.pb(0);
        vl X;
        rep(k, n) X.pb(k - 1);
        repx(j, i, n) {
            aux += s[j];
            ll largo = j - i + 1;
            ll comps = n;

            ll last = -1000;
            vl Y;
            for(auto u: X) {
                if(s[u + 1] != s[j]) continue;
                // cout<<s.substr(u + 2 - largo, largo)<<'\n';
                // cout<<last<<' '<<u + 2 - largo<<'\n';
                if(last < u + 2 - largo) comps -= largo - 1;
                else comps -= u + 1 - last;
                last = u + 1;
                if(u + 1 != n) Y.pb(u + 1);
            }
            // cout<<"con el string "<<s.substr(i, largo)<<" puedo formar "<<comps<<" componentes\n";
            X = Y;


            if(j + 1 < n) {
                int i2 = L[j - i]; while(aux[i2] != s[j + 1] and i2) i2 = L[i2 - 1];
                L.pb(aux[i2] == s[j + 1] ? i2 + 1: 0);
                // cout<<"la extension de "<<s[j + 1]<<" es "<<L.back()<<'\n';
            }
            Ans[comps] = min(Ans[comps], j - i + 1);
            

        }
        L.clear();
    }

    repx(i, 1, n + 1) cout<<(Ans[i] == n + 1? 0: Ans[i]) <<' '; cout<<'\n';


    return 0;
}