#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;

#define rep(i, n) for(int i = 0; i<(int)n; ++i)

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    a.push_back(0);
    for(int i = 1; i<2000000 && n<25; ++i){
        bool can = true;
        for(int j = 0; j<a.size(); ++j){
            if(a[j] == i){
                can = false;
                break;
            }
        }
        if(can){
            a.push_back(i);
            n++;
        }
    }
    ll ans = 0;
    sort(a.begin(), a.end());
    for(int i = 1; i<a.size(); ++i){
        ans += a[i]-a[i-1]-1;
    }
    cout << ans << '\n';
}


// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
// ulimit -s 1000000
// g++ -O2 D.cpp && time ./a.out <input.txt> output.txt
