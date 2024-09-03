#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef double db;
#define repx(i, a, b) for(int i = a; i < b; i++)
#define rep(i, n) repx(i, 0, n)
#define pb push_back

void solve(){
    ll n, x;
    cin >> n >> x;
    
    vl a(n);
    ll mid = 0;
    repx(i, 0, n) {
        cin >> a[i];
        if (2*a[i] == x) mid++;
    }
    sort(a.begin(), a.end());

    if (mid >= 2) {
        ll midstart = lower_bound(a.begin(), a.end(), x/2) - a.begin();
        if (2*mid > n + 1) {
            cout << "*\n";
            return;
        }
        if (midstart - mid + 1 >= 0) {
            repx(i, 0, midstart - mid + 1) {
                cout << a[i] << " ";
            }
            repx(i, midstart - mid + 1, midstart) {
                cout << x/2 << " " << a[i] << " ";
            }
            cout << x/2 << " ";
            repx(i, midstart + mid, n) {
                cout << a[i] << " ";
            }
        }
        else if (2*mid == n + 1) {
            repx(i, 0, midstart) {
                cout << x/2 << " " << a[i] << " ";
            }
            repx(i, midstart + mid, n) {
                cout << x/2 << " " << a[i] << " ";
            }
            cout << x/2 << "\n";
        }
        else {
            repx(i, 0, midstart) {
                cout << x/2 << " " << a[i] << " ";
            }
            repx(i, midstart + mid, midstart + mid + (mid - midstart)) {
                cout << x/2 << " " << a[i] << " ";
            }
            repx(i, midstart + mid + (mid - midstart), n) {
                cout << a[i] << " ";
            }
        }
    }
    else {
        repx(i, 1, n) {
            if (a[i] + a[i - 1] == x) {
                if (a[0] != a[i - 1]) {
                    repx(j, 1, i) {
                        cout << a[j] << " ";
                    }
                    cout << a[0] << " ";
                    repx(j, i, n) {
                        cout << a[j] << " ";
                    }
                }
                else if (a[n - 1] != a[i]) {
                    repx(j, 0, i) {
                        cout << a[j] << " ";
                    }
                    cout << a[n - 1] << " ";
                    repx(j, i, n - 1) {
                        cout << a[j] << " ";
                    }
                }
                else {
                    cout << "*\n";
                }
                return;
            }
        }
        repx(i, 0, n) {
            cout << a[i] << " ";
        }
    }

    
    

}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    solve();

    return 0;
}

