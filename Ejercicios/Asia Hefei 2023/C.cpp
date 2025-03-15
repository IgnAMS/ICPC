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
// g++ -O2 C.cpp && time ./a.out <input.txt> output.txt

const ll MOD = 998244353;

struct Node {    // (*) = Optional
    int len;     // length of substring
    int to[10];  // insertion edge for all characters a-z
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
        for(int i = t.size() - 1; i > 1; i--) 
            t[t[i].link].cnt += t[i].cnt;
    }
    void add(int i, string &s){         // vangrind warning:
        int p=last, c= s[i]-'0';         // i-t[p].len-1 = -1
        while(s[i-t[p].len-1] != s[i]) p = t[p].link;
        if(t[p].to[c]){ last = t[p].to[c]; if(i >= s.size()/2) t[last].cnt++; }
        else{
            int q = t[p].link;
            while(s[i-t[q].len-1] != s[i]) q = t[q].link;
            q = max(1, t[q].to[c]);
            last = t[p].to[c] = t.size();
            if(i >= s.size() / 2) t.emplace_back(t[p].len + 2, q, i-t[p].len-1, 1);
            else t.emplace_back(t[p].len + 2, q, i-t[p].len-1, 0);
        }
    }
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n; cin>>n;
    string s; cin>>s;
    string s2 = s + s;
    EerTree pt(s2);

    ll ans = 0;
    repx(i, 2, pt.t.size()) {
        // cout<<pt.t[i].i<<' '<<pt.t[i].len<<' '<<s2.substr(pt.t[i].i, pt.t[i].len)<<' '<<pt.t[i].cnt<<'\n';
        if(pt.t[i].i < n and pt.t[i].len <= n) {
            ll val = pt.t[i].cnt;
            // cout<<"el string "<<s2.substr(pt.t[i].i, pt.t[i].len)<<" aparece "<<val<<" veces\n";
            ans += (val * val % MOD) * 1LL * pt.t[i].len % MOD;
            ans %= MOD;
        }
    }
    cout<<ans<<'\n';
    return 0;
}