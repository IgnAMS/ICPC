#include <bits/stdc++.h>
using namespace std;
 
#pragma region header
typedef long long ll;
template <typename Value>
using vec = vector<Value>;
istream &in = cin;
ostream &out = cout;
#define all(x) x.begin(), x.end()
#define fast() cin.tie(0); ios_base::sync_with_stdio(0)
#pragma endregion
 
void solve()
{
    int n; in >> n;
    vec<int> x(n);
    for (int i = 0; i < n; i++) {
        in >> x[i];
    }
    vec<int> diff(n-1);
    for (int i = 0; i < n-1; i++) {
        diff[i] = abs(x[i] - x[i+1]) - 1;
    }
    
    int ones = 0;
    int twos = 0;
    for (int i = 0; i < n-1; i++) {
        if (diff[i] == 2) {
            twos++;
        } else if (diff[i] == 1) {
            ones++;
        } else if (diff[i] != 0) {
            out << "NO" << endl;
            return;
        }
    }
    if (twos == 1 && ones == 0) {
        out << "YES" << endl;
    } else if (ones <= 2 && twos == 0) {
        out << "YES" << endl;
    } else if (ones == 0 && twos == 0) {
        out << "YES" << endl;
    } else {
        out << "NO" << endl;
    }
}
 
int main()
{
    fast();
    // solve(); return 0;
    int t; in >> t;
    while (t--) {
        solve();
    }
}