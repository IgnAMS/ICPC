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

template<const int LIM, const int MOD, const int BASE>
struct Hash {
    vector<int> H, P;
 
    int binpow(int a, int b) {
        int res = 1;
        while(b) {
            if(b & 1) res = (1LL * res * a) % MOD;
            a = (1LL * a * a) % MOD;
            b >>= 1;
        }
        return res;
    }
 
    void init(const string& s) {
        int n = s.length(), b = 1;
        H.resize(n + 1); P.resize(n + 1);
        
        H[0] = 0;
        rep(i, n) {
            H[i + 1] = (H[i] + 1LL * b * (s[i] - 'a' + 1)) % MOD;
            b = (1LL * b * BASE) % MOD;
        }
        P[n] = binpow(b, MOD - 2);
        for(int i = n - 1; i >= 0; i--) P[i] = (1LL * P[i + 1] * BASE) % MOD; 
    }
    int query(int l, int r) { return (1LL * (H[r] - H[l] + MOD) * P[l]) % MOD; }
};


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    bool xd = (t == 100000);
    Hash<1000002, 1000000007, 122> H;
    Hash<1000002, 1000000007, 122> revH; 
    while(t--) {
        string s; cin>>s;
        int n = s.length();
        vector<int> d1(n), d2(n);
        for (int i = 0, l = 0, r = -1; i < n; i++) {
            int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
            while(0 <= i - k && i + k < n && s[i - k] == s[i + k]) k++;
            d1[i] = k--;
            if (i + k > r) l = i - k, r = i + k;
        }
        for(int i = 0, l = 0, r = -1; i < n; i++) {
            int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);
            while(0 <= i - k - 1 && i + k < n && s[i - k - 1] == s[i + k]) k++;
            d2[i] = k--;
            if (i + k > r) l = i - k - 1, r = i + k;
        }
        string revs = s;
        reverse(revs.begin(), revs.end());
        H.init(s);
        revH.init(revs); 
        
        pll best_imp = {0, 0};
        rep(i, n) {
            if(i < (n  + 1) / 2) {
                int pref = i - d1[i];
                if(pref >= 0 and H.query(0, pref + 1) == revH.query(0, pref + 1)) {
                    if(best_imp.ss < i) best_imp = {i, i};
                }
                if(pref == -1 and best_imp.ss < i) best_imp = {i, i};
            }
            else {
                int suf = i + d1[i];
                if(suf < n and H.query(suf, n) == revH.query(suf, n)) {
                    if(best_imp.ss < n - i - 1) best_imp = {i, n - i - 1};
                }
                if(suf == n and best_imp.ss < n - i - 1) best_imp = {i, n - i - 1}; 
            }
        }

        pll best_par = {0, -1};
        rep(i, n) {
            if(i < (n + 1) / 2) {
                if(d2[i] == 0) {
                    if(H.query(0, i + 1) == revH.query(0, i + 1)) {
                        if(best_par.ss < i) best_par = {i, i};
                    }
                    continue;
                }
                int pref = i - d2[i] - 1;
                if(pref >= 0 and H.query(0, pref + 1) == revH.query(0, pref + 1)) {
                    if(best_par.ss < i) best_par = {i, i};
                }
                if(pref == -1 and best_par.ss < i) best_par = {i, i};
            }
            else {
                if(d2[i] == 0) {
                    if(H.query(i, n) == revH.query(i, n)) {
                        // cout<<"entre aca xd\n";
                        // cout<<revs.substr(i, n - i - 1)<<'\n';
                        // cout<<s.substr(i, n - i - 1)<<'\n';
                        if(best_par.ss < n - i) best_par = {i, n - i};
                    }
                    continue;
                }
                int suf = i + d2[i];
                // cout<<"entre aca "<<i<<' '<<suf<<' '<<(n == suf)<<' '<<n - i<<'\n';
                if(suf < n and H.query(suf, n) == revH.query(suf, n)) {
                    if(best_par.ss < n - i) best_par = {i, n - i};
                }
                if(suf == n and best_par.ss < n - i) best_par = {i, n - i};
            }
        }
        // cout<<best_imp.ff<<' '<<best_imp.ss<<'\n';
        // cout<<best_par.ff<<' '<<best_par.ss<<'\n';
        string ans = "";
        if(best_imp.ss * 2 + 1 >= 2 * best_par.ss) {
            string aux;
            if(best_imp.ff < (n + 1) / 2) aux = s.substr(0, best_imp.ss + 1);
            else {
                aux = s.substr(best_imp.ff, best_imp.ss + 1);
                reverse(aux.begin(), aux.end());
            }
            ans += aux;
            aux.pop_back();
            reverse(aux.begin(), aux.end());
            ans += aux;
        }
        else {
            string aux;
            if(best_par.ff < (n + 1) / 2) aux = s.substr(0, best_par.ff);
            else {
                aux = s.substr(best_par.ff, best_par.ss);
                reverse(aux.begin(), aux.end());
            }
            
            ans += aux;
            reverse(aux.begin(), aux.end());
            ans += aux;
        }
        cout<<ans<<'\n';
    }

    return 0;
}