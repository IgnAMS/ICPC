#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
#define rep(i,n) for(ll i=0;i<n;i++)
#define ff first
#define ss second


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int m; cin>>m;

    while(m--){
        ll n,t,a,b; cin>>n>>t>>a>>b;
        vector<ll> arr(n);
        vector<ii> test(n);
        multiset<ll> isi;
        multiset<ll> hard;

        rep(i,n) cin>>arr[i];
        rep(i,n) {
            cin>>test[i].ff; 
            test[i].ss=(arr[i]==0? a:b);
            if(arr[i]==0) isi.insert(test[i].ff);
            else hard.insert(test[i].ff);  
        }
        //los ordeno segun tiempo de llegada, y si no por dificultad
        sort(test.begin(),test.end());

        ll cont=0;
        ll ti=0;
        ll cont2=0;
        ll cont3=0;
        ll ans=0;
        rep(i,n){
            cont2=0, cont3=0;
            //reviso cuantas puedo hacer para un t[i]-1
            //printf("%d\n",test[i].ff-ti-1);
            if(test[i].ff-ti-1 >= 0 && ti <= t){
                cont2=min((test[i].ff-ti-1)/a , ll(isi.size()));
                if(test[i].ff-cont2*a-ti-1>=0){
                    cont3=min((test[i].ff-cont2*a-ti-1)/b,ll(hard.size()));
                }
                
                //printf("cont2: %lld, cont3: %lld, i: %lld, ti: %lld\n",cont2,cont3,i,ti);
                ans=max(ans,cont2+cont3+i);
            
            }
            //printf("%d, isi: %d, %d, %d\n",cont2,int(isi.size()),cont3,i);
            
            ti+=test[i].ss;
            if(isi.count(test[i].ff)) isi.erase(isi.find(test[i].ff));
            else hard.erase(hard.find(test[i].ff));
        }
        //printf("tf: %d\n",ti);
        if(ti<=t){
            ans=n;
        }
        //mientras pueda resolver faciles lo hace
        printf("%d\n",ans);
    }

    return 0;
}