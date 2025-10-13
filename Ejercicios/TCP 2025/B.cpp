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

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int M, T; cin>>M>>T;
    string ruleta; cin>>ruleta;
    string ans = "";
    rep(i, M) {
        cout<<"ROJO"<<endl;
        string curr; cin>>curr;
        if(curr == "PERDISTE") ans += "N";
        else ans += "R";
    }

    pll best;
    rep(i, M) {
        rep(j, M) {
            // i: punto de inicio
            // j: N de giros
            ll cont = 0;
            rep(k, M) {
                ll pos = (i + j * k) % M;
                if(ruleta[pos] != ans[k]) break;
                cont++;
            }
            if(cont == M) best = {i, j};
        }
    }

    int curr_pos = best.ff + best.ss * M;
    rep(i, T - M) {
        if(ruleta[curr_pos] == 'R') cout<<"ROJO"<<endl;
        else cout<<"NEGRO"<<endl;
        string curr; cin>>curr;
        curr_pos += best.ss;
        curr_pos %= M;
    }




    return 0;
}