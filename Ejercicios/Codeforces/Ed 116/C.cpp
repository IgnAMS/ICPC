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


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--){
        ll n, k; cin>>n>>k;
        ll A[n]; rep(i, n) cin>>A[i];
        ll acc = 0;
        string ans = "";
        int i = 0;
        ll pot10[12]; pot10[0] = 1; repx(i, 1, 12) pot10[i] = pot10[i-1] * 10;
        while(acc <= k){ // a lo mas 10 pasos
            ll dif = 11;
            if(i+1 < n) dif = A[i+1] - A[i], i++;
            ll agregar = min(k + 1 - acc, pot10[dif] - 1);
            // cout<<"llevo "<<acc<<" agregare "<<agregar<<" llegando a "<<acc+agregar<<'\n';
            acc += agregar;
            string aux = to_string(agregar);
            reverse(aux.begin(), aux.end());
            ans += aux;
            
        }
        reverse(ans.begin(), ans.end());
        cout<<ans<<'\n';
    }    

    return 0;
}