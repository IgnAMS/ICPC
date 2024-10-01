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
    int n; cin>>n;
    vector<vi> H(1e5+1, vi()), A(1e5+1, vi());
    rep(i, n){
        int a, b; cin>>a>>b;
        H[a].push_back(i);
        A[b].push_back(i);
    }

    vector<ii> Ans(n, ii(0, 0));
    rep(i, n) Ans[i].ff = (n - 1), Ans[i].ss = (n - 1);
    rep(i, 1e5+1){
        for(auto u: A[i]) {
            // cout<<"Modificar: "<<u<<' '<<H[i].size()<<'\n';
            Ans[u].ff += H[i].size(), Ans[u].ss -= H[i].size();
        }
    }
    rep(i, n) cout<<Ans[i].ff<<' '<<Ans[i].ss<<'\n';




    return 0;
}