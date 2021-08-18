#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<int,int> ii;
#define ff first
#define ss second
const double PI = acos(-1.0L);


int main(){
    double l, w, h, t;
    while(cin>>l and cin>>w>>h>>t){
        double ans;
        if(t + 1e-12 >= atan(h/l) * 180.0 / PI) ans = h * h * w * tan((90.0 - t) * PI / 180.0) / 2.0;
        else ans = l * w * h - l * l * w * tan(t * PI / 180.0) / 2.0;
        cout<<setprecision(3)<<fixed<<ans<<" mL\n";
    }


    return 0;
}