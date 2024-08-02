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

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        vl A(n); 
        ll imp = 0, sum = 0, sum2 = 0;
        set<pll> S;
        rep(i, n) {
            cin>>A[i];
            if(A[i] == 0) continue;

            sum2++;
            imp += (A[i] & 1);
            sum += A[i] - 1;
            S.insert({A[i], i});
        }

        if((imp & 1) == 0 or sum < sum2 - 1) {
            cout<<"NO\n";
        }
        else {
            cout<<"YES\n";
            bool uno = 0;
            bool turno = 0;
            while(!S.empty()) {
                int x, i;
                if(uno) {
                    tie(x, i) = *S.rbegin();
                    S.erase(*S.rbegin());
                }
                else {
                    tie(x, i) = *S.begin();
                    S.erase(S.begin());
                }

                if(turno == 1 and x == 1) {
                    uno = 1;
                    S.insert({x, i});
                    continue;
                }

                turno = !turno;
                
                cout<<i + 1<<' ';
                if(x == 1) {
                    uno = 1;
                }
                else {
                    uno = 0;
                    S.insert({x - 1, i});
                }
            }
            cout<<'\n';
        }
    }





    return 0;
}