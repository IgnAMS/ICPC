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
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        string a, b; cin>>a>>b;
        vi A(n), B(n); rep(i, n) A[i] = a[i] - '0', B[i] = b[i] - '0';
        ll l = 0, r = n - 1;
        bool rev = 0;
        vi Ans;
        for(int i = n - 1; i >= 0; i--) {
            ll x = rev? l: r, y = rev? r: l;
            ll ax = rev? 1 - A[x]: A[x], ay = rev? 1 - A[y]: A[y];
            if(ax != B[i]) {
                if(ay == B[i]) Ans.push_back(0);
                Ans.push_back(i);
                if(rev) r--;
                else l++;
                rev = !rev;
            }
            else {
                if(rev) l++;
                else r--;
            }
        }
        cout<<Ans.size()<<' ';
        rep(i, Ans.size()) cout<<Ans[i] + 1<<' '; cout<<'\n';
    }


    return 0;
}