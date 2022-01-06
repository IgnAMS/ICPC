#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;
typedef double db;
typedef pair<db,db> ii;
#define x first
#define y second
#define invrep(i,n) for(int i=n-1; i>=0; i--)


int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<ii> P(n); rep(i,n) cin>>P[i].x>>P[i].y;
        sort(P.begin(), P.end());
        int maxy = 0;
        double ans = 0; 
        invrep(i, n-1){
            if(P[i] == P[i+1]) continue;
            double m_inv = (P[i+1].x - P[i].x) / ((P[i+1].y - P[i].y));
            if(P[i].y > maxy){
                double x_aux = m_inv * (maxy - P[i].y) + P[i].x;
                // cout<<P[i].x<<" "<<P[i].y<<" "<<x_aux<<"\n";
                ans += sqrt((x_aux - P[i].x) * (x_aux - P[i].x) + (maxy - P[i].y) * (maxy - P[i].y));
                maxy = P[i].y;
            }    
        }
        cout<<setprecision(2)<<fixed<<ans<<"\n";
    }


    return 0;
}