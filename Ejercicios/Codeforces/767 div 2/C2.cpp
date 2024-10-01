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

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        vi A(n); rep(i, n) cin>>A[i];
        ll maxi = -1; rep(i, n) maxi = max(A[i], maxi);
        
        vector<ii> B(n); rep(i, n) B[i] = {A[i], i};
        sort(B.begin(), B.end());

        ll k = -1, prek = -1, last = -1;
        vi Ans;
        ll cont = 0;
        while((*lower_bound(B.begin(), B.end(), ii(0, prek))).ff == 0 and k < n) { // log * log * n            
            auto it = lower_bound(B.begin(), B.end(), ii(last + 1, prek));
            while(it != B.end() and (*it).ff == last + 1) {
                last++;
                k = max(k, (*it).ss + 1);
                it = lower_bound(B.begin(), B.end(), ii(last + 1, prek));
            }
            Ans.push_back(last + 1);
            prek = k;
            last = -1;
        }
        rep(i, n - max(k, 0LL)) Ans.push_back(0);
        cout<<Ans.size()<<'\n';
        rep(i, Ans.size()) cout<<Ans[i]<<' '; cout<<'\n';
    }





    return 0;
}