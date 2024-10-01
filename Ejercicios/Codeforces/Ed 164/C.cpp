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
    int t; cin>>t;
    while(t--) {
        string x, y; cin>>x>>y;
        if(x.length() < y.length()) swap(x, y);
        if(x.length() > y.length()) {
            string a1 = "", a2 = "";
            rep(i, x.length() - y.length()) a1 += x[i];
            for(int i = x.length() - y.length(), j = 0; j < y.length(); j++) {
                a1 += min(x[i], y[j]);
                a2 += max(x[i], y[j]);
            }
            cout<<a1<<'\n';
            cout<<a2<<'\n';
        }
        else {
            bool dif = 0;
            string a1 = "", a2 = "";
            rep(i, x.length()) {
                if(dif) {
                    a1 += min(x[i], y[i]);
                    a2 += max(x[i], y[i]);
                }
                else if(x[i] != y[i]) {
                    a1 += max(x[i], y[i]);
                    a2 += min(x[i], y[i]);
                    dif = 1;
                }
                else a1 += x[i], a2 += y[i];
            }
            cout<<a1<<'\n';
            cout<<a2<<'\n';
        }
    }
    

    return 0;
}