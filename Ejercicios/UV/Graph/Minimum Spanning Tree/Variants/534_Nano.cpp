#include<bits/stdc++.h>
using namespace std;
vector<int> sz;
vector<int> idd;
int numComp;

typedef pair<int,int> ii;
typedef pair<double,ii> dii;
typedef vector<ii> vii;
typedef pair<string,int> si;
typedef pair<int,double> id;
typedef vector<id> vid;

void init(int tam){
  numComp=tam;
  sz.assign(tam,1);
  idd.assign(tam,int());
  for(int i=0;i<tam;i++){
    idd[i]=i;
  }
  return;
}
int Find(int p){
  int root=p;
  while(root != idd[root]) root=idd[root];

  while(p!=root){
    int next=idd[p];
    idd[p]=root;
    p=next;
  }
  //cout<<root<<endl;
  return root;
}

bool connected(int p, int q){
  return Find(p) == Find(q);
}

int components(){
  return numComp;
}

void unify(int p, int q){
  int root1=Find(p);
  int root2= Find(q);
  if(root1 == root2) return;
  if(sz[root1]<sz[root2]){
    sz[root2]+=sz[root1];
    idd[root1]=root2;
  }
  else{
    sz[root1]+=sz[root2];
    idd[root2]=root1;
  }
  numComp--;
  return;
}
vector<int> way;
vector<vid> lista;
int next;
bool primer=true;

void dfs(int a){
  if(way[a] != -1) return;
  if(!primer){
    way[a]=next;
    //cout<<a<<" tiene de padre a "<<next<<endl;
  }
  else{
    primer=false;
  }
  next=a;
  for(int i=0;i<lista[a].size();i++){
    dfs(lista[a][i].first);
    //cout<<"el nodo "<<a<<" tiene de vecino a "<<lista[a][i].first<<endl;
  }
  return;
}


int main(){
  int n;
  vector<double> ans;
  while(cin>>n){
    if(n==0) break;
    map<ii,double> mapa;
    double x1,y1;
    double x2,y2;
    cin>>x1>>y1>>x2>>y2;
    vector<ii> pares;
    pares.push_back(ii(x1,y1));
    pares.push_back(ii(x2,y2));

    double xi,yi;
    init(n);
    for(int i=0;i<n-2;i++){
      cin>>xi>>yi;
      pares.push_back(ii(xi,yi));
    }
    vector<dii> AdjList;
    double maxi=0;
    for(int i=0;i<n-1;i++){
      for(int j=i+1;j<n;j++){
        double deltx= abs(pares[i].first-pares[j].first);
        double delty= abs(pares[i].second-pares[j].second);
        //cout<<"deltx y delty valen: "<<deltx<<" "<<delty<<endl;
        double dist= sqrt(deltx*deltx*1.0 + delty*delty*1.0);
        //mini=min(dist,mini);
        AdjList.push_back(dii(dist,ii(i,j)));
      }
    }
    lista.assign(n,vid());
    sort(AdjList.begin(),AdjList.end());
    for(int i=0;i<AdjList.size();i++){
      dii tmp=AdjList[i];
      if(!connected(tmp.second.first, tmp.second.second)){
        unify(tmp.second.first, tmp.second.second);

        lista[tmp.second.first].push_back(id(tmp.second.second,tmp.first));
        lista[tmp.second.second].push_back(id(tmp.second.first,tmp.first));
      }
    }
    int h=0;
    way.assign(n,-1);
    dfs(1);

    while(way[h]!=1){
      maxi=max(maxi,lista[h][way[h]].second);
      h=way[h];
    }
    maxi=max(maxi,lista[h][way[h]].second);


    ans.push_back(maxi);
  }
  for(int i=0;i<ans.size();i++){
    printf("Scenario #%d\n",i+1);
    cout<<"Frog Distance = "<<setprecision(3)<<fixed<<ans[i]<<endl;
    if(i<ans.size()-1) cout<<endl;
  }

  return 0;
}


