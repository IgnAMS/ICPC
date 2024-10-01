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
        int n; cin>>n;
        vl A;
        rep(i, n) {
            ll x; cin>>x;
            if(x == 0) continue; // el 0 no sirve de nada xd
            if(x < 0 and A.size() == 0) continue; // se puede ignorar
            if(x < 0 and A.size() > 0) {
                if(A.back() < 0) A.back() += x;
                else A.pb(x);
            } 
            if(x > 0) A.pb(x);
        }
        if(A.size() and A.back() < 0) A.pop_back(); // se puede ignorar
        
        n = A.size();
        bool imp = 0;
        rep(i, n - 1) {
            if(A[i] > 0 and A[i + 1] > 0) imp = 1;
        }
        
        // rep(i, n) cout<<A[i]<<' '; cout<<'\n';

        if(imp) {
            cout<<"NO\n";
            continue;
        }
        if(n <= 1) {
            cout<<"YES\n";
            continue;
        }

        // Al llegar acá A queda de la forma
        // [positivo, negativo, positivo, ..., negativo, positivo]
        // con n >= 3

        ll left = 0, right = n - 1;
        while(left + 1 < n and A[left] <= -A[left + 1]) left += 2;
        while(right - 1 >= 0 and A[right] <= -A[right - 1]) right -= 2;

        if(right <= left) cout<<"YES\n";
        else cout<<"NO\n";
    }


    return 0;
}