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
    int n; cin>>n;
    vi A(n); 
    rep(i, n) cin>>A[i];
    int q; cin>>q;
    vi Ans(q);
    vector<vi> E;
    ll sqr = sqrt(n);
    rep(i, q) {
        int l, r; cin>>l>>r;
        E.push_back({l / sqr, r, l - 1, r - 1, i});
    }
    sort(E.begin(), E.end());
    ll ans = 0;
    vi F(1000001, 0);
    repx(i, E[0][2], E[0][3] + 1) {
        if(F[A[i]] == 0) ans++; 
        F[A[i]]++;
    }
    Ans[E[0][4]] = ans;
    int l = E[0][2], r = E[0][3];
    repx(i, 1, q) {
        for(int j = r; j > E[i][3]; j--) {
            F[A[j]]--;
            if(F[A[j]] == 0) ans--;
        }
        repx(j, r + 1, E[i][3] + 1) {
            if(F[A[j]] == 0) ans++;
            F[A[j]]++;
        }
        for(int j = l - 1; j >= E[i][2]; j--) {
            if(F[A[j]] == 0) ans++;
            F[A[j]]++;
        }
        repx(j, l, E[i][2]) {
            F[A[j]]--;
            if(F[A[j]] == 0) ans--;
        }
        Ans[E[i][4]] = ans;
        l = E[i][2], r = E[i][3];
    }
    rep(i, q) cout<<Ans[i]<<'\n';


    return 0;
}