#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef pair<int,int> ii;
typedef long long ll;

double eps=1e-7;

int main(){ 
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m;
    while(cin>>n && n && cin>>m){
        double A[n]; rep(i,n) cin>>A[i];
        double B[m]; rep(i,m) cin>>B[i];
        vector<double> D;
        rep(i,n) rep(j,m) D.push_back(B[j]/A[i]);
        double maxi=0;
        sort(D.begin(),D.end());
        //rep(i,D.size()) cout<<D[i]<<" "; cout<<"\n";
        rep(i,D.size()-1){
            maxi=max(maxi,D[i+1]/D[i]);
        } 
        int aux= (maxi+eps)*100+0.5;
        maxi=double(aux)/100;
        cout<<setprecision(2)<<fixed<<maxi<<"\n";
    }



    return 0;
}