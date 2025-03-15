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
    int k; string s; cin>>k>>s;
    int n = s.length();

    if(k == 2) {
        string s1 = "", s2 = "";
        rep(i, n) s1 += char((i % 2) + '0');
        rep(i, n) s2 += char(((i+1) % 2) + '0');
        ll d1 = 0, d2 = 0;
        rep(i, n) {
            if(s[i] != s1[i]) d1++;
            else d2++;
        }
        if(d1 < d2) cout<<d1<<' '<<s1<<'\n';
        else cout<<d2<<' '<<s2<<'\n';
    }
    else {
        ll curr = 1;
        ll ans = 0;
        repx(i, 1, n) {
            if(s[i] == s[i - 1]) curr++;
            else curr = 1;

            if(curr == k and i + 1 < n and s[i + 1] != s[i]) {
                s[i - 1] = (s[i - 1] == '1'? '0': '1');
                curr = 1;
                ans++;
            }
            else if(curr == k) {
                s[i] = (s[i] == '1'? '0': '1');
                curr = 1;
                ans++;
            }
        }
        cout<<ans<<' '<<s<<'\n';
    }



    return 0;
}