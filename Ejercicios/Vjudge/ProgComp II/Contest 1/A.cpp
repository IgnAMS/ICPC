#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
#define rep(i,n) for(int i=0;i<n;i++)

int main(){
    int n, q; cin>>n>>q;
    deque<ll> arr(n);
    rep(i,n) cin>>arr[i];

    vector<ll> que(q);
    unordered_map<ll,ii> mapa;
    rep(i,q) {cin>>que[i]; mapa.insert({que[i],ii(-1,-1)});}
    if(q==0) return 0;

    ll ind=0;
    deque<ll> aux=arr;
    int a, b;
    int cont=0;
    for(int i=0;i<n;i++){
        a=aux.front(); aux.pop_front();
        b=aux.front(); aux.pop_front();
        if(b>a){
            ind=i;
            aux.push_front(b);
            aux.push_back(a);
        }
        else{
            aux.push_front(a);
            aux.push_back(b);
        }
        if(mapa.count(i+1)){
            mapa[i+1]={a,b};
        }
    }

    for(int i=0;i<=ind;i++){
        a=arr.front(); arr.pop_front();
        b=arr.front(); arr.pop_front();
        if(b>a){
            arr.push_front(b);
            arr.push_back(a);
        }   
        else{
            arr.push_front(a);
            arr.push_back(b);
        }
    }

    for(int i=0;i<q;i++){
        if(que[i]<=n){
            cout<<mapa[que[i]].first<<" "<<mapa[que[i]].second<<endl;
        }
        else{
            cout<<arr[0]<<" "<<arr[(que[i]-ind-2)%(n-1)+1]<<endl;
        }
    }




    return 0;
}