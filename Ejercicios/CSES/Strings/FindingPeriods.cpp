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


struct SA {
    int n; 
    vector<int> C, R, R_, sa, sa_, lcp;
    vector<vector<int>> DP = vector<vector<int>>(21, vector<int>(1048578));
    inline int gr(int i) { return i < n ? R[i] : 0; }
    void csort(int maxv, int k) {
        C.assign(maxv + 1, 0); 
        rep(i, n) C[gr(i + k)]++;
        repx(i, 1, maxv + 1) C[i] += C[i - 1];
        for(int i = (int)n - 1; i >= 0; i--) sa_[--C[gr(sa[i] + k)]] = sa[i];
        sa.swap(sa_);
    }

    void getSA(vl& s) {
        R = R_ = sa = sa_ = vector<int>(n); 
        rep(i, n) sa[i] = i;
        sort(sa.begin(), sa.end(), [&](int i, int j) { return s[i] < s[j]; });
        int r = R[sa[0]] = 1;
        repx(i, 1, n) R[sa[i]] = (s[sa[i]] != s[sa[i - 1]]) ? ++r : r;
        for(int h = 1; h < n and r < n; h <<= 1) {
            csort(r, h); csort(r, 0);   
            r = R_[sa[0]] = 1;
            repx(i, 1, n) {
                if(R[sa[i]] != R[sa[i - 1]] || gr(sa[i] + h) != gr(sa[i - 1] + h)) r++;
                R_[sa[i]] = r;
            }
            R.swap(R_);
        }
    }

    void getLCP(vl &s) {
        lcp.assign(n, 0); int k = 0;
        rep(i, n) {
            int r = R[i] - 1;
            if(r == n - 1) { k = 0; continue; }
            int j = sa[r + 1];
            while(i + k < n && j + k < n and s[i + k] == s[j + k]) k++;
            lcp[r] = k; if (k) k--;
        }
    }
    
    void getST() {
        int LOG = 31 - __builtin_clz(n);
        rep(i, n) {
            DP[0][i] = lcp[i];
        }
        rep(k, 19) rep(i, n - (1<<k) + 1) {
            DP[k + 1][i] = min(DP[k][i], DP[k][i + (1 << k)]);
        }
    }

    int query_O1(int l, int r) {
        int k = 31 - __builtin_clz(r - l + 1);
        return min(DP[k][l], DP[k][r - (1 << k) + 1]);
    }

    SA(string &S) {
        n = S.size();
        vl s(n);
        rep(i, n) s[i] = S[i] - 'a';
        getSA(s); 
        getLCP(s);
        getST();
    }
};


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    string s; cin>>s;
    int n = s.length();
    vl V(n + 1, 0);

    SA sa(s);
    vl Id(n);
    rep(i, n) Id[sa.sa[i]] = i;
    
    repx(i, 1, n) {
        bool valid = 1;
        if(V[i]) {
            cout<<i<<' ';
            continue;
        }
        for(int j = i; j + i - 1 < n; j += i) {
            int mn = min(Id[0], Id[j]), mx = max(Id[0], Id[j]) - 1;
            if(sa.query_O1(mn, mx) < i) {
                valid = 0;
                break;
            }
        }
        int sobra = n % i;
        if(sobra > 0) {
            int mn = min(Id[0], Id[n - sobra]), mx = max(Id[0], Id[n - sobra]) - 1;
            if(sa.query_O1(mn , mx) < sobra) valid = 0;
        }

        if(valid) {
            cout<<i<<' ';
            for(int j = i; j + i < n; j += i) V[j] = 1;
        }
    }
    cout<<n<<'\n';

    return 0;
}