#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;
typedef pair<int,int> ii;
#define x first
#define y second

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--){
        int n,k; cin>>n>>k;
        vector<ii> cord(n);
        rep(i,n) cin>>cord[i].x>>cord[i].y;
        bool flag=0;
        rep(i,n){
            int cont=0;
            ii u= cord[i];
            rep(j,n){
                ii v=cord[j];
                if(abs(u.x-v.x)+abs(u.y-v.y)<=k) cont++;
            }
            if(cont==n) flag=1;
        }
        if(flag) cout<<1<<"\n";
        else cout<<-1<<"\n";
    }



    return 0;
}