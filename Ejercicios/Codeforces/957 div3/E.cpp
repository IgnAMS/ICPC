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
    vector<pll> Ans[101];
    ll pot10 = 1;
    repx(i, 1, 100) { // 10^2
        ll n = i;
        string s = "";
        string sn = to_string(i);
        if(i == 10 or i == 100) pot10++;
        repx(a, 1, 10001) { // 10^4
            s += sn;
            // Los valores que me sirven de b cumplen que:
            // 1 <= pot10 * a - b <= 6
            // b <= pot10 * a - 1
            // 6 - pot10 * a <= b
            for(ll b = max(1LL, pot10 * a - 6); b <= pot10 * a - 1 and b <= min(10000LL, a * n); b++) {
                ll res = n * a - b;
            
                if(res == 0) continue;

                ll logres = log10(res) + 1e-9 + 1;
                // El string queda vacio o me queda mas grande
                // cout<<n<<' '<<a<<' '<<b<<' '<<res<<' '<<pot10 * a - b<<' '<<logres<<'\n';
                if(pot10 * a - b != logres) continue; 
                // Nota: res tiene a lo mas 6 digitos 
                bool oc = 1;
                for(int j = logres - 1; j >= 0; j--) {
                    if((s[j] - '0') != res % 10) oc = 0; 
                    res /= 10;
                }
                if(oc) Ans[i].pb({a, b});
            }
        }
    }

    while(t--) {
        int n; cin>>n;
        cout<<Ans[n].size()<<'\n';
        for(auto [a, b]: Ans[n]) cout<<a<<' '<<b<<'\n';
    }


    return 0;
}