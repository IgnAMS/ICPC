#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
int main(){
  int t;
  cin>>t;
  vector<int> ans;
  while(t--){
    int n;
    cin>>n;
    int h;
    int cont=0;
    int maxi=0;
    map<int,int> mapa;
    int arr[n];
    for(int i=0;i<n;i++){
      cin>>arr[i];
    }
    for(int i=0;i<n;i++){
      if(!mapa.count(arr[i])){
        mapa.insert(ii(arr[i],i));
        cont++;
      }
      else{
        maxi=max(maxi,(int)mapa.size());
        i=mapa[arr[i]];
        mapa.clear();
      }
      if(i==n-1) maxi=max(maxi,(int)mapa.size());
    }
    ans.push_back(maxi);
  }
  for(int i=0;i<ans.size();i++){
    cout<<ans[i]<<endl;
  }

  return 0;
}
