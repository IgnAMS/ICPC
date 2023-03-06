#include <bits/stdc++.h>
using namespace std;
 
#define ll long long 
#define ar array
#define rep(i, n) for(int i = 0; i<(int)n; ++i)

const int mxN = 305, M = 1e9+7;

int main(){
    string s;
    cin >> s;
    s+='1';
    int n = s.size();
    int ans = 0;
    int cnt = 0;
    vector<int> ff;
    rep(i, n){
        if(s[i] == '1') ff.push_back(i);
    }
    for(int i = 1; i<ff.size(); ++i){
        ans = max(ans, (ff[i]-ff[i-1])/2);
    }
    cout << ans << "\n";
}