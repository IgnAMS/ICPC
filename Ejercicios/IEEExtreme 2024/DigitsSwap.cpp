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
    string s; cin>>s;
    int n = s.length();
    int k; cin>>k;

    rep(i, n) {
        pll best = {s[i] - '0', i};
        for(int j = n - 1; j > i; j--) {
            if(s[j] - '0' > best.ff) {
                best = {s[j] - '0', j};
            }
        }
        if(best.ss != i and k) {
            swap(s[i], s[best.ss]);
            k--;
        }
    }
    cout<<s<<'\n';







    return 0;
}