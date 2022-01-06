#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = a; i < b; ++i)
#define invrep(i,b,a) for(int i = b; i >= a; --i)
using namespace std;

// - the input to the suffix array must be a vector of ints
struct SuffixArray {
    int n;
    vector<int> counts, rank, rank_tmp, sa, sa_tmp;
    vector<int> lcp; // optional: only if lcp is needed
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

    void compute_lcp(vector<int>& s) { // optional: only if lcp array is needed
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


int lower(vector<string>&v, int l, int r, char c, int ind){
    while(l<r){
        int m=(l+r)/2;
        if(v[m].size()<ind+1) l=m+1;
        else if(v[m][ind] < c) l=m+1; 
        else r=m;
    }
    return l;
}


int upper(vector<string>&v, int l, int r, char c, int ind){
    while(l<r){
        int m=(l+r)/2;
        if(v[m].size()<ind+1) l=m+1;
        else if(v[m][ind] <= c) l=m+1; 
        else r=m;
    }
    return l;
}



int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    string line1,line2; cin >> line1>>line2;
    vector<int> sv1,sv2;
    vector<string> v;
    int mini=1e6;

    for(char c :line1) sv1.push_back(c);
    SuffixArray sa(sv1);

    int n=sv1.size();
    rep(i,0,n){
        string aux="";
        int sup= i==0? sa.lcp[i]: max(sa.lcp[i],sa.lcp[i-1]);
        rep(j,0,sup) aux+=line1[j+sa.sa[i]];
        rep(j,sup,n-sa.sa[i]){
            aux+=line1[j+sa.sa[i]];
            cout<<aux<<"\n";
            v.push_back(aux);
        }
    }
    
    for(char c :line2) sv2.push_back(c);
    SuffixArray sa2(sv2);

    n=sv2.size();
    rep(i,0,n){
        string aux="";
        int sup= i==0? sa2.lcp[i]: max(sa2.lcp[i],sa2.lcp[i-1]);
        rep(j,0,sup){
            aux+=line2[j+sa2.sa[i]];
        }

        rep(j,sup,n-sa2.sa[i]){
            aux+=line2[j+sa2.sa[i]];
            cout<<aux<<"\n";
        }
    }
    

    if(mini==1e6) cout<<-1<<"\n";
    else cout<<mini<<"\n";
    
    return 0;
}