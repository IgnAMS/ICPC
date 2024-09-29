#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef pair<ll, ll> pll;
#define repx(i, a, b) for(int i = a; i < b; i++)
#define rep(i, n) repx(i, 0, n)



int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    string m, n; cin>>m>>n;
    vl indM;
    vl indN;

    rep(i, m.size()) if(m[i] == '*') indM.push_back(i);
    rep(i, n.size()) if(n[i] == '*') indN.push_back(i);

    string ans;
    rep(mask, (1<<indM.size())) {
        rep(mask2, (1<<indN.size())) {
            rep(i, indM.size()) m[indM[i]] = (mask & (1<<i)? '1': '0');
            rep(i, indN.size()) n[indN[i]] = (mask2 & (1<<i)? '1': '0');
            ll num = 0;
            rep(i, n.size()) {
                num += ll(n[n.size() - i - 1] == '1') * (1<<i);
            }
            ll pot = 1;
            ll mod = 0;
            rep(i, m.size()) {
                mod += pot * ll(m[m.size() - i - 1] == '1');
                pot *= 2;
                if(pot >= num) pot -= num;
            }
            if(mod % num == 0) {
                ans = m;
                break;
            }
        }
    }
    cout<<ans<<'\n';


    return 0;
}