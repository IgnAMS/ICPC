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

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n; cin>>n;
    vi A(n); rep(i, n) cin>>A[i];
    vi L(n, -1); 
    vi R(n, n); 
    vector<ii> S;
    for(int i = n - 1; i >= 0l; i--) {
        while(!S.empty() and S.back().ff < A[i]) {
            L[S.back().ss] = i;
            S.pop_back();
        }
        if(!S.empty()) R[i] = S.back().ss;
        S.push_back({A[i], i});
    } 
    reverse(S.begin(), S.end());
    vector<vi> E; // eventos. [0] -> i, [1] -> {0: agregar, 1: sacar}, [2] -> elemento
    rep(i, n) {
        if(L[i] != -1) E.push_back({(i + L[i] + 2) / 2, 0, A[i]});
        if(R[i] != n) E.push_back({(i + R[i] + 1) / 2, 1, A[i]});
    }
    sort(E.begin(), E.end());
    set<ll> SS; for(auto u: S) SS.insert(u.ff);
    ll j = 0;
    rep(i, n) {
        while(j < E.size() and E[j][0] == i) {
            if(!E[j][1]) SS.insert(E[j][2]);
            else SS.erase(E[j][2]);
            j++;
        }
        cout<<SS.size() - (SS.count(A[i]))<<' ';
    }


    return 0;
}