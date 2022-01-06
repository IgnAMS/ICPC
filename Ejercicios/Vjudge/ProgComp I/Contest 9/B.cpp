#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define repx(i, a, b) for(int i=a; i<b; i++)
typedef long long ll;



int main(){
    ll ts, tf, t;
    ll n, h;
    cin>>ts>>tf>>t>>n;
    queue<ll> Q; rep(i,n) { cin>>h; Q.push(h); }
    ll act = ts;
    ll ans = -1, mini = 1e13;
    while(act < tf){
        if(!Q.empty() && Q.front() <= act) { 
            if(act + t <= tf && mini > act - Q.front() + 1) {
                ans = Q.front() - 1; mini = act - Q.front() + 1;
            }
            act += t; Q.pop();
        }
        else {
            if(act + t <= tf)  {ans = act, mini = 0; break;} // si no esta ocupado, entonces la rspuesta es 0
            else break; 
        }
    }
    cout<<ans<<"\n";
    




    return 0;
}