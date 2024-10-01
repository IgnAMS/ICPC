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

const int mxN = 3e5+5;
ll A[mxN];
vector<int> X[1000005];
int n;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    rep(i, n) {
        cin>>A[i];
        X[A[i]].pb(i);
    }

    ll L[n], R[n];
    
    ll best = 0; 
    set<ll> Ans;
    for(int x = 1000000; x >= 0; x--) {
        for(auto i: X[x]) {
            L[i] = i;
            int j = i - 1;
            while(j >= 0 and A[j] % A[i] == 0) j = L[j] - 1;
            L[i] = j + 1;
        }
        
        reverse(X[x].begin(), X[x].end());
        for(auto i: X[x]) {
            R[i] = i;
            int j = i + 1;
            while(j < n and A[j] % A[i] == 0) j = R[j] + 1; 
            R[i] = j - 1;
        }

        for(auto i: X[x]) {
            // cout<<"i: "<<i<<", L: "<<L[i]<<", R: "<<R[i]<<'\n';
            if(R[i] - L[i] > best) {
                best = R[i] - L[i];
                Ans.clear();
            }
            if(R[i] - L[i] == best) {
                Ans.insert( L[i]);
            }
        }
    }
    cout<<Ans.size()<<' '<<best<<'\n';
    for(auto u: Ans) cout<<u + 1<<' '; cout<<'\n';


    return 0;
}