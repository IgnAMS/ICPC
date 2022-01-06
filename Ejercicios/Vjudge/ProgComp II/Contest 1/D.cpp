#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
#define rep(i,n) for(int i=0;i<n;i++)
#define ff first
#define ss second


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    priority_queue<ii,vector<ii>,greater<ii>> pq;
    map<int,int> mapa;
    set<int> s;
    rep(i,30000) s.insert(i+1);
    int a,b; char c;
    int T=600;

    while(cin>>a>>c){
        while(!pq.empty() && pq.top().ff <= a){
            if(pq.top().ff==mapa[pq.top().ss] && pq.top().ff<=a){
                mapa.erase(pq.top().ss);
                s.insert(pq.top().ss);
                //cout<<"agrego a "<<pq.top().ss<<" al set"<<endl;
            }
            pq.pop();
        }
        
        if(c=='.'){
            cin>>b;
            if(s.count(b)) cout<<'-'<<endl;
            else{
                cout<<'+'<<endl;
                if(mapa[b]<a+T){
                    mapa[b]=a+T;
                    //cout<<b<<" "<<mapa[b]<<endl;
                    pq.push({a+T,b});
                }
            }
        }
        else{
            pq.push({a+T,*s.begin()});
            mapa.insert({*s.begin(),a+T});
            cout<<*s.begin()<<endl;
            s.erase(*s.begin());
        }
    }





    return 0;
}