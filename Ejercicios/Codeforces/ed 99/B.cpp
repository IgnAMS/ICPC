#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
#define ff first
#define ss second




int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    vector<int> D((int)2*1e6+2,-1);
    D[int(1e6)]=0;
    priority_queue<iii,vector<iii>,greater<iii>> q; //d,nodo, k
    q.push(iii(0,ii(1e6,1)));
    cerr<<"estoy vivo"<<"\n";

    while(!q.empty()){
        int u=q.top().ss.ff, k=q.top().ss.ss, d=q.top().ff;
        if(abs(1e6-u)<20) cerr<<"estoy visitando a "<<u-(int)1e6<<" con dist "<<d<<"\n";
        q.pop();
        if(D[u]<d) continue;
        //cerr<<u<<"\n";
        if(u+k<=2*1e6+2 && (D[u+k] > d+1 || D[u+k]==-1)){
            q.push(iii(d+1,ii(u+k,k+1)));
            D[u+k]=d+1;
        }
        if(u-1>=0 && (D[u-1]==-1 || D[u-1] > d+1)){
            q.push(iii(d+1,ii(u-1,k+1)));
            D[u-1]=d+1;
        }
        if(u+(k*(k+1))/2 >= 0 && (D[u+k*(k+1)/2]==-1 || D[u+k*(k+1)/2] >d+1)){
            q.push(iii(d+1,ii(u-1,k+1)));
            D[u-1]=d+1;
        }
    }

    
    while(t--){
        int x; cin>>x;
        cout<<D[int(x+1e6)]<<"\n";
    }

    return 0;
}