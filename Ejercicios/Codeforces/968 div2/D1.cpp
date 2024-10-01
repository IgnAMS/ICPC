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

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) {
        ll n, m; cin>>n>>m;
        vl A[n];
        ll Mex[n], Mex2[n];
        map<ll, ll> mp;
        rep(i, n) {
            ll l; cin>>l;
            A[i].resize(l);
            vl F(l + 5, 0);
            rep(j, l) {
                cin>>A[i][j];
                if(A[i][j] <= l + 4) F[A[i][j]]++;
            }

            ll mex, mex2;   
            bool bmex = 0;
            rep(j, l + 5) {
                if(F[j] == 0 and bmex == 0) {
                    mex = j;
                    bmex = 1;
                }
                else if(F[j] == 0 and bmex == 1) {
                    mex2 = j;
                    break;
                }
            }
            // cout<<mex<<' '<<mex2<<'\n';
            Mex[i] = mex, Mex2[i] = mex2;

            if(!mp.count(mex)) mp[mex] = mex2;
            else mp[mex] = max(mp[mex], mex2);
        }

        ll best = mp.rbegin()->ff;
        ll ans = 0;
        for(auto it = mp.rbegin(); it != mp.rend(); it++) {
            if(mp.count(it->ss)) {
                // Puedo acceder sin ningun cambio, asi que el mejor hasta aca es best
                mp[it->ff] = mp[it->ss];
                best = max(best, mp[it->ff]);
            }
            else best = max(best, it->ss);
        }

        ll last = m;
        for(auto it = mp.rbegin(); it != mp.rend(); it++) {
            // cout<<"iteracao en "<<it->ff<<", "<<it->ss<<'\n';
            if(it->ff <= m) {
                if(last > best) {
                    // cout<<"aumento el segmento ["<<best + 1<<", "<<last<<"] en si mismos\n";
                    // cout<<last * (last + 1) / 2 - best * (best + 1) / 2<<'\n';
                    ans += last * (last + 1) / 2 - best * (best + 1) / 2;
                    // cout<<"aumento el segmento ("<<it->ff<<", "<<best<<"] en "<<best<<'\n';
                    // cout<<(best - it->ff) * best<<'\n';
                    ans += (best - it->ff) * best;
                }
                else {
                    // cout<<"aumento el segmento ("<<it->ff<<", "<<last<<"] en "<<best<<'\n';
                    // cout<<(last - it->ff) * best<<'\n';
                    ans += (last - it->ff) * best;
                }

                // cout<<"aumento a "<<it->ff<<" en "<<max(best, it->ss)<<'\n';
                // cout<<max(best, it->ss)<<'\n';
                ans += max(best, it->ss); // Se que puedo llegar a it->ss
                last = it->ff - 1;
            }
        }
        // cout<<last<<'\n';
        if(last >= 0) {
            ans += (last + 1) * best;
        }
        
        cout<<ans<<'\n';
    }

    return 0;
}