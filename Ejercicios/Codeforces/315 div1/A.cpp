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


ll P[1179859], Pi[1179859], Rub[1179859];

ll is_palindromic(int n) {
    ll d[10];
    int L10 = 0;
    while(n) {
        d[L10] = n % 10;
        n /= 10;
        L10++;
    }
    for(int i = 0; i < L10 / 2; i++) {
        if(d[i] != d[L10 - i - 1]) return 0;
    }
    return 1;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll p, q; cin>>p>>q;

    for(int i = 2; i < 1179859; i++) P[i] = 1;

    for(int i = 2; i < 1179859; i++) {
        if(P[i]) {
            for(int j = 2 * i; j < 1179859; j += i) {
                P[j] = 0;
            }
        }
        Pi[i] = Pi[i - 1] + P[i];
    }

    repx(i, 1, 1179859) Rub[i] = Rub[i - 1] + is_palindromic(i); 

    int last = -1;
    repx(i, 1, 1179859) {
        // cout<<Pi[i]<<' '<<Rub[i]<<' '<<p * Rub[i] - q * Pi[i]<<'\n';
        if(q * Pi[i] <= p * Rub[i]) {
            last = i;
            // cout<<i - 1<<'\n';
            // return 0;
        }
        // cout<<p * Rub[i] - q * Pi[i]<<'\n';
    }
    if(last == -1) cout<<"Palindromic tree is better than splay tree\n";
    else cout<<last<<'\n';

    return 0;
}