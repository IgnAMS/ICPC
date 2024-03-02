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

struct RH {
    int B = 1777771, M[2] = {999727999, 1070777777}, P[2] = {325255434, 10018302};
    vl H[2], I[2];
    RH(string &s) {
        int N = s.size(); rep(k, 2) {
            H[k].resize(N + 1), I[k].resize(N + 1);
            H[k][0] = 0, I[k][0] = 1; ll b = 1;
            rep(i, N + 1) if (i) {
                H[k][i] = (H[k][i - 1] + b * s[i - 1]) % M[k];
                I[k][i] = (1LL * I[k][i - 1] * P[k]) % M[k];
                b = (b * B) % M[k];
            }
        }
    }
    ll get(int l, int r) {
        r++;
        ll h0 = (H[0][r] - H[0][l] + M[0]) % M[0];
        h0 = (1LL * h0 * I[0][l]) % M[0];
        ll h1 = (H[1][r] - H[1][l] + M[1]) % M[1];
        h1 = (1LL * h1 * I[1][l]) % M[1];
        return (h0 << 32) | h1;
    }
};

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    string s; cin>>s;
    int n = s.length();
    RH rh(s);
    rep(i, n - 1) {
        if(rh.get(0,  i) == rh.get(n - 1 - i, n - 1)) cout<<i + 1<<' ';
    }
    cout<<'\n';

    return 0;
}