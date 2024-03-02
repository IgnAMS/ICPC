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
// g++ -O2 Minimalrotations.cpp && time ./a.out <input.txt> output.txt

struct SA {
    int n; vl C, R, R_, sa, sa_, lcp;
    inline int gr(int i) { return i < n ? R[i] : 0; }
    void csort(int maxv, int k) {
        C.assign(maxv + 1, 0); 
        rep(i, n) C[gr(i + k)]++;
        repx(i, 1, maxv + 1) C[i] += C[i - 1];
        for (int i = (int)n - 1; i >= 0; i--) sa_[--C[gr(sa[i] + k)]] = sa[i];
        sa.swap(sa_);
    }
    void getSA(vl& s) {
        R = R_ = sa = sa_ = vl(n); 
        rep(i, n) sa[i] = i;
        sort(sa.begin(), sa.end(), [&s](int i, int j) { return s[i] < s[j]; });
        int r = R[sa[0]] = 1;
        repx(i, 1, n) R[sa[i]] = (s[sa[i]] != s[sa[i - 1]]) ? ++r : r;
        for(int h = 1; h < n && r < n; h <<= 1) {
            csort(r, h); csort(r, 0); r = R_[sa[0]] = 1;
            repx(i, 1, n) {
                if(R[sa[i]] != R[sa[i - 1]] || gr(sa[i] + h) != gr(sa[i - 1] + h)) r++;
                R_[sa[i]] = r;
            } R.swap(R_);
        }
    }
    void getLCP(vl &s) {
        lcp.assign(n, 0); int k = 0;
        rep(i, n) {
            int r = R[i] - 1;
            if (r == n - 1) { k = 0; continue; }
            int j = sa[r + 1];
            while (i + k < n && j + k < n and s[i + k] == s[j + k]) k++;
            lcp[r] = k; if (k) k--;
        }
    }
    SA(vl &s) { 
        n = s.size();
        getSA(s);
    }
};


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    string s; cin>>s;
    int n = s.length();
    vl s_int(n); 
    rep(i, n) s_int[i] = s[i] - 'a';
    rep(i, n) s_int.pb(s_int[i]);
    SA sa(s_int);
    int ans = 0;
    rep(i, 2 * n) {
        if(sa.sa[i] < n) {
            ans = sa.sa[i];
            break;
        }
    }
    string aux = "";
    rep(i, n) aux += s[(i + ans) % n]; 
    cout<<aux<<'\n';


    return 0;
}