#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef pair<ll, ll> pll;
#define repx(i, a, b) for(int i = a; i < b; i++)
#define rep(i, n) repx(i, 0, n)
#define invrep(i, a, b) for(int i = a; i>=(int)b; --i)
#define pb push_back

const int mxN = 1e5+5;

struct SA{
    int n; vl counts, rank, rank_, sa, sa_, lcp;
    inline int gr(int i) { return i < n ? rank[i] : 0; }
    void csort(int maxv, int k){
        counts.assign(maxv+1, 0);
        repx(i, 0, n) counts[gr(i+k)]++;
        repx(i, 1, maxv+1) counts[i] += counts[i-1];
        invrep(i, n-1, 0) sa_[--counts[gr(sa[i]+k)]] = sa[i];
        sa.swap(sa_);
    }
    void get_sa(vl& s) {
        repx(i, 0, n) sa[i] = i;
        sort(sa.begin(), sa.end(), [&s](int i, int j) { return s[i] < s[j]; });
        int r = rank[sa[0]] = 1;
        repx(i, 1, n) rank[sa[i]] = (s[sa[i]] != s[sa[i-1]]) ? ++r : r;
        for(int h = 1; h<n and r<n; h<<=1){
            csort(r, h); csort(r, 0); r = rank_[sa[0]] = 1;
            repx(i, 1, n){
                if(rank[sa[i]] != rank[sa[i-1]] or gr(sa[i]+h) != gr(sa[i-1]+h)) ++r;
                rank_[sa[i]] = r;
            }
            rank.swap(rank_);
        }
    }
    void get_lcp(vl& s) {
        lcp.assign(n, 0); int k = 0;
        repx(i, 0, n) {
            int r =  rank[i] - 1;
            if(r == n - 1) { k = 0; continue; }
            int j = sa[r + 1];
            while(i+k < n and j+k<n and s[i+k] == s[j+k]) k++;
            lcp[r] = k;
            if(k) k--;
        }     
    }
    SA(vl& s) {
        n = s.size();
        rank.resize(n); rank_.resize(n);
        sa.resize(n); sa_.resize(n);
        get_sa(s); get_lcp(s);
    }
};

struct SEG{
    ll mx[4*mxN], lz[4*mxN], sm[4*mxN];
    void init(){
        rep(u, 4 * mxN) mx[u] = 0, lz[u] = -1, sm[u] = 0;
        // memset(mx, -1, sizeof(mx));
        // memset(lz, 0, sizeof(lz));
        // memset(sm, 0, sizeof(sm));
    }

    void app(ll i, ll val, int l2, int r2){
        mx[i] = val;
        lz[i] = val;
        sm[i] = val*(r2-l2+1);

    }
    void psh(int i, int l2, int m2, int r2){
        app(2*i, lz[i], l2, m2);
        app(2*i+1, lz[i], m2+1, r2);
        merge(i);
        lz[i] = -1;
     }



    void merge(int i){
        mx[i] = max(mx[2*i], mx[2*i+1]);
        sm[i] = sm[2*i] + sm[2*i+1];
    }
    void upd1(int l1, int r1, int l2, int r2, int i, ll val){
        if(l2 > r1 || r2 < l1) return;
        if(l1 <= l2 && r2 <= r1){
            mx[i] = val;
            sm[i] = val;
            lz[i] = -1;
            return;
        }
        
        int m2 = (l2+r2)/2;
        if(lz[i] != -1) {
            psh(i, l2, m2, r2);
        }
        upd1(l1, r1, l2, m2, 2*i, val);
        upd1(l1, r1, m2+1, r2, 2*i+1, val);
        merge(i);
    }
    void upd2(int l1, int r1, int l2, int r2, int i, ll val){
        if(l1 <=l2 && r2 <= r1){
            app(i, val, l2, r2);
            return;
        }
        if(l2 > r1 || r2 < l1) return;

        int m2 = (l2+r2)/2;
        if(lz[i] != -1) {
            psh(i, l2, m2, r2);
        }

        upd2(l1, r1, l2, m2, 2*i, val);
        upd2(l1, r1, m2+1, r2, 2*i+1, val);
        merge(i);
    }
    int upper_bound_idx(int l2, int r2, int i, ll val){
        if(l2 == r2){
            return l2;
        }
        int m2 = (l2+r2)/2;
        if(lz[i] != -1) {
            psh(i, l2, m2, r2);
        }
        // psh(i, l2, m2, r2);
        if(mx[2*i] < val) {
            // Deberia ser val - mx[2 * i]?
            return upper_bound_idx(m2+1, r2, 2*i+1, val);
        }
        return upper_bound_idx(l2, m2, 2*i, val);
    }
    ll qry(int l1, int r1, int l2, int r2, int i){
        if(l2 > r1 or r2 < l1) return 0;
        if(l1 <= l2 and r2 <= r1){
            return sm[i];
        }
        int m2 = (l2+r2)/2;
        if(lz[i] != -1) {
            psh(i, l2, m2, r2);
        }
        return qry(l1, r1, l2, m2, 2*i) + qry(l1, r1, m2+1, r2, 2*i+1);
    }
}seg;

void solve(){
    ll n;
    cin >> n;
    seg.init();
    vector<ll> a(n); 
    rep(i, n){
        cin >> a[i];
    }
    SA sa(a);
    ll denominador = n*n;
    ll numerador = 0;
    seg.upd1(0, 0, 0, n-1, 1, sa.lcp[0]);
    for(int i = 1; i<n; ++i){
        // rep(j, n) cout<<seg.qry(j, j, 0, n - 1, 1)<<' '; cout<<'\n';
        numerador += seg.qry(0, i-1, 0, n-1, 1);
        int l = seg.upper_bound_idx(0, n-1, 1, sa.lcp[i]);
        if(l <= i) {
            // cout<<"update de rango "<<l + 1<<' '<<i<<' '<<sa.lcp[i]<<'\n';
            seg.upd2(l, i, 0, n-1, 1, sa.lcp[i]);
        }
        seg.upd1(i, i, 0, n-1, 1, sa.lcp[i]);
    }

    numerador *= 2;
    numerador += n*(n+1)/2;
    ll gcd = __gcd(numerador, denominador);
    numerador /= gcd;
    denominador /= gcd;
    cout << numerador << "/" << denominador << "\n";
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    
    solve();

    return 0;
}