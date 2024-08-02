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
// g++ -std=c++14 G2.cpp -o a && a <input.txt> output.txt
// ulimit -s 1000000
// g++ -O2 D.cpp && time ./a.out <input.txt> output.txt

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll R[1000];
    ll largo = 30;
    ll largo1 = largo;
    cin>>R[0];
    ll pos = 0;
    repx(i, 1, largo) {
        pos++;
        cout<<"? right"<<endl;
        cin>>R[i];
    }
    ll ans = -1;
    cout<<"? flip"<<endl;
    cin>>R[pos];
    // rep(i, largo) cout<<R[i]<<' '; cout<<endl;

    rep(i, largo - 1) {
        pos--;
        cout<<"? left"<<endl;
        ll x; cin>>x;
        if(x != R[largo - i - 2] and i + 1 >= 3) {
            ans = i + 1;
            break;
        }
    }
    if(ans != -1) {
        cout<<"! "<<ans<<endl;
        return 0;
    }
    // largo * 2 + 1 queries <= 200

    largo = 30;
    ll A[largo] = {
        0, 1, 0, 1, 0, 0, 1, 0, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 
        1, 1, 0, 0, 1, 0, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1
    };
    

    if(A[0] != R[0]) {
        cout<<"? flip"<<endl;
        cin>>R[0];
    }
    repx(i, 1, largo) {
        cout<<"? right"<<endl;
        cin>>R[i];
        if(R[i] != A[i]) {
            cout<<"? flip"<<endl;
            cin>>R[i];
        }
    }
    // 2 * largo <= 60

    ll Last[largo];
    rep(i, largo) Last[i] = A[i];
    pos = 0;
    ll xd = 0;
    while(xd++ < 15100) {
        pos++;
        rep(i, largo - 1) Last[i] = Last[i + 1];
        cout<<"? right"<<endl;
        cin>>Last[largo - 1];
        bool posible = 1;

        // rep(i, largo) cout<<Last[i]<<' '; cout<<endl;
        // rep(i, largo) cout<<A[i]<<' '; cout<<endl;

        rep(i, largo) if(Last[i] != A[i]) posible = 0;

        if(posible and pos >= largo1) {
            cout<<"! "<<pos<<endl;
            break;
        }
    }

    return 0;
}