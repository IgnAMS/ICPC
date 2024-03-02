#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define rep(i, n) for(int i = 0; i<(int)n; ++i)

pair<int, string> ans = {0, ""};

struct Trie{
    static const int mxN = 5e6+5;
    int N[mxN][26] = {0}, freq[mxN] = {0}, c = 0;
    void add(string &s, int a = 1){
        int p = 0;

        rep(i, s.size()){
            int t = s[i] - 'a';
            if(!N[p][t]) N[p][t] = ++c;
            p = N[p][t];
            if(i == s.size()-1){
                freq[p] += a;
                if(freq[p] > ans.first){
                    ans = {freq[p], s};
                }else if(freq[p] == ans.first){
                    if(s < ans.second){
                        ans = {freq[p], s};
                    }
                }
            }
        }
    }
}trie;
int n, c;


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> c;
    rep(i, n){
        string s;
        cin >> s;
        rep(j, s.size()){
            if(s[j] == '*'){
                rep(k, 26){
                    s[j] = 'a'+k;
                    trie.add(s);
                }
                break;
            }
        }
    }
    cout << ans.second << " " << ans.first << '\n';
}