#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<ll, ll> ii;
typedef double db;
typedef vector<ll> vi;
#define ff first
#define ss second
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
//  g++ -O2 D.cpp && time ./a.out < input.txt > output.txt
ll inf = 10000000000;


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    vector<vi> A; 
    rep(i, n) {
        int a, b; cin>>a>>b; A.push_back({a, -b, i});
    }
    sort(A.begin(), A.end());
    for(auto& u: A) u[1] = -u[1];

    ll lx = inf, rx = -inf;
    int ans = -2;
    rep(i, A.size()) {
        if(A[i][0] > rx + 1) {
            lx = A[i][0], rx = A[i][1];
            continue;
        }
        ll maxi = rx;
        ll prev = -1;
        while(i < n and A[i][0] <= rx + 1) {
            // cout<<A[i][2]<<": "<<A[i][1]<<' '<<maxi<<'\n';
            if(A[i][1] <= maxi) ans = A[i][2];
            if(A[i][1] > maxi) {
                if(prev != -1) ans = prev;
                // cout<<i<<' '<<prev<<'\n';
                maxi = A[i][1];
                prev = A[i][2];
            }
            i++;
        }
        i--;
        if(maxi > rx) rx = maxi;
    }
    cout<<ans + 1<<'\n';



    return 0;
}