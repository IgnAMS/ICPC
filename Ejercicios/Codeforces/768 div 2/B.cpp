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
        vi A(n); rep(i, n) cin>>A[i];
        int i = n - 1; // la ultima posicion que no es A[n - 1]
        ll cont = 0;
        while(i >= 0) {
            while(i >= 0 and A[i] == A.back()) i--;
            if(i < 0) break;
            cont++;
            // cout<<"ahora i esta en "<<i<<" y quedara en "<<i - ll(A.size()) + i + 1<<'\n';
            i -= A.size() - i - 1;
        }
        cout<<cont<<'\n';
        // [0, 1, 2, 3, 4, 5]
        // [1, 1, 1, 3, 4, 5]
        // [1, 1, 1, 3, 5, 5]
    }





    return 0;
}