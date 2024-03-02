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

#define PI acos(-1.0L)
db EPS = 1e-12;
typedef complex<double> cd;

void fft(vector<cd> & a, bool invert) {
    int n = a.size();
    if (n == 1)
        return;

    vector<cd> a0(n / 2), a1(n / 2);
    for (int i = 0; 2 * i < n; i++) {
        a0[i] = a[2*i];
        a1[i] = a[2*i+1];
    }
    fft(a0, invert);
    fft(a1, invert);

    double ang = 2 * PI / n * (invert ? -1 : 1);
    cd w(1), wn(cos(ang), sin(ang));
    for (int i = 0; 2 * i < n; i++) {
        a[i] = a0[i] + w * a1[i];
        a[i + n/2] = a0[i] - w * a1[i];
        if (invert) {
            a[i] /= 2;
            a[i + n/2] /= 2;
        }
        w *= wn; // Trie to use w = pow(w, i) or something like that
    }
}

vector<ll> multiply(vector<ll> const& a, vector<ll> const& b) {
    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while (n < a.size() + b.size()) n <<= 1;
    fa.resize(n);
    fb.resize(n);

    fft(fa, false);
    fft(fb, false);
    for (int i = 0; i < n; i++)
        fa[i] *= fb[i];
    fft(fa, true);

    vector<ll> result(n);
    for (int i = 0; i < n; i++)
        result[i] = llround(fa[i].real());
    return result;
}






int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    vl A(n), B(n);
    rep(i, n) cin>>A[i];
    rep(i, n) cin>>B[i];
    
    vl BA(2 * n, 0), BB(2 * n, 0);
    rep(i, n) {
        if(A[i] == 47) BA[n - i - 1] = 1;
        if(B[i] == 47) BB[i] = BB[n + i] = 1;
    }

    vl FFA(2 * n, 0), FFB(2 * n);
    rep(i, n) FFA[i] = A[n - i - 1];
    rep(i, 2 * n) FFB[i] = B[i % n];

    vl convF = multiply(FFA, FFB);
    vl convB = multiply(BA ,BB);

    ll mx = 0;
    repx(i, n - 1, 2 * n - 1) {
        // cout<<convB[i]<<' '<<convF[i]<<'\n';
        if(convB[i] <= 0.5) mx = max(mx, convF[i]);
    }
    cout<<mx<<'\n';

    return 0;
}