#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define rep(i, n) for(int i = 0; i<(int)n; ++i)

int main(){
    char ans = 'S';
    rep(i, 8){
        ll a;
        cin >> a;
        if(a == 9) ans = 'F';
    }
    cout << ans << endl;
}