#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
typedef long long ll;



ll mod=1e9+7;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin>>t;
    while(t--){
        ll a,b,c,n;
        cin>>a>>b>>c>>n;
        priority_queue<ll,vector<ll>> pq1;
        priority_queue<ll,vector<ll>,greater<ll>> pq2;

        ll F[n];
        F[0]=1;
        ll sum=1;
        pq2.push(1);

        for(int i=1;i<n;i++){
            ll mid= pq1.size()>=pq2.size()? pq1.top():pq2.top();

            //cout<<"mid: "<<mid<<endl;
            F[i]=(a*mid + b*(i+1) + c)%mod;
            //cout<<"agrego "<<F[i]<<endl;

            if(pq2.top()<=F[i]){
                //debo tirarlo para arriba
                pq2.push(F[i]);
                //si luego pq2 tiene mayor tamaño entonces el mas bajo lo tiro abajo
                if(pq2.size()>pq1.size()){
                    pq1.push(pq2.top());
                    pq2.pop();
                }
            }

            else if(F[i]<pq2.top()){
                pq1.push(F[i]);
                if(pq1.size()>pq2.size()){
                    pq2.push(pq1.top());
                    pq1.pop();
                }
            }

            sum+=F[i];
            
        }
        cout<<sum<<endl;
    }




    return 0;
}