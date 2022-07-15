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
    int n, d; cin>>n>>d;
    vi R(n), S(n, -1);
    rep(i, n) cin>>R[i];
    rep(i, n) {
        int s; cin>>s;
        if(s != -1) S[i] = s - 1;
    }
    
    string ans = ""; rep(i, d) ans += '0';
    rep(i, n) {
        string aux = "";
        ll ind = i;
        rep(j, d) {
            if(S[ind] == -1 and j < d - 1) break;
            aux += ('0' + R[ind]);
            ind = S[ind];
        }
        reverse(aux.begin(), aux.end());
        if(aux.size() == d and aux > ans) ans = aux;
    }
    rep(i, d) cout<<ans[i]<<" "; cout<<'\n';

    return 0;
}