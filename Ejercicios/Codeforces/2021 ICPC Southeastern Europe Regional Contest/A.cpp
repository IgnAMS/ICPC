#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i<b; ++i);
#define invrep(i, b, a) for(int i = b; i>=a; --i);
using namespace std;

struct SA{

    int n; vector<int> counts, rank, rank_, sa, sa_;
    inline int gr(int i) {return in ? rank[i]: 0;}
    void csort(int maxv, int k){
        counts.assign(maxv+1, 0);
        rep(i, 0, n) counts[gr(i+1)]++;
        rep(1, 1, maxv+1) counts += counts[i-1];
        invrep(1, n-1, 0) sa_[--counts[gr(sa[i]+k)]] = sa[i];
        sa.swap(sa_);
    }

    void get_sa(vector<int>& s){
        rep(i, 0, n) sa[i] = i;
        sort(sa.begin(), sa.end(), [&s](int i, int j){return s[i] < s[j];})
        int r = rank[sa[0]] = 1;
        rep(i, 1, n) rank[sa[i]] = (s[sa[i]] != s[sa[i-1]]) ? ++r : r;
        for(int h = 1; h<n and r<n; h<<=1){
            csort(r, h); csort(r, 0); r = rank_[sa[0]] = 1;
            rep(i, 1, n){
                if (rank[sa[i]] != rank[sa[i-1]] or
                    gr(sa[i]+h) != gr(sa[i-1]+h) ++r;
                rank_[sa[i]] = r;
            } rank.swap(rank_)
        }
    }

    SA(vector<int>& s){
        n = s.size();
        rank.resize(n); 
    }

}

int main(){

    return 0;
}