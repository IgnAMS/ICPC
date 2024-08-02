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


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n, k; cin>>n>>k;
    string s; cin>>s;
    
    ll acc = 0;
    ll cont = 0;
    multiset<ll> S;
    rep(i, n) {
        if(s[i] == '1') cont++;
        else {
            acc += cont * (cont + 1) / 2;
            S.insert(cont);
            cont = 0;
        }
    }
    acc += cont * (cont + 1) / 2;
    S.insert(cont);
    cont = 0;

    // cout<<((5 + 1) / 2 - 1)<<' '<<(5 / 2)<<'\n';
    // cout<<((4 + 1) / 2 - 1)<<' '<<(4 / 2)<<'\n';
    // cout<<((3 + 1) / 2 - 1)<<' '<<(3 / 2)<<'\n';
    // cout<<((1 + 1) / 2 - 1)<<' '<<(1 / 2)<<'\n';

    ll ans = 0;
    while(acc > k) {
        ll x = *S.rbegin();
        // 2 -> [1, 0]
        // 3 -> [1, 1] 
        // 4 -> [2, 1] 
        // 5 -> [2, 2]
        ll left = (x + 1) / 2 - 1, right = x / 2;
        // cout<<"cambio el "<<x<<" por "<<left<<' '<<right<<'\n';
        acc += left * (left + 1) / 2 + right * (right + 1) / 2 - x * (x + 1) / 2;
        S.erase(S.find(x));
        S.insert(left); S.insert(right);
        ans++;
    }
    cout<<ans<<'\n';

    return 0;
}