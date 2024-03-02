#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define rep(i, n) for(int i = 0; i<(int)n; ++i)

int main(){
    
    ll n;
    cin >> n;
    vector<ll> freq(14);

    ll J = 0, M = 0, a, b;
    cin >> a >> b;
    freq[a]++;
    freq[b]++;
    if(a > 10) a = 10;
    if(b > 10) b = 10;
    J += a + b;
    cin >> a >> b;
    freq[a]++;
    freq[b]++;
    if(a > 10) a = 10;
    if(b > 10) b = 10;
    M += a + b;

    rep(i, n){
        cin >> a;
        freq[a]++;
        if(a > 10) a = 10; 
        J += a;
        M += a;
    }
    //cout << J << endl << M << endl;
    ll ans = 14;
    for(int i = 1; i <= 13; i++){
        if(freq[i] == 4) continue;
        ll add = i;
        if(i > 10) add = 10;
        //cout << i << " " << J + add << " " << M + add << " " << add << "\n";
        if(((J + add >= 24) && (M + add <= 23)) || (M + add == 23)){
            ans = i;
            break;
        }
    }
    if(ans == 14) cout << "-1\n";
    else cout << ans << "\n";
}