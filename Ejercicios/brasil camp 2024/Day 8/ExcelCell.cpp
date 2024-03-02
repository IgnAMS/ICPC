#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
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

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll r, c; cin>>r>>c;
    int q; cin>>q;
    while(q--) {
        string s; cin>>s;
        int n = s.length();
        // query del tipo 1 que es transformarlo a 
        if('A' <= s[0] and s[0] <= 'Z') {
            int indnum = 0;
            ll col = 0;
            rep(i, n) {
                if(!('A' <= s[i] and s[i] <= 'Z')) {
                    indnum = i;
                    break;
                }
                col = col * 26 + ll(s[i] - 'A') + 1;
            }
            ll row = 0;
            repx(i, indnum, n) {
                row = row * 10 + ll(s[i] - '0');
            }
            cout<<(row - 1) * c + col<<'\n';
        }
        else {
            ll num = 0;
            rep(i, n) num = num * 10 + ll(s[i] - '0');
            ll row = (num - 1) / c + 1;
            ll col = num - (row - 1) * c;
            string ans = "";
            while(col) {
                ans += char('A' + ((col - 1 + 26) % 26));
                if(col % 26 == 0) col--;
                col /= 26;
            }
            reverse(ans.begin(), ans.end());
            cout<<ans<<row<<'\n';
        }
    }

    // repx(col2, 1, 65535 + 1) {
    //     ll col = col2;
    //     string ans = "";
    //     while(col) {
    //         ans += char('A' + ((col - 1 + 26) % 26));
    //         if(col % 26 == 0) col--;
    //         col /= 26;
    //     }
    //     reverse(ans.begin(), ans.end());
    //     cout<<ans<<'\n';
    // }

    return 0;
}