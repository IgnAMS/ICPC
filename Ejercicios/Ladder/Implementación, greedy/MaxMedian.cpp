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
    int n, k; cin>>n>>k;
    vi A(n); rep(i, n) cin>>A[i];
    multiset<ll> L, R;
    rep(i, k) L.insert(A[i]);
    while(L.size() > R.size()) {
        R.insert(*L.rbegin());
        L.erase(L.find(*L.rbegin()));
    }
    ll ans;
    if(L.empty()) ans = *R.begin();
    else ans = *L.rbegin();
    repx(i, k, n) {
        cerr<<"i: "<<i<<". Meto a "<<A[i]<<'\n';
        if(A[i] >= *R.begin()) R.insert(A[i]);
        else L.insert(A[i]);
        
        if(A[i - k] >= *R.begin()) R.erase(R.find(A[i - k]));
        else L.erase(L.find(A[i - k]));
        
        while(R.size() > L.size()) {
            L.insert(*R.begin());
            R.erase(R.find(*R.begin()));
        }

        while(L.size() > R.size()) {
            R.insert(*L.rbegin());
            L.erase(L.find(*L.rbegin()));
        }
        
        if(L.size() < R.size()) ans = max(ans, *R.begin());
        else ans = max(ans, *L.rbegin());
        // cout<<i<<". L, R, ans: "<<L.size()<<' '<<R.size()<<' '<<ans<<'\n';
        cerr<<"si llegue xd\n";
    }
    cout<<ans<<'\n';

    return 0;
}