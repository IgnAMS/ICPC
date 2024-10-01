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

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vi L(n), R(n), C(n);
        rep(i, n) cin>>L[i]>>R[i]>>C[i];
        ll lcost = 0, rcost = 0, cost = 0, l = 1e10, r = 0;
        rep(i, n){
            if(L[i] == l and R[i] == r and C[i] <= cost){
                cost = C[i], lcost = rcost = 0;
            }
            else if(L[i] < l and R[i] >= r){ // lo cambio todo
                cost = C[i], lcost = rcost = 0;
            }
            else if(L[i] <= l and R[i] > r){
                cost = C[i], lcost = rcost = 0;
            }
            
            else if(L[i] < l and R[i] < r){ // anado por la izq
                rcost = cost - lcost;
                cost = cost + C[i] - lcost;
                lcost = C[i];
            }
            else if(L[i] > l and R[i] > r){ // anado por la derecha
                lcost = cost - rcost;
                cost = cost + C[i] - rcost;
                rcost = C[i];
            }

            else if(L[i] == l and C[i] < lcost){
                rcost = cost - lcost;
                cost = cost + C[i] - lcost;
                lcost = C[i];
            }
            else if(R[i] == r and C[i] < rcost){
                lcost = cost - rcost;
                cost = cost + C[i] - rcost;
                rcost = C[i];
            }
            
            l = min(l, L[i]), r = max(r, R[i]);
            cout<<cost<<'\n';
        }
    }





    return 0;
}