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
    int n, k; cin>>n>>k;
    ll C[n], T[n];
    multiset<ll> attend, waiting;
    int ans = 0;
    rep(i, n) {
        cin>>C[i]>>T[i];
        while(attend.size() and *attend.begin() <= C[i]) {
            if(waiting.size()) {
                ll id = *waiting.begin();
                attend.insert(T[id] + *attend.begin());
                // cout<<"ingrese a "<<id<<" en el tiempo "<<*attend.begin()<<" para que termine el tiempo "<<T[id] + *attend.begin()<<'\n';
                waiting.erase(*waiting.begin());
            }
            attend.erase(attend.find(*attend.begin()));
            ans = max({ans, (int)attend.size() + (int)waiting.size()});
        }
        if(attend.size() == k) waiting.insert(i);
        else {
            // cout<<"ingrese a "<<i<<" en el tiempo "<<C[i]<<" para que termine el tiempo "<<T[i] + C[i]<<'\n';
            attend.insert(C[i] + T[i]);
        }
        // for(auto time: attend) cout<<time<<' '; cout<<'\n';
        // for(auto wait: waiting) cout<<wait<<' '; cout<<'\n'; cout<<'\n';
        ans = max({ans, (int)attend.size() + (int)waiting.size()});
    }

    cout<<ans<<'\n';


    return 0;
}