#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--){
        int n,m; cin>>n>>m;
        int A[n]; rep(i,n) cin>>A[i];
        map<int,int> Sb;
        int B[n]; rep(i,n) { cin>>B[i]; Sb[B[i]]=i; }
        int Dif[n+1]; memset(Dif,0,sizeof(Dif));
        map<int,vector<int>> mapa;
        int d=0;
        rep(i,n) if(A[i]!=B[i]) {
            Dif[B[i]]++, d++;
            if(!mapa.count(B[i])) mapa[B[i]]={};
            mapa[B[i]].push_back(i);
        }
        int C[m]; 
        rep(i,m) cin>>C[i];
        vector<int> ans;
        queue<int> aux2;
        rep(i,m){
            //mesirve
            if(Dif[C[i]]){
                d-=aux2.size();
                while(!aux2.empty()){
                    int u=aux2.front(); aux2.pop();
                    ans[u]=mapa[C[i]].back(); //los tiro como error
                }
                Dif[C[i]]--, d--;
                ans.push_back(mapa[C[i]].back()); //lo reparo
                mapa[C[i]].pop_back();
                
            }
            else if(Sb.count(C[i])){
                d-=aux2.size();
                while(!aux2.empty()){
                    int u=aux2.front(); aux2.pop();
                    ans[u]=Sb[C[i]]; //los tiro como error
                }
                ans.push_back(Sb[C[i]]); //lo reparo
                //cout<<"reparacion: "<<C[i]<<" "<<Sa[C[i]]<<"\n";
            }
            else{
                d++;
                aux2.push(i);
                ans.push_back(-1);
            }
        }
        
        if(d) cout<<"NO\n";
        else {
            cout<<"YES\n";
            rep(i,m) cout<<ans[i]+1<<" "; cout<<"\n";
        }
        
    }


    return 0;
}