#pragma GCC optimize("Ofast")
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
        sort(A.begin(), A.end());
        vi Acc(n + 1, 0); rep(i, n) Acc[i + 1] = Acc[i] + A[i];
        vi Rev(n + 1, 0); 
        for(int i = n - 1, j = 0; j < n; j++, i--){
            Rev[j + 1] = Rev[j] + A[i]; 
        } 
        
        bool pos = 0;
        repx(i, 1, n) { // i es la cantidad de elementos chicos
            auto it = upper_bound(Rev.begin(), Rev.end(), Acc[i]);
            // cout<<"L: "<<i<<' '<<Acc[i]<<'\n';
            // cout<<"R: "<<it - Rev.begin()<<' '<<*it<<'\n';
            if(it - Rev.begin() != n + 2 and it - Rev.begin() + i <= n and it - Rev.begin() < i) {
                // cout<<"siuuuu\n";
                pos = 1;
            }
        }
        if(pos) cout<<"YES\n";
        else cout<<"NO\n";
    }


    return 0;
}