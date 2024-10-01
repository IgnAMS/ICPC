#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(ll i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<int,int> ii;
#define ff first
#define ss second
typedef vector<ll> vi;



int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    // primeros 168 primos, todos tienen a lo mas 3 potencias <= 10^9
    vi primes = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47,
    53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137,
    139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227,
    229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313,
    317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419,
    421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509,
    521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617,
    619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727,
    733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823, 827, 829,
    839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941, 947,
    953, 967, 971, 977, 983, 991, 997 }; 
    
    // cout<<primes[43]<<endl;
// 
    // rep(i, primes.size()) {
    //     if(2 * primes[i + 1] * primes[i + 2] * primes[i + 3] > 1e9) {
    //         cout<<primes[i]<<' '<<i<<endl; 
    //         break;
    //     }
    // }

    map<ll, vector<ll>> mult;
    vi Q;
    rep(i, primes.size()){ // hasta 168 primos
        ll aux = 1; 
        mult[primes[i]] = vector<ll>();
        int j;
        for(j = 0; aux * primes[i] <= 1000000000; aux *= primes[i], j++){
            mult[primes[i]].push_back(aux * primes[i]);
        }
    }
    int ind = 0; // indice en el que voy 
    vector<ll> A;
    vector<vector<ll>> B;
    while(ind < 168){
        ll mul = 1;
        vector<ll> b;
        while(ind < 168 and 0 <= mul * primes[ind] and 
                mul < 1000000000000000000 / primes[ind]){
            b.push_back(primes[ind]);
            mul *= primes[ind++];
        }
        A.push_back(mul);
        B.push_back(b);
    }

    
    // rep(i, 17) { for(auto u: B[i]) cout<<u<<' '; cout<<endl; }

    int t; cin>>t;
    cerr<<t<<'\n';
    while(t--){
        vector<ll> gcds;
        ll num = 1;
        vector<ll> base;
        ll k = 22;
        for(int i = 0; i < A.size() and base.size() < k; i++) {
            cout<<"? "<<A[i]<<endl;
            ll h; cin>>h;
            rep(j, B[i].size()) {
                cerr<<B[i][j]<<' ';
                if(__gcd(h, B[i][j]) != 1) base.push_back(B[i][j]);
            }
            cerr<<endl;
            num = num / __gcd(num, h) * h;
            k--;
            cerr<<base.size()<<' '<<k<<endl;
        }

        // calculo las bases
        ll ans = 1;
        rep(i, min((ll)base.size(), k)) {
            cout<<"? "<<mult[base[i]].back()<<endl;
            ll g; cin>>g;
            cerr<<g<<endl;
            ll e = 0;
            while(g) e++, g /= base[i];
            cerr<<e<<endl;
            ans *= e;
        }
        cout<<"! "<<max(2 * ans, ans + 7)<<endl;
    }

    return 0;
}