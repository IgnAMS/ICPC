#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define rep(i, n) for(int i = 0; i<(int)n; ++i)

int main(){
    int n;
    string s;
    int ans = 0;
    cin >> n >> s;
    for(int i = 0; i<n; ++i){
        int cnt = 0;
        while(i<n && s[i] == 'a'){
            cnt++;
            ++i;
        }
        if(cnt > 1){
            ans += cnt;
        }
    }
    cout << ans << '\n';
}