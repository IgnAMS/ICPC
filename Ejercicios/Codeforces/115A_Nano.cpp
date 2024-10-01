#include<bits/stdc++.h>
using namespace std;

vector<vector<bool> > mat;
vector<bool> visit;
vector<int> aux;

void printm(int n){
  cout<<"-  ";
  for(int i=0;i<n;i++){
    cout<<i<<"  ";
  }
  cout<<endl;
  for(int a=0;a<n;a++){
    cout<<a<<"  ";
    for(int b=0;b<n;b++){
      cout<<mat[a][b]<<"  ";
    }
    cout<<endl;
  }
  cout<<endl;
}

void dfs(int a,int n){
  if(visit[a]) return;
  visit[a]=true;
  aux.push_back(a);
  for(int i=0;i<n;i++){
    if(i==a) continue;
    if(!mat[a][i]) dfs(i,n);
  }
}

int main(){
  int n;
  cin>>n;
  mat.assign(n,vector<bool>(n,true));
  int h;
  vector<vector<pair<int,int> > > AdjList;
  for(int i=0;i<n;i++){
    cin>>h;
    if(h==-1) continue;
    h--;
    mat[i][h]=false;
  }

  printm(n);

  for(int i=0;i<n;i++){
    aux.clear();
    visit.assign(n,false);
    dfs(i,n);
    for(int j=1;j<aux.size();j++){
      mat[i][aux[j]]=false;
    }
  }
  printm(n);

  visit.assign(n,false);
  for(int i=0;i<n;i++){
    vector<int> xd;
    xd.push_back(i);
    vector<pair<int,int> > meh;
    if(visit[i]) continue;
    for(int j=i+1;j<n;j++){
      bool asd=true;
      if(visit[j]) continue;
      /*for(int h=0;h<n;h++){
        //printf("%d y %d estan en %d, %d y %d estan en %d\n",i,h,mat[i][h],j,h,mat[j][h]);
        //cout<<i<<" "<<j<<" "<<h<<" "<<" "<<mat[i][h]<<" "<<mat[h][j]<<endl;
        if(!mat[i][h] && !mat[j][h]) asd=false;
      }*/
      for(int h=0;h<meh.size();h++){
        if(!mat[j][meh[h].second]){
          cout<<"No pueden ir juntos "<<j<<" "<<meh[h].second<<endl;
          asd=false;
        }
      }
      if(!mat[i][j] || !mat[j][i]) asd=false;
      if(asd){
        xd.push_back(j);
        meh.push_back(pair<int,int>(i,j));
        cout<<i<<" "<<j<<endl;
        visit[i]=true;
        visit[j]=true;
      }
    }
    if(!meh.empty()) AdjList.push_back(meh);
  }
  int cont=0;
  for(int i=0;i<n;i++) if(!visit[i]){
    cont++;
    cout<<i<<endl;
  }
  cont+=(int)AdjList.size();
  cout<<cont<<endl;

  return 0;
}
