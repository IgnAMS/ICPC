#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)


int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin>>n;
    vector<int> boys(n);
    rep(i,n) cin>>boys[i];
    int m;
    cin>>m;
    int acc[102];
    memset(acc,0,sizeof(acc));
    int x;
    rep(i,m) {cin>>x; acc[x]++;}
    sort(boys.begin(),boys.end());
    int cont=0;
    //cout<<acc[5]<<endl;
    rep(i,n){
        //cout<<"boys: "<<boys[i]<<endl;
        for(int j=boys[i]-1; j<=boys[i]+1;j++){
            //cout<<j<<" "<<acc[j]<<endl;
            if(acc[j]>0){
                //cout<<"tomo a la niña "<<boys[i]<<" "<<j<<endl;
                acc[j]--;
                cont++;
                break;
            }
        }
    }
    cout<<cont<<endl;

    return 0;
}