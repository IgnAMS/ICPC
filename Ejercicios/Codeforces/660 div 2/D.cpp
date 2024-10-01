#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

#define INF (int)1e9
#define pb push_back
#define OJ                            \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);


vector<vi> AdjList;
vector<bool> extrem;
vector<ll> a;
vector<int> camino;
ll ans=0;
deque<int> porvisitar;
void dfs(int u, int ant){
    for(int i=0;i<AdjList[u].size();i++){
        dfs(AdjList[u][i],u);
    }
    
    if(a[u]>0){
        if(ant!=-1){
            a[ant]+=a[u];
        }
        camino.push_back(u+1);
        ans+=a[u];
    }
    else{
        //cout<<"no tomaremos el "<<u+1<<" porque tiene valor: "<<a[u]<<endl;
        porvisitar.push_front(u);
    }
    
    return;
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cout.tie(0);
    //OJ;
    int n; cin>>n;
    extrem.assign(n,true);
    AdjList.assign(n,vi());
    a.resize(n);
    int b[n];
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++){
        cin>>b[i];
        if(b[i]!=-1){
            //el nodo al que llegare no es extremo
            AdjList[b[i]-1].push_back(i);
        }
    }
    deque<ii> q;
    vector<int> visited(n,false);
    for(int i=0;i<n;i++){
        if(b[i]==-1){
           dfs(i,-1);
        }
    }
    for(int i=0;i<porvisitar.size();i++){
        ans+=a[porvisitar[i]];
        camino.push_back(porvisitar[i]+1);
    }
    cout<<ans<<endl;
    for(int i=0;i<camino.size();i++){
        cout<<camino[i];
        if(i<camino.size()-1) cout<<" ";
    }
    cout<<endl;
    


    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
    //g++ -O2 [path] && time ./a.out < in > out
}