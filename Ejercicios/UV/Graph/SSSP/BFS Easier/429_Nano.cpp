#include<bits/stdc++.h>
using namespace std;

#define INF INT_MAX

typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
  int t;
  cin>>t;
  while(t--){
    vector<string> lib;
    vector<vii> AdjList;
    string linea;
    map<string,int> mapa;
    int key=0;

    while(cin>>linea){
      if(linea=="*") break;

      lib.push_back(linea);
      if(!mapa.count(linea)){
        mapa.insert(pair<string,int> (linea,key));
        key++;
      }
    }

    AdjList.assign(lib.size(),vii());
    for(int i=0;i<lib.size();i++){
      for(int j=i+1;j<lib.size();j++){

        int error=0;
        for(int h=0;lib[i].length()== lib[j].length() && h<lib[i].length(); h++ ){
          if(lib[i][h]!=lib[j][h]) error++;
        }
        if(error==1){
          //printf("%s es vecino de %s y tienen los indices %d y %d\n",lib[i],lib[j],mapa[lib[i]],mapa[lib[j]]);
          AdjList[mapa[lib[i]]].push_back(ii(mapa[lib[j]],0));
          AdjList[mapa[lib[j]]].push_back(ii(mapa[lib[i]],0));
        }

      }
    }

    getchar();
    linea="";
    string pa1,pa2;

    while(getline(cin,linea)){
      if(linea.length()==0) break;
      bool xd=true;
      pa1="",pa2="";
      for(int i=0;i<linea.length();i++){
        if(linea[i]==' '){
          xd=false;
          continue;
        }
        if(xd) pa1+=linea[i];
        else pa2+=linea[i];
      }
      int s=mapa[pa1];
      int d=mapa[pa2];

      vector<int> dist(lib.size(), INF);
      dist[s] = 0;
      queue<int> q;
      q.push(s);

      while (!q.empty()) {
        int u = q.front(); //siendo u la ubicacion actual
        q.pop();

        for (int j = 0; j < (int)AdjList[u].size(); j++) {
        ii v = AdjList[u][j];
          //cout<<v.first<<endl;

          if (dist[v.first] == INF) {
            dist[v.first] = dist[u] + 1;
            q.push(v.first);
          }
        }
      }
      cout <<pa1<<" "<<pa2<<" "<< dist[d] << endl;


    }

    if(t>0) cout<<endl;
  }



  return 0;
}
