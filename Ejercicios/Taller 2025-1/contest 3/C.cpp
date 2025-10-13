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
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        ll L[n], R[n], Ans[n];
        ll j = 0, curr = 0;
        rep(i, n) {
            cin>>L[i]>>R[i];
            if(curr < L[i]) curr = L[i] + 1, Ans[i] = L[i];
            else if(curr <= R[i]) Ans[i] = curr, curr += 1;
            else Ans[i] = 0;
            cout<<Ans[i]<<' ';
        }
        cout<<'\n';
    }


    return 0;
}