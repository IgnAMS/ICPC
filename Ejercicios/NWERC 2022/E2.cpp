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

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    string s;
    cin >> s;
    ll n, d;
    for(int i = 0; i<s.size(); ++i){
        if(s[i] == '/'){
            n = stoi(s.substr(0, i+1));
            d = stoi(s.substr(i+1, (int)s.size()-(i+1)));
        }
    }

    ll on = n, od = d;
    while(d <= 1000000) {
        if(d - 1 <= n and n <= (d - 1) * d / 2) {
            vl Ans(d - 1, 1);
            ll curr = d - 1;
            rep(i, d - 1) {
                ll dif = (i + 1) - Ans[i];
                if(curr + dif <= n) Ans[i] = i + 1, curr += dif;
                else Ans[i] = Ans[i] + (n - curr), curr += (n - curr);
            }
            cout<<d<<' '<<d - 1<<'\n';
            vector<pll> E;
            rep(i, d - 1) {
                cout<<Ans[i]<<' '<<i + 2<<'\n';
                
            }
            return 0;
        }
        else d += od, n += on;
    }
    cout<<"impossible\n";
    







    return 0;
}