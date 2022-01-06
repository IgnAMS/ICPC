#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
#define mp make_pair
#define ff first
#define ss second.first
#define tt second.second


int main(){
    int n; cin>>n;
    priority_queue<iii,vector<iii>,greater<iii>> pq;
    int a,b,c;
    rep(i,n){
        cin>>a>>b>>c;
        pq.emplace(mp(a,mp(b,c)));
        

    }




    return 0;
}