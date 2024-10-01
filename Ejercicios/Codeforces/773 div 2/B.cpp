#pragma GCC optimize("Ofast")
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
    int t; cin>>t;
    while(t--) {
        set<ll> S; 
        map<ll, ll> mapa;
        int n; cin>>n;
        vi A(n); rep(i, n) cin>>A[i];
        rep(i, n) {
            if(!mapa.count(A[i])) mapa[A[i]] = 0;
            mapa[A[i]]++;
            S.insert(A[i]);
        }
        ll ans = S.size();
        multiset<ll> S2;
        for(auto u: mapa) S2.insert(u.ss);
        rep(i, ll(S.size())) {
            cout<<S.size()<<' '; 
        } 
        rep(i, n - ll(S.size())) {
            cout<<S.size() + i + 1<<' ';
        }
        cout<<'\n';


    }





    return 0;
}