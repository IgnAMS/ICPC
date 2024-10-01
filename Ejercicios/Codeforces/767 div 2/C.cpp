#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<int,int> ii;
typedef double db;
typedef vector<ll> vi;
#define ff first
#define ss second
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
//  g++ -O2 D.cpp && time ./a.out < input.txt > output.txt

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        map<int, vector<int>> mapa;
        ll maxi = -1;
        vi A(n); 
        rep(i, n) { 
            cin>>A[i];
            if(!mapa.count(A[i])) mapa[A[i]] = {};
            mapa[A[i]].push_back(i);
            maxi = max(maxi, A[i]);
        }
        ll pre_k = -1, k = -1;
        vi Ans;
        for(auto u: mapa) sort(u.ss.begin(), u.ss.end());
        while(mapa.count(0) and (lower_bound(mapa[0].begin(), mapa[0].end(), k) - mapa[0].begin()) < mapa[0].size()) {
            ll last = -1;
            for(auto u: mapa) {
                int pos = (lower_bound(u.ss.begin(), u.ss.end(), pre_k) - u.ss.begin());
                if(u.ff == last + 1 and pos < u.ss.size()) {
                    last = u.ff;
                    k = max(k, ll(u.ss[pos] + 1));
                }
                else {
                    if(last != -1) Ans.push_back(last + 1);
                    last = -1;
                    break;
                }
            }
            
            if(last == maxi) {
                Ans.push_back(last + 1);
            }
            pre_k = k;
        }
        for(auto u: mapa) {
            ll cont = (lower_bound(u.ss.begin(), u.ss.end(), k) - u.ss.begin());
            rep(i, u.ss.size() - cont) Ans.push_back(0);
        }
        cout<<Ans.size()<<'\n';
        for(auto u: Ans) cout<<u<<' '; cout<<'\n';
    }





    return 0;
}