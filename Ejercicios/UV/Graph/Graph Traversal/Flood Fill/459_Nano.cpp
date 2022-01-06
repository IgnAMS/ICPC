#include<bits/stdc++.h>
using namespace std;
vector<int> sz;
vector<int> id;
int numComp;

void init(int tam){
  numComp=tam;
  sz.assign(tam,1);
  id.assign(tam,int());
  for(int i=0;i<tam;i++) id[i]=i;
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
  return root;
}

bool connected(int p,int q){
  return Find(p)==Find(q);
}

void unify(int p, int q){
  int root1= Find(p);
  int root2= Find(q);
  if(root1==root2) return;
  else if(sz[root1]>sz[root2]){
    sz[root1]+=sz[root2];
    id[root2]=root1;
  }
  else{
    sz[root2]+=sz[root1];
    id[root1]=root2;
  }
  numComp--;
  return;
}




int main(){
  int t;
  cin>>t;
  vector<int> ans;
  while(t--){

    char a;
    cin>>a;
    init(a-'A'+1);
    string linea;
    getchar();
    while(getline(cin,linea)){
      if((int)linea.size() < 1) break;

      unify(linea[0]-'A', linea[1]-'A');
      //cout<<"se unio "<<linea[0]<<" con "<<linea[1]<<" dejando un total de ";
      //cout<<numComp<<" comps"<<endl;
    }
    ans.push_back(numComp);

  }
  for(int i=0;i<ans.size();i++){
    cout<<ans[i]<<endl;
    if(i<ans.size()-1) cout<<endl;
  }
  //cout<<"a\n";


  return 0;
}
