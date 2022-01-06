#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;
typedef pair<int,int> ii;

vector<int> res;
vector<vector<int>> ans;
int vis;
vector<int> aux;

void dfs(int V, int R){
    if(V==0){
        ans.push_back(aux);
        return;
    }
    rep(i,26){
        if(V&(1<<i) && !(R&(1<<i))){
            aux.push_back(i);
            dfs(V&~(1<<i), R|res[i]);
            aux.pop_back();
        }
        if(V&(1<<i) && (R&(1<<i))){
            return;
        }
    }
}



int main(){
    int t=0; 
    string linea; getline(cin,linea);
    rep(i,linea.length()) t= t*10+linea[i]-'0';
    while(t--){
        getline(cin,linea);
        getline(cin,linea);
        vis=0;
        for(int i=0;i<linea.length();i+=2) vis|=(1<<(linea[i]-'A'));
        getline(cin,linea);
        //restricciones
        res.assign(26,0);
        for(int i=0;i<linea.length();i+=4) {
            int a=linea[i]-'A';
            int b=linea[i+2]-'A';
            res[b]|=(1<<a);
        }
        ans.clear();
        dfs(vis,0);
        rep(i,ans.size()){
            rep(j,ans[i].size()) 
                cout<<char(ans[i][j]+'A')<<(j<ans[i].size()-1? " ":"\n");
        }
        if(ans.size()==0) cout<<"NO\n";
        if(t) cout<<"\n";
    }




    return 0;
}