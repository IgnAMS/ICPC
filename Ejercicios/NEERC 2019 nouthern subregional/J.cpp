#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>

using namespace std;
#define repx(i, a, b) for(int i = a; i < b; i++)
#define rep(i, n) repx(i, 0, n)
typedef long long ll;
typedef vector<ll> vl;
typedef pair<ll, ll> pll;
#define pb push_back


// g++ -O2 A.cpp && time ./a.out <input.txt> output.txt

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n;
    cin >> n;

    vector<vector<int>> mat(n, vector<int>(n));

    repx(i, 0, n) {
        string s;
        cin >> s;
        repx(j, 0, n) {
            mat[i][j] = s[j] - '0';
        }
    }
    repx(i, 0, n) {
        repx(j, i + 1, n) {
            if (!mat[i][j]) continue;
            repx(k, j + 1, n) {
                mat[i][k] = (mat[i][k] - mat[j][k] + 10) % 10;
            }
        }
    }

    repx(i, 0, n) {
        repx(j, 0, n) {
            cout << mat[i][j];
        }
        cout << endl;
    }

    return 0;
}


