#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma") // could make sigill runtime error
#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<int, int> pll;
typedef double db;
typedef vector<int> vi;
typedef vector<ll> vl;
#define ff first
#define ss second
#define pb push_back
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
// ulimit -s 1000000
// g++ -O2 D.cpp && time ./a.out <input.txt> output.txt

struct SA
{
    int n; vi C, R, R_, sa, sa_, lcp;
    inline int gr(int i) { return i < n ? R[i] : 0; }
    void csort(int maxv, int k)
    {
        C.assign(maxv + 1, 0); rep(i, n) C[gr(i + k)]++;
        repx(i, 1, maxv + 1) C[i] += C[i - 1];
        for (int i = (int)n - 1; i >= 0; i--) sa_[--C[gr(sa[i] + k)]] = sa[i];
        sa.swap(sa_);
    }
    void getSA(vi& s)
    {
        R = R_ = sa = sa_ = vi(n); rep(i, n) sa[i] = i;
        sort(sa.begin(), sa.end(), [&s](int i, int j) { return s[i] < s[j]; });
        int r = R[sa[0]] = 1;
        repx(i, 1, n) R[sa[i]] = (s[sa[i]] != s[sa[i - 1]]) ? ++r : r;
        for (int h = 1; h < n && r < n; h <<= 1)
        {
            csort(r, h); csort(r, 0); r = R_[sa[0]] = 1;
            repx(i, 1, n)
            {
                if (R[sa[i]] != R[sa[i - 1]] || gr(sa[i] + h) != gr(sa[i - 1] + h)) r++;
                R_[sa[i]] = r;
            } R.swap(R_);
        }
    }
    void getLCP(vi &s)
    {
        lcp.assign(n, 0); int k = 0;
        rep(i, n)
        {
            int r = R[i] - 1;
            if (r == n - 1) { k = 0; continue; }
            int j = sa[r + 1];
            while (i + k < n && j + k < n and s[i + k] == s[j + k]) k++;
            lcp[r] = k; if (k) k--;
        }
    }
    SA(vi &s) { n = s.size(); getSA(s); getLCP(s); }
};

struct OP
{
    static const int neutro = 1e7;
    static int merge(int x, int y) { return min(x, y); }
};

template <class t>
class ST
{
    int N; vi DP;

public:
    ST(vi &v)
    {
        N = v.size(); int LOG = 31 - __builtin_clz(N);
        DP.assign(N * (LOG + 1), -1);
        rep(i, N) DP[i] = v[i];
        rep(k, LOG) rep(i, N)
            DP[(k + 1) * N + i] = t::merge(DP[k * N + i], 
                                           DP[k * N + i + (1 << k)]);
    }
    int query_O1(int l, int r)
    {
        int k = 31 - __builtin_clz(r - l + 1);
        return t::merge(DP[k * N + l], DP[k * N + r - (1 << k) + 1]);
    }
    int query_Ologn(int l, int r)
    {
        int ans = t::neutro;
        int d = r - l + 1;
        for (int k = 0; d; k++, k >>= 1) if (k & 1)
            ans = t::merge(ans, DP[k * N + l]), l += 1 << k;
        return ans;
    }
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    string t; cin>>t;
    int d; cin>>d;
    int n = t.size();
        
    vi A(n); rep(i, n) A[i] = int(t[i] - 'a'); 
    
    SA sa1(A);
    vi Aux(n);
    rep(i, n) Aux[sa1.sa[i]] = i;
    ST<OP> st(sa1.lcp);
    ll ans = 0;
    for(int i = 0; i < n;) {
        ll right = i + d;
        for(int j = i; j < min(i + d, n); j++) {
            ll largo = j - i + 1;
            // cout<<i<<' '<<j<<' '<<i + largo<<'\n';
            if(i + largo >= n) {
                right = max(right, (ll)i + d);
                continue;
            }
            ll l = min(Aux[i], Aux[i + largo]);
            ll r = max(Aux[i], Aux[i + largo]);
            
            // cout<<l<<' '<<r<<'\n';
            // cout<<i<<' '<<largo<<' '<<l<<' '<<r<<' '<<largo + st.query_O1(l, r - 1)<<'\n';
            right = max(right, i + largo + st.query_O1(l, r - 1));
        }
        // cout<<"me como el intervalo "<<i<<' '<<right<<'\n';
        ans++;
        i = right;
    }
    cout<<ans<<'\n';
    
    return 0;
}