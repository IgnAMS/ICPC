#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(long long i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<ll, ll> pll;
typedef double db;
typedef vector<ll> vl;
#define ff first
#define ss second
#define pb push_back
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
// ulimit -s 1000000
// g++ -O2 D.cpp && time ./a.out <input.txt> output.txt

const int n = 100;
ll k;
ll A[n], B[n];
ll V[n];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    rep(i, n) cin>>A[i], B[i] = A[i];
    cin>>k;

    // caso imposible
    sort(B, B + n);
    ll curr = 0;
    rep(i, n) curr += B[i] * ll(n - i - 1);
    if(curr > k) {
        cout<<"-1\n";
        return 0;
    }

    // asignaria de tal forma de que el gasto sea minimo e intentare poner elementos mínimos
    curr = 0;
    rep(i, n) {
        // asumo que los primeros i's ya estan fijados
        rep(j, n) if(!V[j]) {
            curr += A[i] * j;
            V[j] = 1;
            ll temp = curr;
            
            repx(a, i + 1, n) B[a] = A[a];
            sort(B + i + 1, B + n);
            ll ind = n - 1;
            rep(a, n) {
                if(!V[a]) temp += B[ind] * a, ind--;
            }

            if(temp <= k) {
                cout<<j<<' ';
                break;
            }
            V[j] = 0;
            curr -= A[i] * j;
        }
    }

    return 0;
}