#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,m;
  cin>>n>>m;
  int mat[n][m];
  vector<int> mini(n,1000000000);

  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cin>>mat[i][j];
      mini[i]=min(mini[i],mat[i][j]);
    }
    //cout<<mini[i]<<endl;
  }
  sort(mini.begin(),mini.end());
  cout<<mini[n-1]<<endl;


  return 0;
}
