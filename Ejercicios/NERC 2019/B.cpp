#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;
#define rep(i, n) for(int i = 0; i < n; i++)
#define repx(i, a, b) for(int i = a; i < b; i++)
#define pb push_back


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    string s;

    cin >> s;

    int cnt = 0;
    int prev = s[0];
    vector<pair<int, int>> blocks;

    blocks.push_back({1, s[0]});

    repx(i, 1, s.length()) {
        if (s[i] != prev) {
            cnt++;
            prev = s[i];
            blocks.push_back({1, s[i]});
        }
        else {
            blocks[cnt].first++;
        }   
    }
    cnt++;

    // repx(i, 0, cnt) {
    //     cout << blocks[i] << " ";
    // }
    // cout << "\n";

    if (cnt % 2 == 0 || blocks[cnt / 2].first < 2) {
        cout << "0\n";
        return 0;
    }

    repx(i, 0, blocks.size() / 2) {
        if (blocks[i].first + blocks[blocks.size() - i - 1].first < 3 || blocks[i].second != blocks[blocks.size() - i - 1].second) {
            cout << "0\n";
            return 0;
        }
    }

    cout << blocks[cnt/2].first + 1 << "\n";

}