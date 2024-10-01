#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        //cout<<n<<"\n";
        multiset<ll> s;
        ll arr[n];
        rep(i,n) { cin>>arr[i]; s.insert(arr[i]); }
        ll tomax=0;
        rep(i,n) tomax+= (*s.rbegin())-arr[i];
        ll maxi=0;
        rep(i,n){
            ll aux=arr[i];
            ll toaux= tomax-(*s.rbegin()-aux); //saco la diferencia al maximo
            s.erase(s.find(aux));
            if(*s.rbegin() < aux) {
                toaux-=(aux-*s.rbegin())*(n-1); //calculo el nuevo maximo
            }

            //cout<<toaux<<" ";
            toaux= aux-toaux;
            //cout<<toaux<<"\n";
            if(toaux<0) maxi=max(maxi,-toaux);
            else if((toaux)%(n-1)==0) maxi=maxi;
            else maxi= max(maxi,(n-1)-(toaux)%(n-1));
            s.insert(aux);
        }

        cout<<maxi<<"\n";
    }



    return 0;
}