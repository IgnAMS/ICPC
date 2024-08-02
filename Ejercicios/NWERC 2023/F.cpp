#pragma GCC optimize("Ofast")
#pragma GCC target("bmi,bmi2,lzcnt,popcnt")
#pragma GCC target("avx,avx2,f16c,fma,sse3,ssse3,sse4.1,sse4.2")
#include <bits/stdc++.h>
using namespace std; 
 
#define ll __int128_t
#define ar array
#define rep(i, n) for(int i = 0; i<(int)n; ++i)
const long long mxN = 6e5+5, M = 1e9+7;
vector<int> a, b;
int dig[10];
 
void reduce(ll &a, ll &b){
    ll fgcd = __gcd(a, b);
    a /= fgcd;
    b /= fgcd;
}
 
void check(ll X, ll num2){
    vector<int> fx;
    ll numx = X;
    while(numx){
        fx.push_back(numx%10);
        numx/=10;
    }
    //reverse(fx.begin(), fx.end());
    vector<int> freq(10, 0);
    ll num = 0;
    ll pond = 1;
    int i = 0;
    for(int j = 0; i<b.size() && j<fx.size(); ++i){
        if(b[i] == fx[j]){
            ++j;
            num += pond*b[i];
            pond*=10;
        }else{
            freq[b[i]]++;
        }
    }
    while(i < b.size()){
        freq[b[i++]]++;
    }
    //cout << num << " " << X << "\n";
    bool can = true;
    for(int x = 0; x<10; ++x){
        //cout << x << " :  " << freq[x] << ' ' << dig[x] << "\n";
        if(freq[x] != dig[x]){
            can = false;
        }
    }
    if(can && num == X){
        cout << "possible\n";
 
        cout << to_string((long long)num2) << " " << to_string((long long)num) << "\n";
        exit(0);
    }
}
 
void solve(){
    long long xA, xB, xC, xD;
    ll A, B, C, D;
 
    cin >> xA >> xB >> xC >> xD;
    A = xA;
    B = xB;
    C = xC;
    D = xD;
 
 
    // ll ffff = __gcd(A, B);
    // A /= ffff;
    // B /= ffff;
    // ffff = __gcd(C, D);
    // C /= ffff;
    // D /= ffff;
     ll aa = A;
 
    while(aa){
        a.push_back(aa%10);
        aa/=10;
    }
    ll bb = B;
    while(bb){
        b.push_back(bb%10);
        bb /= 10;
    }
    //reverse(b.begin(), b.end());
    for(int mask = 0; mask<(1<<(int)a.size()); ++mask){
        ll num = 0;
        ll C2 = C, D2 = D;
        memset(dig, 0, sizeof(dig));
        ll pond = 1;
        for(int bit = 0; bit<a.size(); ++bit){
            if(mask & (1<<bit)){
                dig[a[bit]]++;
            }else{
                num += pond*a[bit];
                pond*=10;
            }
        }
        
        ll num2 = num;
        // cout << "\n";
        // cout << num2 << "\n";
        if((num2*D2) % C2 == 0) {
            // reduce(C2, num2);
            // reduce(C2, D2);
            // cout << num2 << " " << C2 << " " << D2 << "\n";
            check( (num*D2) / C2, num2);
        }
        
    }
    cout << "impossible\n";
}
 
int main(){
#ifdef _DEBUG
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", " w", stdout);
#endif
    std::ios_base::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);
 
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}