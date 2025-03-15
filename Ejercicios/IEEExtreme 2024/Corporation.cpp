#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
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


const int mxN = 2e5+5;
ll sq = sqrt(mxN);


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll n, q; cin>>n>>q;
    ll A[n], F[n];
    rep(i, n) {
        cin>>A[i];
        F[i] = 0;
    }
    sq = sqrt(n);

    ll V[(n + sq - 1) / sq], FB[(n + sq - 1) / sq], L[(n + sq - 1) / sq];
    ll Offset[(n + sq - 1) / sq], OffFB[(n + sq - 1) / sq];
    rep(i, (n + sq - 1) / sq) {
        Offset[i] = V[i] = FB[i] = OffFB[i] = 0;
        repx(j, sq * i, min(sq * (i + 1), n)) {
            L[i] = min(sq * (i + 1), n) - i * sq;
            V[i] += A[j];
        }
    }

    while(q--) {
        int t; cin>>t;        
        if(t <= 1) {    
            ll l, r, c; cin>>l>>r>>c; l--, r--;
            if(t == 1) { 
                ll sign = (c == 0? 0: (c < 0? -1: 1));
                for(int i = l; i < min(r + 1, (l / sq + 1) * sq); i++) {
                    A[i] += c;
                    V[l / sq] += c;
                    F[i] += sign;
                    FB[l / sq] += sign;
                }
                for(int i = l / sq + 1; i < r / sq; i++) {
                    Offset[i] += c;
                    OffFB[i] += sign;
                }
                for(int i = max((l / sq + 1) * sq, (r / sq) * sq); i <= r; i++) {
                    A[i] += c;
                    V[r / sq] += c;
                    F[i] += sign;
                    FB[r / sq] += sign;
                }
            }
            else {
                for(int i = (l / sq); i < r / sq + 1; i++) {
                    for(int j = i * sq; j < min((i + 1) * sq, n); j++) {
                        A[j] += Offset[i];
                        F[j] += OffFB[i];

                        FB[i] += OffFB[i];
                        V[i] += Offset[i];
                    }
                    Offset[i] = OffFB[i] = 0;
                }
                for(int i = l; i < min(r + 1, (l / sq + 1) * sq); i++) {
                    // cout<<"estoy en "<<i<<' '<<c<<' '<<A[i]<<'\n';
                    if(A[i] > c) F[i]--, FB[l / sq]--;
                    if(A[i] < c) F[i]++, FB[l / sq]++;
                    V[l / sq] += c - A[i];
                    A[i] = c;
                }
                for(int i = l / sq + 1; i < r / sq; i++) {
                    for(int j = i * sq; j < min((i + 1) * sq, n); j++) {
                        if(A[j] > c) F[j]--, FB[i]--;
                        if(A[j] < c) F[j]++, FB[i]++;
                        V[i] += c - A[j];
                        A[j] = c;
                    }
                }
                for(int i = max((l / sq + 1) * sq, (r / sq) * sq); i <= r; i++) {
                    if(A[i] > c) F[i]--, FB[r / sq]--;
                    if(A[i] < c) F[i]++, FB[r / sq]++;
                    V[r / sq] += c - A[i];
                    A[i] = c;
                }
            }
        }
        else {
            ll l, r; cin>>l>>r; l--, r--;
            if(t == 2) {
                ll salario = 0;
                for(int i = l; i < min(r + 1, (l / sq + 1) * sq); i++) salario += A[i] + Offset[l / sq];
                for(int i = l / sq + 1; i < r / sq; i++) salario += V[i] + Offset[i] * L[i];
                for(int i = max((l / sq + 1) * sq, (r / sq) * sq); i <= r; i++) salario += A[i] + Offset[r / sq];
                ll g = __gcd(abs(salario), (r - l + 1));
                cout<<salario / g<<"/"<<(r - l + 1) / g<<'\n';
            }
            if(t == 3) {
                ll felicidad = 0;
                for(int i = l; i < min(r + 1, (l / sq + 1) * sq); i++) felicidad += F[i] + FB[l / sq];
                for(int i = l / sq + 1; i < r / sq; i++) felicidad += FB[i] + OffFB[i] * L[i];
                for(int i = max((l / sq + 1) * sq, (r / sq) * sq); i <= r; i++) felicidad += F[i] + OffFB[r / sq];
                ll g = __gcd(abs(felicidad), (r - l + 1));
                cout<<felicidad / g<<"/"<<(r - l + 1) / g<<'\n';
            }
        }
    }







    return 0;
}