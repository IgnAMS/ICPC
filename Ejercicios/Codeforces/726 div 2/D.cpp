#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define repx(i,a,b) for(int i=a; i<b; i++)
typedef long long ll;
typedef pair<ll,ll> ii;
#define ff first
#define ss second

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        unordered_map<int, int> mapa;
        queue<int> pq;
        pq.push(n); mapa[n] = 0;
        bool terminado = false;
        while(!pq.empty() and not terminado){
            int u = pq.front(); pq.pop();
            bool flag = true;
            repx(i, 2, sqrt(u) + 1) if(u != i) {
                if(u % i == 0 and !mapa.count(u - i)){
                    pq.push(u - i); 
                    mapa[u - i] = mapa[u] + 1;
                    flag = false;
                }
                if(u % i == 0 and !mapa.count(u - u/i)){
                    pq.push(u - u/i); 
                    mapa[u - u/i] = mapa[u] + 1;
                    flag = false;
                }
            }
            if(flag){
                if(mapa[u] % 2 == 0) cout<<"Bob\n";
                else cout<<"Alice\n";
                terminado = true;
            }
        }
    }



    return 0;
}