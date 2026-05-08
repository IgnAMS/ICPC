#pragma GCC optimize("Ofast")
#include<string.h>
#include<vector>
#include<map>
#include<deque>
#include<queue>
#include<iostream>
#include<algorithm>
#include<numeric>
#include <unordered_map>
#include <cmath>
#include<set>
#include<array>
using namespace std;
// g++ -std=c++17 F2.cpp -o a && ./a <input.txt> output.txt   
// ulimit -s 1000000
// g++ -std=c++17 -O2 F2.cpp && time ./a.out <input.txt> output.txt

#define ll long long
#define rep(i, n) for(int i = 0; i < (int)n; ++i)

pair<int, string> ans = {0, ""};

int n, c;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>c;

    unordered_map<string, int> mp;
    mp.reserve(26 * n);
    rep(i, n) {
        string s;
        cin >> s;

        rep(j, s.size()) {
            if (s[j] == '*') {
                char old = s[j];
                rep(k, 26) {
                    s[j] = char('a' + k);
                    int f = ++mp[s];
                    if (f > ans.first) {
                        ans = {f, s};
                    }
                    else if (f == ans.first && s < ans.second) {
                        ans = {f, s};
                    }
                }
                s[j] = old;
                break;
            }
        }
    }

    cout<<ans.second<<" "<<ans.first<<'\n';
}