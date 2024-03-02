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
    cout<<"? "<<l<<' '<<r<<endl;
    cin>>res;
    while(r - l > 2) {
        int m = (l + r) / 2;
        if(res == -1) {
            cout<<"? "<<l<<' '<<r<<endl;
            cin>>res;
        }
        if(l <= res and res <= m) {
            cout<<"? "<<l<<' '<<m<<endl;
            cin>>res2;
            if(res == res2) r = m;
            else res = -1, l = m + 1;
        }
        else {
            cout<<"? "<<m + 1<<' '<<r<<endl;
            cin>>res2;
            if(res == res2) l = m + 1;
            else res = -1, r = m;
        }
    }

    // aosdkasokdsaokdasodoaskdoksadoksaok xddd
    if(r - l == 2) {
        if(res == l) {
            l++;
            cout<<"? "<<l<<' '<<r<<endl;
            cin>>res;
        }
        else if(res == r) {
            r--;
            cout<<"? "<<l<<' '<<r<<endl;
            cin>>res;
        }
        else if(res == l + 1) {
            cout<<"? "<<l<<' '<<l + 1<<endl;
            cin>>res;
            if(res == l + 1) r--;
            else res = l + 1, l++;
        }
    }

    if(res == l) cout<<"! "<<r<<endl;
    else cout<<"! "<<l<<endl;



    return 0;
}