#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
#define repx(i, a, b) for(int i = (int)a; i < (int)b; i++)
#define rep(i, n) repx(i, 0, n)
#define ff first
#define ss second
typedef pair<ll, ll> pll;
typedef vector<ll> vl;


const double PI = acos(-1.0L);

const int mxN = 4e5+5, M = 1e9+7;

int main(){
    string s;
    cin >> s;
    int n, d;
    for(int i = 0; i<s.size(); ++i){
        if(s[i] == '/'){
            n = stoi(s.substr(0, i+1));
            d = stoi(s.substr(i+1, (int)s.size()-(i+1)));
        }
    }
    
    if (n + 1 < d) {
        cout << "impossible\n";
        return 0;
    }

    int on = n, od = d;

    vector<pair<int, int>> nodes;
    int cnt = 1;
    int sn = 0;
    int sd = 1;
    while (true) {
        if (sn + cnt >= n && sd + 1 < d) {
            break;
        }
        if (sd + 1 == d) {
            if (sn + cnt == n) {
                // done
                nodes.push_back({cnt + 1, cnt});
                sd++;
                sn += cnt;
                cnt++;
                break;
            }
            else {
                // amplificar fraccion
                n += on;
                d += od;
            }
        }
        nodes.push_back({cnt + 1, cnt});
        sn += cnt;
        sd++;
        cnt++;
    }
    while (sd < d - 1) {
        nodes.push_back({cnt + 1, 1});
        sn++;
        sd++;
        cnt++;
    }
    if (sn < n) {
        nodes.push_back({cnt + 1, n - sn});
        sn += n - sn;
        sd++;
        cnt++;
    }

    cout << cnt << " " << cnt - 1 << "\n";
    repx(i, 0, nodes.size()) {
        cout << nodes[i].first << " " << nodes[i].second << "\n";
    }
    return 0;
}

