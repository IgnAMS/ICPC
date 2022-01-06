#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;
#define ff first
#define ss second
#define uset unordered_set
typedef pair<int,int> ii;

vector<uset<int>> adj;
set<pair<int,int>> s;

void remo(set<ii>::iterator it){
    int u=it->ss;
    s.erase(it);
    for(int v: adj[u]){
        auto _it=s.find({adj[v].size(),v});
        adj[v].erase(u);
        s.erase(_it);
        s.insert({adj[v].size(),v});
    }
}

int main(){
    int n,m,a,b;
    while(cin>>n>>m>>a>>b){
        adj.clear();
        s.clear();
        adj.resize(n);
        int x,y;
        int maxi=0;
        
        //tener un set ordenado por degree
        //los que estan al inicio mueren por A
        //los que estan al final del set mueren por B 

        rep(i,m){
            cin>>x>>y;
            x--, y--;
            adj[x].insert(y);
            adj[y].insert(x);
        }

        rep(i,n) s.insert({adj[i].size(),i});
        bool flag=true;

        while(true){
            flag=false;
            while(!s.empty() && s.begin()->ff < a){
                remo(s.begin());
                flag=true;
            }
            while(!s.empty() && (s.size() - s.rbegin()->ff -1) < b){
                remo(prev(s.end()));
                //tambien es valido prev(s.end())
                flag=true;
            }
            if(!flag) break;
        }
        cout<<s.size()<<endl;
    }


    return 0;
}