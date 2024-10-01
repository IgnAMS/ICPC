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

vi moves;



int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        vi A(n); rep(i, n) cin>>A[i];
        map<ll, vi> mapa;
        for(int i = n - 1; i >= 0; i--) {
            if(!mapa.count(A[i])) mapa[A[i]] = vi();
            mapa[A[i]].push_back(i);
        }
        bool oc = 1;
        for(auto u: mapa) if(u.ss.size() % 2 != 0) oc = 0;
        if(!oc) { cout<<"-1\n"; continue; }

        vector<ii> moves;
        vi T;
        rep(i, n / 2) {
            if(A[2 * i] != A[2 * i + 1]) {
                ll j = n - 1;
                while(A[j] != A[2 * i]) j--;
                for(int k = n - 1, s = 0; k >= j; k--, s++) {
                    moves.push_back({j + s, A[k]});
                }
                reverse(A.begin() + j, A.end());
                T.push_back(2 * (n - j));
                for(int k = n - 1, s = 0; k >= 2 * i + 1; k--, s++) {
                    moves.push_back({2 * i + 1 + s, A[k]});
                }
                reverse(A.begin() + 2 * i + 1, A.end());
                T.push_back(2 * (n - (2 * i + 1)));
            }
        }
        cout<<moves.size()<<'\n';
        for(auto u: moves) cout<<u.ff<<' '<<u.ss<<'\n';
        cout<<T.size() + n / 2<<'\n';
        rep(i, n / 2) cout<<2<<' ';
        rep(i, T.size()) {
            cout<<T[T.size() - i - 1]<<' ';
        }
        cout<<'\n';

    }


    return 0;
}