#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define invrep(i,b,a) for(int i=b;i>=a;i--)
typedef long long ll;

struct SuffixArray {
    int n;
    vector<int> counts, rank, rank_tmp, sa, sa_tmp;
    vector<int> lcp;
    inline int get_rank(int i) { return i < n ? rank[i]: 0; }
    void counting_sort(int maxv, int k) {
        counts.assign(maxv+1, 0);
        rep(i,0,n) counts[get_rank(i+k)]++;
        rep(i,1,maxv+1) counts[i] += counts[i-1];
        invrep(i,n-1,0) sa_tmp[--counts[get_rank(sa[i]+k)]] = sa[i];
        sa.swap(sa_tmp);
    }
    void compute_sa(vector<int>& s) {
        rep(i,0,n) sa[i] = i;
        sort(sa.begin(), sa.end(), [&s](int i, int j) { return s[i] < s[j]; });
        int r = rank[sa[0]] = 1;
        rep(i,1,n) rank[sa[i]] = (s[sa[i]] != s[sa[i-1]]) ? ++r : r;
        for (int h=1; h < n and r < n; h <<= 1) {
            counting_sort(r, h);
            counting_sort(r, 0);
            r = rank_tmp[sa[0]] = 1;
            rep(i,1,n) {
                if (rank[sa[i]] != rank[sa[i-1]] or
                    get_rank(sa[i]+h) != get_rank(sa[i-1]+h)) ++r;
                rank_tmp[sa[i]] = r;
            }
            rank.swap(rank_tmp);
        }
    }
    void compute_lcp(vector<int>& s) {
        lcp.assign(n, 0);
        int k = 0;
        rep(i,0,n) {
            int r = rank[i]-1;
            if (r == n-1) { k = 0; continue; }
            int j = sa[r+1];
            while (i+k<n and j+k<n and s[i+k] == s[j+k]) k++;
            lcp[r] = k;
            if (k) k--;
        }
    }
    SuffixArray(vector<int>& s) {
        n = s.size();
        rank.resize(n); rank_tmp.resize(n);
        sa.resize(n); sa_tmp.resize(n);
        compute_sa(s);
        compute_lcp(s); // optional: only if lcp array is needed
    }
};


int upper(vector<int>& v, string& s, int l, int r, int ind){
    while(l<r){
        int m=(l+r)/2;
        if(v.size()-v[m] < ind+1) l=m+1;
        else if(s[v[m]+ind]<=s[ind])
            l=m+1;
        else r=m;
    }
    return l;
}

int lower(vector<int>&v, string& s, int l, int r, int ind){
    while(l<r){
        int m=(l+r)/2;
        if(v.size()-v[m] < ind+1) l=m+1;
        else if(s[v[m]+ind]<s[ind]) l=m+1; 
        else r=m;
    }
    return l;
}



int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin>>t;
    while(t--){
        string line; cin>>line;
        vector<int> s;
        for(auto& c : line) s.push_back(c);
        SuffixArray sa(s);

        ll l=0, r=line.length();
        ll ans=0;
        rep(i,0,line.length()){
            ll nextl=lower(sa.sa,line,l,r,i);
            ll nextr=upper(sa.sa,line,l,r,i);
            l=nextl, r=nextr;
            ans+=r-l;
        }
        cout<<ans<<"\n";
    }
    return 0;
}