#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
#define repx(i, a, b) for(int i = int(a); i < int(b); i++)
#define rep(i, n) repx(i, 0, n)
typedef vector<ll> vl;

bool comp(tuple<int, int, string> t1, tuple<int, int, string> t2) {
    if (get<0>(t1) == get<0>(t2)) return get<1>(t1) < get<1>(t2);
    return get<0>(t1) > get<0>(t2);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    
    int n;
    cin >> n;
    string c;
    int p, max, min, sum;
    vl e(6);

    vector<tuple<int, int, string>> m(n);
    repx(i, 0, n) {
        cin >> c >> p;
        max = 0;
        min = 10;
        sum = 0;
        repx(j, 0, 6) {
            cin >> e[j];
            sum += e[j];
            if (e[j] > max) max = e[j];
            if (e[j] < min) min = e[j];
        }
        m[i] = make_tuple(10*p + sum - max - min, i, c);
    }

    sort(m.begin(), m.end(), comp);

    int count = 0;
    int score;
    unordered_map<int, int> sm;
    int score1 = -1;
    int score2 = -1;
    int score3 = -1;

    while(count < m.size() && count < 1000) {
        score = get<0>(m[count]);
    
        if (score1 == -1) {
            score1 = score;
        }
        else if (score2 == -1 && score != score1) {
            if (sm[score1] > 2) break;
            score2 = score;
        }
        else if (score2 != -1 && score3 == -1 && score != score2) {
            if (sm[score1] + sm[score2] > 2) break;
            score3 = score;
        }

        sm[score]++;

        cout << get<2>(m[count]) << " " << score << "\n";

        count++;
    }

    return 0;
        
}
