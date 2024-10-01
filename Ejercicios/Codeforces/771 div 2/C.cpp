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
        int n; cin>>n;
        vi A(n); rep(i, n) cin>>A[i];
        vi B(n); rep(i, n) B[A[i] - 1] = i;
        // rep(i, n) cout<<B[i]<<' '; cout<<'\n';
        int x = n - 1;
        ll comps = n;
        set<ll> S;
        while(x >= 0) {
            if(S.count(x + 1)) { x--; continue; }
            int i = B[x] + 1;
            ll mn = x;
            S.insert(x + 1);
            // cout<<"parto en "<<i<<" para el numero "<<x + 1<<'\n';
            while(i < n and A[i] < x + 1) {
                mn = min(A[i], mn);
                comps--;
                if(S.count(A[i])) break;
                S.insert(A[i]);
                i++;
            }
            // cout<<"termino en "<<i<<" para el numero "<<x + 1 <<'\n';
            A[B[x]] = mn;
            x--;
        }
        cout<<comps<<'\n';
    }


    return 0;
}