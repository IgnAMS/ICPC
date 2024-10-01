  #include<bits/stdc++.h>
  using namespace std;

  vector<int> ans;

  int ddr[]={-1,0,1, 0};
  int ddc[]={ 0,1,0,-1};

  int dr[]={-1,-1,-1,0,1,1, 1, 0};
  int dc[]={-1, 0, 1,1,1,0,-1,-1};

  bool visit[55][55];
  char mat[55][55];

  void limp(){
    ans.clear();
    for(int i=0;i<55;i++){
      for(int j=0;j<55;j++){
        mat[i][j]='.';
        visit[i][j]=false;
      }
    }
  }

  int sist=0;
  int cont=0;

  void dado(int a, int b){
    if(visit[a][b]) return;
    visit[a][b]=true;
    for(int i=0;i<4;i++){
      if(a+ddr[i]<=55 && a+ddr[i]>=0 && b+ddc[i]<=55 && b+ddc[i]>=0 && mat[a+ddr[i]][b+ddc[i]]=='X'){
        dado(a+ddr[i],b+ddc[i]);
      }
    }
  }

  void dfs(int a, int b){
    if(visit[a][b]) return;
    sist++;
    if(mat[a][b]=='X'){
      dado(a,b);
      cont++;
    }
    visit[a][b]=true;
    for(int i=0;i<4;i++){
      if(a+ddr[i]<=55 && a+ddr[i]>=0 && b+ddc[i]<=55 && b+ddc[i]>=0 && mat[a+ddr[i]][b+ddc[i]]!='.'){
        dfs(a+ddr[i],b+ddc[i]);
        //cout<<"entre a la recursion";
      }
    }
  }


  int main(){
    int h,w;
    int t=0;
    bool primer=true;

    while(cin>>w>>h){
      if(w==0 && h==0) break;

      t++;
      limp();
      for(int i=0;i<h;++i){
        for(int j=0;j<w;++j){
          cin>>mat[i][j];
        }
      }
      for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
          cont=0;
          sist=0;
          if(mat[i][j]!='.') dfs(i,j);
          //cout<<sist<<endl;
          if(cont>0) ans.push_back(cont);
        }
      }

      sort(ans.begin(),ans.end());

      if(!primer) cout<<endl;
      cout<<"Throw "<<t<<endl;
      for(int i=0;i<ans.size();i++){
        cout<<ans[i];
        if(i<ans.size()-1) cout<<" ";
      }
      cout<<endl;
      primer=false;
    }



    return 0;
  }
