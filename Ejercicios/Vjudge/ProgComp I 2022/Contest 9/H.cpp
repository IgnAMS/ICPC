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

vi W; 
ll D, n;
vi Acc;

vi S;
vector<bool> X;
void pos(ll i, ll w) {
    // cout<<Acc.back()<<' '<<Acc[i]<<'\n';
    if(Acc.back() - Acc[i] < w) return;
    // for(auto u: S) cout<<u<<' '; cout<<'\n';
    if(w == 0) {
        X[S.size()] = 1;
        return;
    }
    if(W[i] > w) return;
    pos(i + 1, w);

    S.push_back(W[i]);
    pos(i + 1, w - W[i]);
    S.pop_back();
}



int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    repx(cas, 1, t + 1) {
        cin>>n>>D;
        W.assign(n, 0); rep(i, n) cin>>W[i];
        sort(W.begin(), W.end());

        Acc.assign(n + 1, 0);
        rep(i, n) Acc[i + 1] = W[i] + Acc[i];

        X.assign(n + 1, 0);
        pos(0, D);

        ll suma = 0, ans = 0;
        rep(i, n + 1) {
            suma += X[i];
            if(X[i]) ans = i;
        }
        if(suma == 0) {
            cout<<"Case #"<<cas<<": IMPOSSIBLE\n";
        }
        else if(suma > 1) {
            cout<<"Case #"<<cas<<": AMBIGIOUS\n";
        }
        else {
            cout<<"Case #"<<cas<<": "<<ans<<"\n";
        }
        
        


    }





    return 0;
}