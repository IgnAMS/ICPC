#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define repx(i, a, b) for (int i = a; i < b; i++)
#define rep(i, n) repx(i, 0, n)
typedef long long ll;
typedef pair<ll, ll> pll;
typedef double db;
typedef vector<ll> vl;
#define ff first
#define ss second
#define pb push_back
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
// ulimit -s 1000000
// g++ -O2 D.cpp && time ./a.out <input.txt> output.txt

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    set<ll> P2;
    rep(i, 20) P2.insert(1LL << i);

    int n, q;
    cin >> n >> q;
    ll A[n];
    rep(i, n) cin >> A[i];

    vl PrefP2(n + 1, 0);
    vl PrefImp(n + 1, 0);
    vl Pref1(n + 1, 0);

    rep(i, n)
    {
        PrefP2[i + 1] = PrefP2[i];
        PrefImp[i + 1] = PrefImp[i];
        Pref1[i + 1] = Pref1[i];
        if (P2.count(A[i]) and A[i] != 1)
            PrefP2[i + 1] += A[i];
        if ((A[i] & 1) and A[i] != 1)
            PrefImp[i + 1] += A[i];
        if (A[i] == 1)
            Pref1[i + 1]++;
    }

    // rep(i, n + 1) cout << PrefP2[i] << ' ';
    // cout << '\n';
    // rep(i, n + 1) cout << PrefImp[i] << ' ';
    // cout << '\n';
    // rep(i, n + 1) cout << Pref1[i] << ' ';
    // cout << '\n';

    rep(i, q)
    {
        int l, r;
        cin >> l >> r;
        ll v1 = PrefP2[r] - PrefP2[l - 1], v2 = PrefImp[r] - PrefImp[l - 1];
        if ((Pref1[r] - Pref1[l - 1]) & 1)
            v1++;

        // cout << PrefImp[4] << '\n';
        // cout << l << ' ' << r << ' ' << PrefImp[r] << ' ' << PrefImp[l - 1] << '\n';
        // cout << v1 << ' ' << v2 << '\n';
        if (v1 == v2)
            cout << "E\n";
        else if (v1 > v2)
            cout << "A\n";
        else
            cout << "B\n";
    }

    return 0;
}