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
        ll n; cin>>n;
        vi A(n); rep(i, n) cin>>A[i];
        vi B(n); rep(i, n) cin>>B[i];
    
        ll ans = 0, b_mx = 0;
        vi Pos(31, 0);
        rep(i, 30) {
            int cnt1 = 0, cnt2 = 0;
            rep(j, n) if(A[j] & (1LL << i)) cnt1++;
            rep(j, n) if(B[j] & (1LL << i)) cnt2++;
            // cout<<"i: "<<i<<", "<<cnt1<<' '<<cnt2<<'\n';
            if(cnt1 == n - cnt2) b_mx = i, ans = (1LL<<i), Pos[i] = 1;
        }

        for(ll j = b_mx - 1; j >= 0; j--) {
            int cnt1 = 0, cnt2 = 0;
            if(!Pos[j]) continue;
            multiset<ll> S;
            ll cand = (1LL << j) | ans;
            rep(j, n) S.insert(A[j] & cand);
            rep(j, n) {
                ll aux = B[j] & cand;
                if(S.count(cand ^ aux)) {
                    S.erase(S.find(cand ^ aux));
                }
                else break;
            }
            if(S.empty()) ans |= (1LL << j);
        }
        cout<<ans<<'\n';


    }

    return 0;
}