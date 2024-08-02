#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
#define repx(i, a, b) for(int i = int(a); i < int(b); i++)
#define rep(i, n) repx(i, 0, n)
typedef vector<ll> vl;


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    
    int n;
    cin >> n;

    int maxd = 0;
    int maxh = 0;
    int maxhx = 0;
    deque<tuple<int, int, int>> v;
    deque<tuple<int, int, int>>::iterator it = v.begin();
    deque<tuple<int, int, int>>::iterator p;
    

    int lasth = 0;
    int h;
    cin >> lasth;

    repx(i, 1, n) {
        cin >> h;
        if (h > lasth) {
            if (maxh == 0) break;
            if (h > maxh) {
                p = lower_bound(it, v.end(), maxhx);
                d = i - (get<0>(*p) + ((get<1>(*p) - h)/(get<1>(*p) - get<0>(*p))));
                if (d > maxd) maxd = d;
            }
            else {
                d = (i + calc_dist(make_tuple(i, h, lasth))) - maxhx;
                if (d > maxd) maxd = d;
            }
        }


    }


    return 0;
}
