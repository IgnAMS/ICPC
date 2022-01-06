#include<bits/stdc++.h>
using namespace std;
vector<int> sz;
vector<int> id;
int numComp;

typedef pair<int,int> ii;
typedef pair<double,ii> iii;
typedef vector<ii> vii;
typedef pair<string,int> si;

void init(int tam){
  numComp=tam;
  sz.assign(tam,1);
  id.assign(tam,int());
  for(int i=0;i<tam;i++){
    id[i]=i;
  }
  return;
}
int Find(int p){
  int root=p;
  while(root != id[root]) root=id[root];

  while(p!=root){
    int next=id[p];
    id[p]=root;
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
    id[root1]=root2;
  }
  else{
    sz[root1]+=sz[root2];
    id[root2]=root1;
  }
  numComp--;
  return;
}


int main(){
  int n,k;
  vector<vector<int> > ans;
  while(cin>>n>>k){
    if(n==0 && k==0) break;

    vector<iii> AdjList;
    int a,b,c;
    for(int i=0;i<k;i++){
      cin>>a>>b>>c;
      AdjList.push_back(iii(c,ii(a,b)));
    }

    sort(AdjList.begin(),AdjList.end());
    init(n);
    int cost=0;
    vector<int> useless;
    for(int i=0; i<AdjList.size(); i++){
      iii tmp=AdjList[i];
      if(!connected(tmp.second.first,tmp.second.second)){
        unify(tmp.second.first,tmp.second.second);
        cost+=tmp.first;
      }
      else{
        useless.push_back(tmp.first);
      }
    }
    ans.push_back(useless);

  }
  for(int i=0;i<ans.size();i++){
    for(int j=0;j<ans[i].size();j++){
      cout<<ans[i][j];
      if(j<ans[i].size()-1) cout<<" ";
    }
    if(ans[i].size()==0) cout<<"forest";
    cout<<endl;


  }

  return 0;
}




