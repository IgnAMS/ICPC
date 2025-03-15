#include <bits/stdc++.h>
using namespace std;

using ul = unsigned long long;
using ll = long long;
using db = double;

using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<db, db>;

using vp = vector<pii>;
using vi = vector<int>;
using vl = vector<ll>;
using vd = vector<db>;

using vvp = vector<vp>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using vvd = vector<vd>;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repx(i, a, b) for (int i = (int)a; i < (int)b; i++)
#define all(x) begin(x), end(x)
#define sz(x) ((int)(x).size())
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

int H, M, A, B, X, Y, Q, Ang;
char c;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> H >> c >> M;
    H *= 30;
    M *= 6;
    // cerr << H << ' ' << M << endl;

    cin >> Q;

    cin >> A >> B >> X >> Y;

    int ans = 0;
    rep(_, Q)
    {
        cin >> Ang;

        int NH, NM;

        int now = INT_MAX;
        for (int dH = -11; dH <= 0; dH++)
        {
            int bC = abs(dH) * 30 * X * B;
            int HH = (H < M ? 360 : 0) + H + dH * 30;
            int MM = M;
            int cc = 0;
            while (MM < HH)
            {
                int C = bC + cc * Y * A;
                // if (C == 0) cerr << HH << ' ' << MM << ' ' << HH - MM << ' ' << C << ' ' << dH << endl;
                if (HH - MM == Ang && C < now) now = C, NH = HH, NM = MM;
                if (360 - (HH - MM) == Ang && C < now) now = C, NH = HH, NM = MM;
                MM++, cc++;
            }
        }

        for (int dH = 0; dH <= 11; dH++)
        {
            int bC = abs(dH) * 30 * X * A;
            int HH = H + dH * 30;
            int MM = (M < H ? 360 : 0) + M;
            int cc = 0;
            while (MM > HH)
            {
                int C = bC + cc * Y * B;
                // if (C == 0) cerr << HH << ' ' << MM << ' ' << MM - HH << ' ' << C << endl;
                if (MM - HH == Ang && C < now) now = C, NH = HH, NM = MM;
                if (360 - (MM - HH) == Ang && C < now) now = C, NH = HH, NM = MM;
                MM--, cc++;
            }
        }

        ans += now;
        if (NH >= 360) NH -= 360;
        if (NM >= 360) NM -= 360;
        H = NH, M = NM;

        // cerr << now << endl;
    }

    cout << ans << '\n';
}
