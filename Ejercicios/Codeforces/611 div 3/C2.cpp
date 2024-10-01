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
    int n; cin>>n;
    vi A(n); rep(i, n) cin>>A[i];
    set<ll> S; rep(i, n) if(A[i]) S.insert(A[i]);
    set<ll> C1, C2; 
    rep(i, n) if(A[i] == 0){
        if(S.count(i + 1)) C1.insert(i + 1);
        else C2.insert(i + 1);
    }

    // for(auto u: C1) cout<<u<<' '; cout<<'\n';
    // for(auto u: C2) cout<<u<<' '; cout<<'\n';

    // C2 se auto marcan
    if(C2.size() > 1) for(auto it = C2.begin(); it != C2.end(); it++) {
        if(it == prev(C2.end())) A[*it - 1] = (*C2.begin());
        else A[*it - 1] = (*next(it));
        S.insert(*it);
    }
    else if(C2.size() == 1){
        A[(*C1.begin()) - 1] = (*C2.begin());
        S.insert(*C2.begin());
        C1.erase(C1.begin());
        C1.insert(*C2.begin());
    }

    // for(auto u: C1) cout<<u<<' '; cout<<'\n';
    // for(auto u: C2) cout<<u<<' '; cout<<'\n';

    rep(i, n) if(!S.count(i + 1)) {
        // cout<<"no encontre a "<<i + 1<<'\n';
        A[(*C1.begin()) - 1] = i + 1;
        C1.erase(C1.begin());
    }
    rep(i, n) cout<<A[i]<<' '; cout<<'\n';
    






    return 0;
}