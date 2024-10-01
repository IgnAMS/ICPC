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
int cont=0;
vector<bool> visited;
struct MST{
    vector<int> parents;
    map<char,int> mapa;
    MST(){
        parents.assign(26,-1);
    }
    
    int find(int a){
        int root=a;
        while(parents[root]>=0){
            root=parents[root];
            cont++;
        }
        return root;
    }

    int conts(int a){
        int root=a;
        cont=0;
        while(parents[root]>=0){
            if(visited[root]) break;
            //cout<<"el padre de "<<char(root+'a')<<" es "<<char('a'+parents[root])<<endl;
            visited[root]=true;
            root=parents[root];
            cont++;
        }
        //cout<<a<<" "<<char(a+'a')<<" "<<char(root+'a')<<" "<<cont<<endl;
        return cont;
    }


    void Union(char a, char b){
        //a<b por definicion
        int a1=a-'a';
        int b1=find(b-'a');
        if(a1==b1) return;
        //a1 siempre sera el mayor, y procedemos a atacar
        parents[b1]=a1;
        return;
    }

};





int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cout.tie(0);
    //OJ;
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        string linea1,linea2; cin>>linea1>>linea2;
        bool pasa=true;
        set<pair<char,char>> cc;
        vector<pair<char,char>> conexiones;
        for(int i=0;i<n;i++){
            if(linea1[i]>linea2[i]){
                pasa=false;
                break;
            }
            if(linea1[i]!=linea2[i] && !cc.count(make_pair(linea1[i],linea2[i]))){
                conexiones.emplace_back(linea1[i],linea2[i]);
            }
            cc.insert(make_pair(linea1[i],linea2[i])); 
        }

        if(!pasa){
            cout<<-1<<endl;
            continue;
        }
        sort(conexiones.begin(),conexiones.end());
        //set<pair<char,char>>::iterator it;
        MST Tree=MST();
        for(int i=conexiones.size()-1;i>=0;i--){
            Tree.Union(conexiones[i].first,conexiones[i].second);
        }
        int ans=0;
        visited.assign(26,false);
        for(int i=25;i>=0;i--){
            if(!visited[i]){
                ans+=Tree.conts(i);
            }
            
        }
        cout<<ans<<endl;
    }


    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
    //g++ -O2 [path] && time ./a.out < in > out
}