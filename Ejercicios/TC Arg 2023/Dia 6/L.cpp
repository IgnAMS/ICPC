#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
#define rep(i, n) for(int i = 0; i < n; i++)

int f(string &s){
    if(s == "LIE"){
        return 0;
    }
    return 1;
}

int main() {
    int n;
    cin >> n;
    vector<string> a(n);
    vector<int> val(n, 0);
    rep(i, n)cin >> a[i];

    val[n-1] = f(a[n-1]);
    for(int i = n-2; i>=0; --i) {
        val[i] = f(a[i])^(val[i+1]^1);  
    }

    if(val[0])cout << "TRUTH";
    elsecout << "LIE";

    return 0;
}