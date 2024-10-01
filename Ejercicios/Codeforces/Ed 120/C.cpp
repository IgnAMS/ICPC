#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<int,int> ii;
typedef double db;
typedef vector<ll> vi;
#define ff first
#define ss second
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
//  g++ -O2 D.cpp && time ./a.out < input.txt > output.txt

vi A, invAcc;
ll n, k;
ll suma;
ll xd;
ll f(ll x) { 
    ll aux = x;
    int i = n - 1;
    while(i >= 1 and suma - aux > k){
        aux += abs(A[i] - (A[0] - x)); // convierto A[i] en A[0]
        i--;
    }
    if(suma - aux > k) return 1000000000000;
    return x + (n - 1 - i);
}

ll min_search(ll l, ll r) {
    while (l < r) {
        ll m = (l + r) >> 1;
        ll f1 = f(m+1), f2 = f(m);
        if(f1 >= f2) r = m;
        else l = m + 1;
    }
    return l;
}

double min_ternary_search(ll l, ll r, ll times) {
    while(l < r) {
        ll d = (r - l) / 3;
        if(r - l <= 3) return min({f(l), f(l+1), f(l+2), f(l+3)});
        ll m1 = l + d, m2 = r - d;
        ll f1 = f(m1), f2 = f(m2);
        if (f1 <= f2) r = m2;
        if (f1 >= f2) l = m1;
        cerr<<l<<' '<<r<<'\n';
    }
    return f((l+r)*.5);
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--){
        cin>>n>>k;
        A.resize(n); rep(i, n) cin>>A[i];
        sort(A.begin(), A.end());
        invAcc.resize(n, 0);
        suma = 0;
        rep(i, n) suma += A[i];
        
        ll l = 0, r = suma;
        while(l < r){
            ll m = (l + r) / 2;
            if(f(m) == 1000000000000) l = m+1;
            else r = m;
        }

        // ll aux = min_search((l+r)/2, suma);
        // cout<<f(aux)<<'\n';
        cerr<<"termine el primero!\n";
        cout<<min_ternary_search((l+r)/2, suma, 300)<<'\n';
    }


    return 0;
}