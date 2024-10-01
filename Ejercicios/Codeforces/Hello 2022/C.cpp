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
// g++ -std=c++11 C.cpp -o a && a <input.txt> output.txt
//  g++ -O2 D.cpp && time ./a.out < input.txt > output.txt

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vi P(n + 1, 0);
        ll q = 1, ask = 1, curr = 1;
        ll ans = -1;
        ll found = 0;
        while(found != n){
            cout<<"? "<<q<<endl;
            cin>>q; curr = q;
            ans = -1;
            while(ans != q){
                cout<<"? "<<ask<<endl;
                cin>>ans;
                P[curr] = ans;
                curr = ans;
                // repx(i, 1, n+1) cout<<P[i]<<' '; cout<<'\n';
                found++;
            }
            repx(i, 1, n+1) if(P[i] == 0) { q = ask = curr = i; break; }
        }
        cout<<"! ";
        rep(i, n) cout<<P[i+1]<<' '; cout<<endl;
    }






    return 0;
}