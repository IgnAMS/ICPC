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
vi Mn(101, 1000000);
vector<vector<ii>> Ans(101, vector<ii>());
ll cont = 0;
void dp(vi& A, vector<ii>& P, ll d) {
    cont++;
    if(Mn[A.back()] > d) {
        Mn[A.back()] = d;
        Ans[A.back()] = P;
    }
    set<ll> aux;
    ll n =  A.size();
    for(int i = n - 1; i >= 0; i--) {
        for(int j = n - 1; j >= 0 and A[i] + A[j] > A.back(); j--) 
            if(!aux.count(A[i] + A[j]) and A[i] + A[j] <= 100 and Mn[A[i] + A[j]] >= d + 1) {
                A.push_back(A[i] + A[j]);
                P.push_back({A[i], A[j]});
                dp(A, P, d + 1);
                A.pop_back();
                P.pop_back();
                aux.insert(A[i] + A[j]);
            }
    }
}



int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n, m; cin>>n>>m;
    if(n != 1) { cout<<"*\n"; return 0; }
    vi A = {1};
    vector<ii> P;
    dp(A, P, 0);
    rep(i, Ans[m].size()) {
        cout<<1<<' '<<Ans[m][i].ff<<'\n';
        cout<<1<<' '<<Ans[m][i].ss<<'\n';
    }


    return 0;
}