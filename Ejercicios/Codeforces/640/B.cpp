#include<bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin>>t;
  vector<vector<int> > ans;
  while(t--){
    int n,k;
    cin>>n>>k;
    vector<int> asd;
    if((n-(k-1))%2==1){
      for(int i=0;i<k-1;i++){
        asd.push_back(1);
        n--;
      }
      asd.push_back(n);
    }
    else if(n%2==0 && n>=2*k){
      for(int i=0;i<k-1;i++){
        asd.push_back(2);
        n-=2;
      }
      asd.push_back(n);
    }
    else{
      asd.push_back(-1);
    }
    ans.push_back(asd);
  }
  //cout<<ans.size()<<endl;
  for(int i=0;i<ans.size();i++){
    //cout<<"iteracion: "<<i<<endl;
    //cout<<ans[i][0]<<endl;
    if(ans[i][0]==-1){
      cout<<"NO\n";
      continue;
    }
    else cout<<"YES\n";
    for(int j=0;j<ans[i].size();j++){
      cout<<ans[i][j];
      if(j<ans[i].size()-1) cout<<" ";
    }
    cout<<endl;
  }



  return 0;
}
