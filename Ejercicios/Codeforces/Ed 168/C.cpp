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
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        string s; cin>>s;
        ll curr = 0;
        ll R[n + 1];
        R[n] = 0;
        for(int i = n - 1; i >= 0; i--) {
            if(s[i] == ')') curr++;
            if(s[i] == '(') curr--;
            if(s[i] == '_') curr--; 
            curr = max(curr, 0LL);
            R[i] = max(R[i + 1], curr); 
        }

        // rep(i, n) cout<<R[i]<<' '; cout<<'\n';
        
        curr = 0;
        ll add = 0;
        rep(i, n) {
            // Caso contrario R[i] > 0
            if(s[i] == '_' and curr - R[i] <= 0) {
                s[i] = '(';
                curr++;
            }
            else if(s[i] == '_' and curr - R[i] > 0) {
                s[i] = ')';
                curr--;
            }
            else if(s[i] == '(') curr++;
            else if(s[i] == ')') curr--; 
        }
        vl Last;
        ll ans = 0;
        rep(i, n) {
            if(s[i] == '(') Last.pb(i);
            else {
                ans += i - Last.back();
                Last.pop_back();
            }
        }
        cout<<ans<<'\n';
        // cout<<s<<'\n';
    }

    return 0;
}