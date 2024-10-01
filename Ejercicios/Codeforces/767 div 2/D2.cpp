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
    while(t--) {
        int n; cin>>n;
        vector<string> A(n); rep(i, n) cin>>A[i];
        multiset<string> S; rep(i, n) S.insert(A[i]);
        multiset<string> S2; 
        bool ans = 0;
        rep(i, n) {
            S2.insert(A[i]);
            string aux1 = "", aux2 = ""; 
            string aux = A[i]; 
            reverse(aux.begin(), aux.end());
            cout<<aux<<' '<<aux.substr(0, 2)<<'\n';
            if(S.count(aux) or (aux.length() == 3 and (S.count(aux.substr(1, 2)) or S2.count(aux.substr(0, 2))))) { 
                ans = 1;
                break; 
            }
            S.erase(S.find(A[i]));
        }
        
        if(ans) cout<<"YES\n";
        else cout<<"NO\n";
    }





    return 0;
}