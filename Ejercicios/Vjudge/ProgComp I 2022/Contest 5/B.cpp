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


vi Ans(10, -1);
vi A(10);
bool backtrack(ll x, ll suma, ll k, ll n, ll suma2) {
    if(n == 10) return 1;
    rep(i, 10) cout<<Ans[i]<<' '; cout<<'\n';
    if(suma2 * x + suma > k) return 0;
    rep(i, 10) {  
        if(Ans[i] == -1 and suma + x * A[i] <= k) {
            Ans[i] = x;
            if(backtrack(x + 1, suma + x * A[i], k, n + 1, suma2 - A[i])) return 1;
            Ans[i] = -1;
        }
    }
    return 0;
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) {
        rep(i, 10) cin>>A[i];
        ll suma2 = 0; rep(i, 10) suma2 += A[i];
        ll k; cin>>k;
        if(backtrack(0, 0, k, 0, suma2)) {
            rep(i, 10) cout<<Ans[i]<<' '; cout<<'\n'; 
        }
        else cout<<"-1\n";

    }


    return 0;
}