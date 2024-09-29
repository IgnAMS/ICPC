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


ll solve(string &s, ll l, ll r) {
    if(r - l == 0) {
        if(s[l] == 'a') return 1;
        return 0;
    }

    ll ans = 0;
    ll m = (l + r) / 2;
    ans += solve(s, l, m) + solve(s, m + 1, r);
    vl X(r - l + 2, 0);
    
    ll curr = 0, curr2 = 0, index = l;
    for(int i = m; i >= l; i--) {
        if(s[i] == ')') curr--, curr2++;
        if(s[i] == '(') curr++, curr2--;
        if(curr2 < 0) curr2 = 0;
        if((s[i] == '(' or s[i] == 'a') and curr >= 0 and curr2 == 0) X[curr]++; 
    }

    curr = 0, curr2 = 0;
    // cout<<"left: ";
    // for(int i = l; i <= m; i++) cout<<s[i]; cout<<", right: ";
    // for(int i = m+1; i <= r; i++) cout<<s[i]; cout<<'\n';
    for(int i = m + 1; i <= r; i++) {
        if(s[i] == ')') curr++, curr2--;
        if(s[i] == '(') curr--, curr2++;
        if(curr2 < 0) curr2 = 0;
        if((s[i] == ')' or s[i] == 'a') and curr >= 0 and curr2 == 0) {
            // cout<<"en "<<i<<" aumento en "<<X[curr]<<'\n';
            ans += X[curr];
        }
    }
    // cout<<'\n';
    return ans;
}


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    string s; cin>>s;
    rep(i, (int)s.length()) {
        if(s[i] == '+' or s[i] == '-' or s[i] == '*' or s[i] == '/') s[i] = '+';
        else if(s[i] == '(' or s[i] == ')') s[i] = s[i];
        else s[i] = 'a';
    }
    vector<string> S;
    string aux = "";
    rep(i, (int)s.length()) {
        aux += s[i];
        if(aux.length() >= 2) {
            int largo = aux.length();
            char x = aux[largo - 1];
            if(
                (aux[largo - 2] == '(' and aux[largo - 1] == ')') or
                (aux[largo - 2] == '(' and aux[largo - 1] == '+') or
                (aux[largo - 2] == '+' and aux[largo - 1] == ')') or
                (aux[largo - 2] == '+' and aux[largo - 1] == '+') or
                (aux[largo - 2] == ')' and aux[largo - 1] == '(') or
                (aux[largo - 2] == ')' and aux[largo - 1] == 'a') or
                (aux[largo - 2] == 'a' and aux[largo - 1] == '(')     
            ) {
                aux.pop_back();
                S.pb(aux);
                aux = "";
                aux += x;
            }
        }
    }
    S.pb(aux);

    ll ans = 0;
    for(auto s2: S) {
        // cout<<"string a revisar: "<<s2<<'\n';
        ll x = solve(s2, 0, s2.length() - 1); 
        // cout<<x<<'\n';
        // cout<<"\n\n";
        ans += x;
    }
    cout<<ans<<'\n';

    return 0;
}