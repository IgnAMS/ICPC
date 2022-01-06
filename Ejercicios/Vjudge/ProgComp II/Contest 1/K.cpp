#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
#define rep(i,n) for(int i=0;i<n;i++)
#define ff first
#define ss second
struct per{
    int s,h,id;
    per(int s, int h, int id): s(s), h(h), id(id) {};
};


int main(){
    int t; cin>>t;
    while(t--){
        vector<per> v;
        int m,q; cin>>m>>q;
        //m la cantidad de personas
        //q la cantidad de queries
        rep(i,m){
            int id,s,h; 
            cin>>id>>s>>h;
            v.push_back(per(s,h,id));
        }
        sort(v.begin(),v.end(),[&](const per &a, const per &b){
            if(a.s==b.s) return a.h<b.h;
            return a.s<b.s;
        });

        priority_queue<ii,vector<ii>,greater<ii>> pq;
        map<int,int> boss, conts;
        rep(i,m){
            conts.insert({v[i].id,0});
            boss.insert({v[i].id,0});
            while(!pq.empty() && pq.top().ff <= v[i].h){
                conts[v[i].id]+=conts[pq.top().ss]+1;
                boss[pq.top().ss]=v[i].id;
                pq.pop();
            }
            pq.push({v[i].h,v[i].id});
        }
        rep(i,q){
            int id; cin>>id;
            cout<<boss[id]<<" "<<conts[id]<<endl;
        }
    }



    return 0;
}