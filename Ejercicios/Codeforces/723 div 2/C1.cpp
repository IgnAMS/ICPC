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
    int n; cin>>n;
    vl A(n); rep(i, n) cin>>A[i];
    ll acc = 0;
    multiset<ll> Neg;
    ll ans = 0;
    rep(i, n) {
        if(A[i] >= 0) acc += A[i], ans++;
        else {
            if(acc + A[i] >= 0) Neg.insert(A[i]), acc += A[i], ans++;
            else {
                if(!Neg.empty() and *Neg.begin() <= A[i]) {
                    acc -= *Neg.begin();
                    acc += A[i];
                    Neg.erase(Neg.find(*Neg.begin()));
                    Neg.insert(A[i]);
                }
            }
        }
        // cout<<i<<' '<<ans<<' '<<acc<<' '<<Neg.size()<<'\n';
    }
    cout<<ans<<'\n';

    return 0;
}