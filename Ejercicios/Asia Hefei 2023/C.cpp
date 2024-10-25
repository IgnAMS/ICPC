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

int n; 
string s;


struct RH {
    int binpow(int a, int b, int MOD) {
        int res = 1;
        while(b) {
            if(b & 1) res = (1LL * res * a) % MOD;
            a = (1LL * a * a) % MOD;
            b >>= 1;
        }
        return res;
    } 
    const int B = 119, M[2] = {999727999, 1070777777}, P[2] = {325255434, 10018302};
    vector<int> H[2], I[2];
    RH(string &s) {
        int N = s.size();
        rep(k, 2) {
            H[k].resize(N + 1), I[k].resize(N + 1);
            H[k][0] = 0; ll b = 1;
            rep(i, N) {
                H[k][i + 1] = (H[k][i] + b * (s[i] - 'a' + 1)) % M[k];
                b = (b * B) % M[k];
            }
            I[k][N] = binpow(b, M[k - 2], M[k]);
            for(int i = N - 1; i >= 0; i--) I[k][i] = (1LL * I[k][i + 1] * B) % M[k];
        }
    }

    ll get(int l, int r) {
        ll h0 = (H[0][r] - H[0][l] + M[0]) % M[0];
        h0 = (1LL * h0 * I[0][l]) % M[0];
        ll h1 = (H[1][r] - H[1][l] + M[1]) % M[1];
        h1 = (1LL * h1 * I[1][l]) % M[1];
        return (h0<<32) | h1;
    }
};



void manacher() {
    vl d1(n);
    cout<<"impar:\n";
    for(int i = 0, l = 0, r = -1; i < n; i++) {
        int k = (i > r) ? 1: min(d1[l + r - i], r - i + 1LL);
        cout<<((i > r)? 1: l + r - i)<<'\n';
        while(0 <= i - k and i + k < n and s[i - k] == s[i + k]) {
            k++;
        }
        d1[i] = k--;
        cout<<i<<' '<<d1[i]<<'\n';
        
        if(i + k > r) {
            l = i - k, r = i + k;
        }
    }
    cout<<"\npar:\n";
    vl d2(n);
    for(int i = 0, l = 0, r = -1; i < n; i++) {
        int k = (i > r) ? 0: min(d2[l + r - i - 1], r - i + 1LL);
        while(0 <= i - k and i + k < n and s[i - k] == s[i + k]) {
            k++;
        }
        d2[i] = k--;
        cout<<i<<' '<<k<<'\n';
        if(i + k > r) {
            l = i - k - 1, r = i + k;
        }
    }
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    cin>>s;
    manacher();


    return 0;
}