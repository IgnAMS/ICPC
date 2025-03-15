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

    if(n == 1) {
        cout<<"0\n";
        return 0;
    }
    if(n == 2) {
        cout<<"00\n";
        return 0;
    }


    string ans = "00";
    ll k = 1;
    repx(i, 2, n) {
        for(int j = 0; j <= i - 2 * k; j++) {
            cout<<A[j]<<' '<<A[j + 2 * k]<<' '<<2 * A[j + k]<<'\n';
        }
        cout<<'\n';
        
        if(A[i - 2 * k] + A[i] == 2 * A[i - k]) {
            ans += '1';
            continue;
        }
        
        k++;
        while(k <= i / 2) {
            bool pos = 1;
            for(int j = 0; j <= i - 2 * k; j++) {
                if(A[j] + A[j + 2 * k] != 2 * A[j + k]) {
                    pos = 0;
                    break;
                }
            }
            if(pos) break;
            k++;
        }
        if(k == i / 2 + 1) ans += '0';
        else ans += '1';
    }

    cout<<ans<<'\n';

    return 0;
}

