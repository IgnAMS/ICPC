#pragma GCC optimize("Ofast")
#include<iostream>
#include<vector>
#include<map>
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

vector<bool> isP(1000001, 1);
vl P;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    string X; cin>>X;
    ll num = 0;
    for(int i = 0; i < min(int(X.size()), 10); i++) {
        num = num * 10 + (X[i] - '0'); 
    }


    for(int i = 2; i <= 1000000LL; i++) if(isP[i]) {
        for(ll j = 1LL * i * i; j <= 1000000LL; j += i) {
            isP[j] = 0;
        }
        P.pb(i);
    }

    map<ll, ll> mp;
    // cout<<P.size()<<"\n"; // 78498 = 10^5
    for(auto p: P) {
        while(num % p == 0) {
            if(!mp.count(p)) mp[p] = 0;
            mp[p]++;
            num /= p;
        }
    }
    if(num != 1) mp[num] = 1; 

    if(X.size() > 10) {
        if(!mp.count(2)) mp[2] = 0;
        if(!mp.count(5)) mp[5] = 0;

        mp[2] += X.size() - 10;
        mp[5] += X.size() - 10;
    }
    cout<<mp.size()<<"\n";
    for(auto [a, b] : mp) {
        cout<<a<<" "<<b<<"\n";
    }
    // ll xd = 1;
    // for(auto [a, b]: mp) {
    //     rep(j, b) xd *= a;
    // }
    // cout<<xd<<"\n";


    return 0;
}