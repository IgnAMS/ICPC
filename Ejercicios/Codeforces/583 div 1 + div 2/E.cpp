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
    vi D(n); rep(i, n) cin>>D[i];
    vector<ii> Ans;
    repx(i, 1, n) Ans.push_back(ii(2 * i, 2 * (i + 1)));
    repx(i, 1, n + 1) {
        if(2 * (i + D[i - 1] - 1) <= 2 * n) 
            Ans.push_back(ii(2 * i - 1, 2 * (i + D[i - 1] - 1)));
        else 
            Ans.push_back(ii(2 * i - 1, 2 * (i - D[i - 1] + 1)));
    }
    rep(i, Ans.size()) {
        cout<<Ans[i].ff<<' '<<Ans[i].ss<<'\n';
    }




    return 0;
}