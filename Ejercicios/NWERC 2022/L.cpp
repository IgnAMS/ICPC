#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
#define repx(i, a, b) for(int i = (int)a; i < (int)b; i++)
#define rep(i, n) repx(i, 0, n)
#define ff first
#define ss second
typedef pair<ll, ll> pll;


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    // repx(i, 3, 5) cout<<i<<'\n';
    int g, l;
    cin >> g >> l;

    unordered_set<int> inv, used, to_use;
    vector<int> ans(l, 0);
    vector<unordered_set<int>> inv_pos(l, unordered_set<int>());
    string s, t;
    repx(j, 0, g - 1) {
        cin >> s >> t;
        repx(i, 0, l) {
            if (t[i] == 'G') {
                ans[i] = s[i];
                used.insert(s[i]);
                if(to_use.count(s[i]) != 0) {
                    to_use.erase(s[i]);
                }
            }
            else if (t[i] == 'B') {
                inv.insert(s[i]);
            }
            else if (t[i] == 'Y') {
                inv_pos[i].insert(s[i]);
                if (used.count(s[i]) == 0) {
                    to_use.insert(s[i]);
                }
            }
        }
    }

    bool done;
    repx(i, 0, l) {
        if (ans[i] == 0) {
            done = false;
            for (unordered_set<int>::iterator it = to_use.begin(); it != to_use.end(); it++) {
                if (inv_pos[i].count(*it) + inv.count(*it) == 0) {
                    ans[i] = *it;
                    to_use.erase(*it);
                    used.insert(*it);
                    done = true;
                    break;
                }
            }
            if (!done) {
                repx(j, 0, 26) {
                    if (inv_pos[i].count(j + 'a') + inv.count(j + 'a') == 0) {
                        ans[i] = j + 'a';
                        to_use.erase(ans[i]);
                        used.insert(ans[i]);
                        break;
                    }
                }
            }
        }
        cout << (char)ans[i];
    }
    cout << "\n";

    return 0;
}