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
    int n, q; cin>>n>>q;
    vector<vi> E;
    rep(i, n){
        ll s, t, h; cin>>s>>t>>h;
        E.push_back({s - h, 0, h});
        E.push_back({t - 1 - h, 2, h});
    }
    rep(i, q){
        ll d; cin>>d;
        E.push_back({d, 1, i});
    }
    sort(E.begin(), E.end());
    vi ans(q); 
    multiset<int> A;
    for(auto e: E){
        if(e[1] == 0) A.insert(e[2]);
        if(e[1] == 1 and A.size() == 0) ans[e[2]] = -1;
        if(e[1] == 1 and A.size() != 0) ans[e[2]] = *A.begin();
        if(e[1] == 2) A.erase(A.find(e[2]));
    }

    rep(i, q) cout<<ans[i]<<'\n';



    return 0;
}