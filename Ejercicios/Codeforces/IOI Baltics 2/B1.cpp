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


vector<vii> AdjList;
vector<bool> visited;
vector<bool> switched;
vector<int> nums;
int cont=0;

void dfs1(int u){
    visited[u]=true;
    for(int i=0;i<AdjList[u].size();i++){
        ii v= AdjList[u][i];
        if(!visited[v.first]){
            //si es esquina lo tomo
            if(nums[v.first]==v.first && AdjList[v.first].size()==1){
                cont+=2;
                int aux=nums[v.first];
                nums[v.first]=nums[u];
                nums[u]=aux;
            }
            dfs1(v.first);
        }
        
    }
    return;
}
void dfs2(int u){
    bool cambiado=false;
    visited[u]=true;
    if(nums[u]!=u) cambiado=true;
    for(int i=0;i<AdjList[u].size();i++){
        ii v=AdjList[u][i];
        if(!visited[v.first]){
            if(nums[u]==u && nums[v.first]==v.first){
                //si no se han cambiado los valores
                cambiado=true;
                cont+=2;
                int aux=nums[v.first];
                nums[v.first]=nums[u];
                nums[u]=aux;
            }
            dfs2(v.first);
        }
    }
    if(!cambiado){
        ii v=AdjList[u][0];
        cont+=2;
        int aux=nums[v.first];
        nums[v.first]=nums[u];
        nums[u]=aux;
    }
    return;
}



int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cout.tie(0);
    OJ;
    int n;
    cin>>n;
    AdjList.assign(n,vii());
    visited.assign(n,false);
    switched.assign(n,false);
    nums.resize(n);
    int a,b;
    for(int i=0;i<n-1;i++){
        nums[i]=i;
        cin>>a>>b;
        AdjList[a-1].push_back(ii(b-1,0));
        AdjList[b-1].push_back(ii(a-1,0));
    }
    nums[n-1]=n-1;

    dfs1(0);
    visited.assign(n,false);
    dfs2(0);

    cout<<cont<<endl;
    for(int i=0;i<n;i++){
        cout<<nums[i]+1;
        if(i<n-1) cout<<" ";
    }
    cout<<endl;


    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
    //g++ -O2 [path] && time ./a.out < in > out
}