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
// g++ -O2 D.cpp && time ./a.out < input.txt > output.txt

struct SA{
    int n; vi C, R, R_, sa, sa_, lcp;
    inline int gr(int i) { return i < n ? R[i] : 0; }
    void csort(int maxv, int k){
        C.assign(maxv + 1, 0);
        rep(i, n) C[gr(i + k)]++;
        repx(i, 1, maxv + 1) C[i] += C[i - 1];
        for (int i = (int)n - 1; i >= 0; i--) sa_[--C[gr(sa[i] + k)]] = sa[i];
        sa.swap(sa_);
    }
    void getSA(vi& s){
        R = R_ = sa = sa_ = vi(n); rep(i, n) sa[i] = i;
        sort(sa.begin(), sa.end(), [&s](int i, int j) { return s[i] < s[j]; });
        int r = R[sa[0]] = 1;
        repx(i, 1, n) R[sa[i]] = (s[sa[i]] != s[sa[i - 1]]) ? ++r : r;
        for (int h = 1; h < n && r < n; h <<= 1){
            csort(r, h); csort(r, 0); r = R_[sa[0]] = 1;
            repx(i, 1, n){
                if (R[sa[i]] != R[sa[i - 1]] || gr(sa[i] + h) != gr(sa[i - 1] + h)) r++;
                R_[sa[i]] = r;
            } R.swap(R_);
        }
    }
    void getLCP(vi &s){
        lcp.assign(n, 0); int k = 0;
        rep(i, n){
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
    int n; cin>>n;
    vector<vector<ll>> V(n);
    rep(i, n){
        int k; cin>>k; V[i].resize(k); rep(i, k) cin>>V[i][k];
    }

    vi super_largo;
    rep(i, n){
        rep(k, V[i].size()) super_largo.push_back(V[i][k]);
        super_largo.push_back(0);
    }
    SA suffix(super_largo);
    vi as; for(auto it = suffix.sa.rbegin(); it != suffix.sa.rend(); it++) as.push_back(*it);

    
    set<vi> S;
    ll acc = 0; 
    vi cont(n, 0);
    rep(i, n) {
        S.insert({as[acc], i, 0});
        cont[i] = acc;
        acc += V[i].size() + 1;
    }
    vector<ii> Ans;
    while(!S.empty()){
        int x = (*S.begin())[0], i = (*S.begin())[1], j = (*S.begin())[2]; 
        Ans.push_back({i, j});
        S.erase(S.begin());
        if(j == V[i].size() - 1) continue;
        S.insert({as[cont[i] + j + 1], i, j + 1});
    }
    
    rep(i, Ans.size()) cout<<V[Ans[i].ff][Ans[i].ss]<<' ';


    return 0;
}