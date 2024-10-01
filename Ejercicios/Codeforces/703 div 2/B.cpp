#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;
typedef pair<ll,ll> ii;
#define ff first
#define ss second

vector<ll> x,y;

ll costx(ll i) {
    ll sum=0;
    for(auto& u:x) sum+=abs(u-i);
    return sum; 
}
ll minx(int l, int r) { // convex cost function
    while (l < r) {
        int m = (l+r) >> 1;
        int slope = costx(m+1) - costx(m);
        if (slope >= 0) r = m;
        else l = m+1;
    }
    return l;
}

int maxx(int l, int r) { // concave cost function
    while (l < r) {
        int m = (l+r) >> 1;
        int slope = costx(m+1) - costx(m);
        if (slope <= 0) r = m;
        else l = m+1;
    }
    return l;
}

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        double promx=0, promy=0;
        x.resize(n); y.resize(n);
        map<ll,ll> cx,cy;
        rep(i,n) {
            cin>>x[i]>>y[i];
            if(!cx.count(x[i])) cx[x[i]]=0;
            if(!cy.count(y[i])) cy[y[i]]=0;
            cx[x[i]]++, cy[y[i]]++;
        }
        if(n==1) { cout<<1<<"\n"; continue; }
        
         
         
        
    }



    return 0;
}