#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<int,int> ii;
typedef double db;
typedef vector<ll> vi;
#define ff first
#define ss second
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
//  g++ -O2 D.cpp && time ./a.out < input.txt > output.txt

vi d1, d2;
void Manacher(vi& A){
    int n = A.size();
    d1.assign(n, 0);
    for (ll i = 0, l = 0, r = -1; i < n; i++) {
        int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
        while (0 <= i - k && i + k < n && A[i - k] == A[i + k]) {
            k++;
        }
        d1[i] = k--;
        if (i + k > r) {
            l = i - k;
            r = i + k;
        }
    }
    d2.assign(n, 0);
    for (ll i = 0, l = 0, r = -1; i < n; i++) {
        int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);
        while (0 <= i - k - 1 && i + k < n && A[i - k - 1] == A[i + k]) {
            k++;
        }
        d2[i] = k--;
        if (i + k > r) {
            l = i - k - 1;
            r = i + k ;
        }
    }
}


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




struct FT
{
    vi t;
    FT(int N) { t.resize(N + 1, 0); }
    int query(int i)
    {
        int ans = 0;
        for (; i; i -= i & (-i)) ans += t[i];
        return ans;
    }
    int query(int i, int j) { return query(j) - query(i - 1); }
    void update(int i, int v)
    {
        int s = query(i, i); // Sets
        for (; i < t.size(); i += i & (-i)) t[i] += v;
    }
    void update(int i, int j, int v) { update(i, v); update(j + 1, -v); }
};



int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, q; cin>>n>>q; 
    string s; cin>>s;
    vi A(s.length()); rep(i, s.length()) A[i] = s[i] - 'a' + 1;
    vector<ii> Q(q);
    rep(i, q) { 
        cin>>Q[i].ff; 
        Q[i].ss = i;
    }
    sort(Q.begin(), Q.end());
    
    Manacher(A); 

    FT inicio(n);
    rep(i, n) inicio.update(i - (d1[i] - 1) + 1, i + 1, 1);
    rep(i, n) inicio.update(i - d2[i] + 1, i, 1);
    
    SA sa1(A);
    ll inicios = 0;
    int j1 = 0;

    vi I(q, -1);
    rep(i, n) {
        inicios += inicio.query(sa1.sa[i] + 1); // sumo la cantidad que hay
        while(j1 < q and Q[j1].ff <= inicios){
            I[Q[j1].ss] = sa1.sa[i];
            j1++;
        }
    }
    
    reverse(A.begin(), A.end());
    Manacher(A); 

    FT fin(n);
    rep(i, n) fin.update(i+1, i + 1 + (d1[i]-1), 1);
    rep(i, n) fin.update(i+1, i + 1 + (d2[i]-1), 1);
    
    SA sa2(A);
    ll finales = 0;
    int j2 = 0;
    vi O(q, -1);
    rep(i, n) {
        finales += fin.query(sa2.sa[i] + 1); 
        while(j2 < q and Q[j2].ff <= finales){
            O[Q[j2].ss] = sa2.sa[i];
            j2++;
        }
    }

    
    rep(i, q) cout<<I[i]<<' '<<O[i]<<'\n';



    return 0;
}