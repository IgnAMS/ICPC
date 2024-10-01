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
//  g++ -O2 D.cpp && time ./a.out < input.txt > output.txt


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    vector<ii> A(2 * n);
    rep(i, 2 * n) {
        char c; cin>>c;
        A[i].ff = (c == '+');
        if(c == '-') {
            int h; cin>>h;
            A[i].ss = h;
        }
    }

    vector<vi> S;
    vi Ans(2 * n, -1);
    rep(i, 2 * n) {
        if(A[i].ff) S.push_back({i, 1000000, 0});
        else {
            if(S.empty()) { cout<<"NO\n"; return 0; }
            ii q = { S.back()[1], S.back()[2] };
            if(q.ff != 1000000 and A[i].ss < q.ff) { cout<<"NO\n"; return 0; }
            if(q.ss != 0 and A[i].ss < q.ss) { cout<<"NO\n"; return 0; }
            Ans[S.back()[0]] = A[i].ss;
            if(S.size() > 1) {
                ll x = S.size() - 2;
                S[x][1] = min({ A[i].ss, S[x][1], S.back()[1]} );
                S[x][2] = max({ A[i].ss, S[x][2], S.back()[2]} );
            }
            S.pop_back();
        }
    }   
    cout<<"YES\n";
    rep(i, 2 * n) if(Ans[i] != -1) cout<<Ans[i]<<' '; cout<<'\n';

    return 0;





    return 0;
}