#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>

using namespace std;
#define repx(i, a, b) for(int i = a; i < b; i++)
#define rep(i, n) repx(i, 0, n)
typedef long long ll;
typedef vector<ll> vl;
typedef pair<ll, ll> pll;
#define pb push_back


// g++ -O2 A.cpp && time ./a.out <input.txt> output.txt

ll X[1000001];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    ll A[n]; 
    ll mxa = 0, suma = 0;
    rep(i, n) {
        cin>>A[i];
        mxa = max(mxa, A[i]), suma += A[i];
    }

    ll curr = A[0];
    repx(i, 1, n) {
       rep(j, A[i]) X[curr + j] = curr;
       curr += A[i];
    }
    X[suma] = suma;
    // rep(i, suma + 1) cout<<X[i]<<' '; cout<<'\n';


    map<ll, ll> mp;
    int q; cin>>q;
    while(q--) {
        int t; cin>>t;
        if(t < mxa) cout<<"Impossible\n";
        else if(mp.count(t)) cout<<mp[t]<<'\n';
        else {
            ll u = 0, res = 1;
            while(true) {
                if(u + t >= suma) break;
                u = X[u + t];
                res++;
            }
            mp[t] = res;
            cout<<res<<'\n';
        }
    }

    return 0;
}


