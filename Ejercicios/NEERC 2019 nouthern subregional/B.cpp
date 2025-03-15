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

// const double PI = acos(-1);
// double mn = 1e9;
// double compare(double num){
//     mn = min(mn, ceil(num)-num);
//     return ceil(num) - num;
    
// }

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    
    cout << fixed << setprecision(12);
    // pair<double, double> ans = {10000000.0, 100.0};
    // for(int x = 1 ; x<6830; ++x){
    //     ans = min(ans, {compare(2*PI*x), 2*PI*x});
    // }
    // cout << "epsilon " << mn << "\n";
    // cout << "maximo" << mn*50000/2;
    // cout << ans.first << " " << ans.second;
    // return 0;

    int n; cin >> n; ll x = 710;
    for(int i = 0; i<n; ++i) cout << x*(i-25000) << " ";
    // cout << "\n";
    // for(int i = 0; i<n; ++i){
    //     cout << sin(x*(i-25000)) << " ";
    // }

}


