#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<ll, ll> ii;
typedef double db;
typedef vector<ll> vi;
#define ff first
#define ss second
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
// g++ -O2 D.cpp && time ./a.out <input.txt> output.txt

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        vi B(n); rep(i, n) cin>>B[i];
        vector<vi> invB(n + 2, vi());
        ll k = 0;
        rep(i, n) {
            if(B[i] < (i + 1)) k = max(k, B[i]);
            else k = max(k, ll(i + 1));
            invB[B[i]].push_back(i + 1);
        }
        cout<<k<<'\n';
        vi prev = {0, n + 1};
        vi nw, P;
        vector<vi> Ans;
        ll cnt = 0;
        while(cnt != n) {
            for(auto& u: prev) for(auto& v: invB[u]) {
                if(Ans.size() and P.size() == Ans.size() - 1) {
                    P.push_back(u);
                }
                nw.push_back(v);
                cnt++;
            }
            Ans.push_back(nw);
            prev = nw;
            nw.clear();
        }
        rep(i, Ans.size() - 1) {
            for(auto& v: Ans[i]) if(v != P[i]) cout<<v<<' ';
            cout<<P[i]<<' '; 
        }
        for(auto v: Ans.back()) cout<<v<<' ';
        cout<<'\n';
    }


    return 0;
}