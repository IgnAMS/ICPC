#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define repx(i, a, b) for(int i = a; i < int(b); i++)
#define rep(i, n) repx(i, 0, n)

typedef long long ll;

#define MOD 998244353

struct Node {    // (*) = Optional
 int len;     // length of substring
 int to[26];  // insertion edge for all characters a-z
 int link;    // maximun palindromic suffix
 int i;       // (*) start index of current Node
    int cnt;     // (*) # of occurrences of this substring
    Node(int len, int link=0, int i=0, int cnt=0): len(len),
    link(link), i(i), cnt(cnt) {memset(to, 0, sizeof(to));}
};

struct EerTree {    // Palindromic Tree
    vector<Node> t; // tree (max size of tree is n+2)
    int last;       // current node
    EerTree(string &s) : last(0) {
        t.emplace_back(-1); t.emplace_back(0); // root 1 & 2
        rep(i, s.size()) add(i, s);  // construct tree
        for(int i = t.size()-1; i > 1; i--) 
            t[t[i].link].cnt += t[i].cnt;
    }
    void add(int i, string &s){
        int p=last, c=s[i]-'0';
        while(s[i-t[p].len-1] != s[i]) p = t[p].link;
        if(t[p].to[c]){ last = t[p].to[c]; if(i >= s.size()/2) t[last].cnt++; }
        else{
            int q = t[p].link;
            while(s[i-t[q].len-1] != s[i]) q = t[q].link;
            q = max(1, t[q].to[c]);
            last = t[p].to[c] = t.size();
            t.emplace_back(t[p].len + 2, q, i-t[p].len-1);
            if(i >= s.size()/2) t.back().cnt++;
        }
    }
};

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;

    string s;
    cin >> s;
    s = s + s;
    EerTree pt(s);
    ll total = 0;
    repx(i, 2, pt.t.size()){
        if(pt.t[i].i < n && pt.t[i].len <= n){
            total += (((ll)pt.t[i].cnt*(ll)pt.t[i].cnt) % MOD) * (ll)pt.t[i].len;
            total %= MOD;
        }
    }
    cout << total << endl;
}
