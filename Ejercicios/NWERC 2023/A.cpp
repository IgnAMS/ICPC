#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef double db;
#define repx(i, a, b) for(int i = a; i < b; i++)
#define rep(i, n) repx(i, 0, n)
#define ff first
#define pb push_back

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll n, s; cin>>n>>s;
    vl A(n); rep(i, n) cin>>A[i];

    if(s == 1 or n == 1) {
        cout<<1<<'\n';
        return 0;
    }


    sort(A.begin(), A.end());
    ll ans = 2;
    ll M1 = 0, M11 = 0, M2 = 0;
    s -= 2;

    rep(i, n - 2) {
        // cout<<A[i]<<' '<<s<<'\n';
        if(A[i] % 3 == 1) {
            if(M2 and s >= A[i] / 3) {
                M2--;
                ans++;
                s -= A[i] / 3;
            }
            else if(M1 and s >= (A[i] / 3)) {
                M11++;
                M1--;
                ans++;
                s -= (A[i] / 3);
            }
            else if(M1 == 0 and M2 == 0 and s >= (A[i] + 2) / 3) {
                M1++;
                ans++;
                s -= (A[i] + 2) / 3;
            }
        }
        else if(A[i] % 3 == 2) {
            if(M1 and s >= (A[i] / 3)) {
                M1--;
                ans++;
                s -= A[i] / 3;
            }
            else if(M11 and s >= (A[i] + 2) / 3) {
                M11--;
                M1++;
                s -= (A[i] + 2) / 3;
                ans++;
            }
            else if(M1 == 0 and M11 == 0 and s >= (A[i] + 2) / 3) {
                M2++;
                s -= (A[i] + 2) / 3;
                ans++;
            }
        }
        else if(A[i] % 3 == 0 and s >= A[i] / 3) {
            ans++;
            s -= A[i] / 3;
        }
        // cout<<M1<<' '<<M11<<' '<<M2<<' '<<s<<'\n';
    }
    cout<<ans<<'\n';

    return 0;
}