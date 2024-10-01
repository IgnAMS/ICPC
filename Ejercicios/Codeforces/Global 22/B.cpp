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
        ll n, k; cin>>n>>k;
        vi S(k); rep(i, k) cin>>S[i];
        bool oc = 1;
        ll mn = 1e10;
        for(int i = k - 2; i >= 0; i --) {
            if(S[i + 1] - S[i] > mn) oc = 0;
            mn = S[i + 1] - S[i];
            if(S[i] > mn * (n - k + i + 1)) oc = 0;
            // cout<<i<<' '<<n - k + i + 1<<'\n';
        }
        cout<<(oc? "Yes\n": "No\n");
    }





    return 0;
}