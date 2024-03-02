#include <bits/stdc++.h>  
using namespace std;  
typedef long long ll; 
typedef pair<ll, ll> pll; 
 
 
vector<vector<int>> graph;  
vector<int> dist;  
vector<int> parent;  
 
pll bfs_visit(int s, ll count1, ll count2){  
    queue<int> Q; 
    Q.push(s);  
    dist[s] = 0; 
    while (!Q.empty()){ 
         
        int u = Q.front(); 
        Q.pop();  
         
        if(!(dist[u]%2)) count1 += 1;  
        else count2 += 1; 
        //cout<<u<<" "<<dist[u]<<"\n"; 
        for (auto v : graph[u]){  
            if (dist[v] == -1){  
                dist[v] = dist[u] +1;  
                parent[v] = u;  
                //cout <<v << " " << count1 << " " << count2 << "\n";  
                Q.push(v);  
                 
            }  
        }  
    }  
    return {count1,count2}; 
}  
  
pll bfs() {  
    ll c = 0,d = 0; 
    dist.resize(graph.size(), -1);  
    parent.resize(graph.size(), -1);  
    for (int u = 0; u < graph.size(); u++){  
        if (dist[u] == -1){  
            tie(c,d) = bfs_visit(u,c,d);  
        }  
    }  
    return {c,d}; 
}  
  
int main(){  
    ll n,m;  
    cin >> n;  
    m=n-1; 
    graph.assign(n, {});  
    for (int j = 0; j < m; j++){  
        int a,b; 
        cin >> a>>b; 
        graph[a - 1].push_back(b - 1);  
        graph[b - 1].push_back(a - 1);  
    }  
    ll c,d;  
    tie(c, d) = bfs();  
    cout << c*d -n +1 << "\n";  
}