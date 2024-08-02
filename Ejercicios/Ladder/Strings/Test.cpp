#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<ll, ll> pll;
typedef double db;
typedef vector<int> vl;
#define ff first
#define ss second
#define pb push_back
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
// ulimit -s 1000000
// g++ -O2 D.cpp && time ./a.out <input.txt> output.txt

vl KMP(string& p) {
    int n = p.size();
    vl L(n); L[0] = 0;
    rep(j, n - 1) {
        int i = L[j]; 
        while (p[i] != p[j + 1] && i) i = L[i - 1];
        L[j + 1] = (p[i] == p[j + 1] ? i + 1 : 0);
    }
    return L;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    string S[3];
    while(cin>>S[0]) {
        cin>>S[1]>>S[2];

        vector<vl> kmp(3, vl());
        rep(i, 3) kmp[i] = KMP(S[i]);
        ll ans = 2e6;
        vl P = {0, 1, 2};
        do {
            int I[3] = {0, 0, 0};
            ll cont = 0;
            bool Completed[] = {0, 0, 0};
            rep(i, 3) {
                if(Completed[P[i]]) continue;
                repx(j, I[P[i]], S[P[i]].length()) {
                    cont++;
                    rep(k, 3) {
                        int &ind = I[P[k]];
                        while(S[P[k]][ind] != S[P[i]][j] and ind) ind = kmp[P[k]][ind - 1];
                        if(S[P[k]][ind] == S[P[i]][j] and ++ind == S[P[k]].length()) {
                            ind = kmp[P[k]][S[P[k]].length() - 1];
                            Completed[P[k]] = 1;
                        }
                    }
                }
            }
            ans = min(ans, cont);
        } while(next_permutation(P.begin(), P.end()));
        cout<<ans<<'\n';
    }


    return 0;
}