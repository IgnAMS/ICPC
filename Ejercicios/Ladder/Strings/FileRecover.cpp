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


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    string line;
    while(cin>>line and line != "*"){
        int n = line.length();
        vi A(n); rep(i, n) A[i] = line[i] - 'a' + 1;
        SA sa(A);
        ll ans = 0, prev = 0;
        int i = 0;  
        // rep(i, n-1) cout<<sa.lcp[i]<<' '; cout<<'\n';
        while(i < n-1){
            while(i < n-1 and sa.lcp[i] < sa.lcp[i+1]) i++;
            // cout<<sa.lcp[i]<<" entre aca\n";
            ans += sa.lcp[i] - prev;
            while(i < n-1 and sa.lcp[i] > sa.lcp[i+1]) i++;
            prev = sa.lcp[i];
            while(i < n-1 and sa.lcp[i] == sa.lcp[i+1]) i++;
        }
        cout<<ans<<'\n';
    }


    return 0;
}