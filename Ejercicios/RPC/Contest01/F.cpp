#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;
#define repx(i,a,b) for(int i = a; i < b;i++)
#define rep(i, n) repx(i, 0, n)
#define ff first
#define ss second


ll yp, lp, ys, ls;
ll func(ll x) {
    return (yp - x) * ys + (x - lp) * ls + x * ls;
}

int main() {
    int t; cin>>t;
    while(t--) {
        cin>>yp>>lp>>ys>>ls;
        if(lp >= yp and lp * ls < yp * ys) cout<<lp * ls<<'\n';
        else if(lp >= yp) cout<<yp * ys<<'\n';
        else {
            cout<<min(min(yp * ys, func(lp)), func(yp))<<'\n';
        }
    }
    return 0;
}