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
    int n, c; cin>>n>>c;
    vl A(n); rep(i, n) cin>>A[i];
    multiset<ll> S1, E1, S2, E2;
    ll suma1 = 0, suma2 = 0;
    rep(i, n) {
        S1.insert(A[i]);
        suma1 += A[i];
        if((i + 1) % c == 0) {
            suma1 -= *S1.begin();
            E1.insert(*S1.begin());
            S1.erase(S1.find(S1.begin()));
        }
    }
    
    ll ans = 0;
    rep(i, n) {
        S2.insert(A[i]);
        suma2 += A[i];
        if((i + 1) % c == 0) {
            suma2 -= A[i];
            E2.insert(*S2.begin());
            S2.erase(S2.find(S2.begin()));
        }

        if(S2.count(A[i])) S2.erase(S2.find(A[i])), suma2 -= A[i];
        else E2.erase(E2.find(A[i])); 
        ll cant = S2.size() + E2.size();
        while(E2.size() > cant / c) {
            S2.insert(*E2.begin());
            suma2 += *E2.begin();
            E2.erase(E2.find(*E2.begin()));
        }
        while(E2.size() < cant / c) {
            E2.insert(*S2.begin());
            suma2 -= *S2.begin();
            S2.erase(S2.find(S2.begin()));
        }


        ans = max(ans, suma1 + suma2);
    }

    cout<<ans<<'\n';



    return 0;
}