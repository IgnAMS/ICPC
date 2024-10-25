#include<bits/stdc++.h>
using namespace std;

#define repx(i, a, b) for(int i = a; i < b; i++)
#define rep(i, n) repx(i, 0, n)
typedef long long ll;
typedef pair<ll, ll> pll;


ll to_num(string& s) {
    ll aux = 0;
    rep(i, s.length()) {
        aux *= 62;
        if('A' <= s[i] and s[i] <= 'Z') aux += (s[i] - 'A') + 10 + 26;
        else if('a' <= s[i] and s[i] <= 'z') aux += (s[i] - 'a') + 10;
        else aux += s[i] - '0';
    }
    return aux;
}


int main() {    
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    ll A[n];
    rep(i, n) {
        string s; cin>>s;
        A[i] = to_num(s);
    }


    ll aux = 0;
    rep(i, 2000000) {
        // valores posibles de k
        aux += ll(i) / 2 - (i) / 3;
    }
    cout<<aux<<'\n';





    return 0;
}

