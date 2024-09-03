#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef double db;
#define repx(i, a, b) for(int i = a; i < b; i++)
#define rep(i, n) repx(i, 0, n)



int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    string s;
    cin >> s;
    map<char, int> m;
    m['T'] = m['P'] = m['U'] = m['A'] = 0;
    repx(i, 0, s.length()) {    
        m[s[i]]++;
    }



    cout << min(m['T'], min(m['¨P'], m['U'] + m['A'])) << "\n";


    return 0;
}

