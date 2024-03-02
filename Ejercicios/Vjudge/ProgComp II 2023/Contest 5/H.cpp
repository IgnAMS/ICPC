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
    int n; cin>>n;
    ll l = 1, r = n;
    ll res, res2;
    cout<<"? "<<1<<' '<<n<<endl;
    cin>>res;
    if(res == 1) {
        l = 2, r = n;
        while(l < r) {
            ll m = (l + r) / 2;
            cout<<"? "<<1<<' '<<m<<endl;
            cin>>res2;
            if(res2 == res) r = m;
            else l = m + 1;
        }
    }
    else if(res == n) {
        l = 1, r = n - 1;
        while(l < r) {
            ll m = (l + r + 1) / 2;
            cout<<"? "<<m<<' '<<n<<endl;
            cin>>res2;
            if(res2 == res) l = m;
            else r = m - 1;
        }
    }
    else {
        cout<<"? "<<1<<' '<<res<<endl;
        cin>>res2;
        if(res2 == res) {
            l = 1, r = res - 1;
            while(l < r) {
                ll m = (l + r + 1) / 2;
                cout<<"? "<<m<<' '<<res<<endl;
                cin>>res2;
                if(res2 == res) l = m;
                else r = m - 1;
            }
        }
        else {
            l = res + 1, r = n;
            while(l < r) {
                ll m = (l + r) / 2;
                cout<<"? "<<res<<' '<<m<<endl;
                cin>>res2;
                if(res2 == res) r = m;
                else l = m + 1;
            }
        }
    }
    cout<<"! "<<l<<endl;


    return 0;
}