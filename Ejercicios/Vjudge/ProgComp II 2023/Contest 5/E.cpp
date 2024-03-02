#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma") // could make sigill runtime error
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
    ll n; cin>>n;
    ll l = 1, r = n;
    ll L = -1, R = -1, resp;
    ll m = (l + r) / 2;
    cout<<"? "<<l<<' '<<r<<' '<<endl;
    cin>>resp;
    while(r - l > 2) {
        ll m = (l + r) / 2;
        cout<<"? "<<l<<' '<<m<<endl;
        cin>>L;
        cout<<"? "<<m+1<<' '<<r<<endl;
        cin>>R;

        if(resp == L) r = m, resp = L;
        else if(resp == R) l = m + 1, resp = R;
        else if(l <= resp and resp <= m) l = m + 1, resp = R;
        else if(m+1 <= resp and resp <= r) r = m, resp = L;
    }

    if(r - l == 2) {
        if(resp == l) {
            l++;
            cout<<"? "<<l<<' '<<r<<endl;
            cin>>resp;
        }
        else if(resp == r) {
            r--;
            cout<<"? "<<l<<' '<<r<<endl;
            cin>>resp;
        }
        else if(resp == l + 1) {
            cout<<"? "<<l<<' '<<l + 1<<endl;
            cin>>resp;
            if(resp == l + 1) r--;
            else resp = l + 1, l++;
        }
    }

    if(resp == l) cout<<"! "<<r<<endl;
    else cout<<"! "<<l<<endl;
    

    return 0;
}