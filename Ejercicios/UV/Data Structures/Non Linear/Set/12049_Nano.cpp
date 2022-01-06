#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
int main(){
  int t;
  cin>>t;
  vector<int> ans;
  while(t--){
    int n,m;
    cin>>n>>m;
    int arr1[n];
    map<int,int> cont1;
    map<int,int> cont2;
    int arr2[m];

    for(int i=0;i<n;i++){
      cin>>arr1[i];
      if(!cont1.count(arr1[i])){
        cont1.insert(ii(arr1[i],1));
      }
      else{
        cont1[arr1[i]]++;
      }
    }
    for(int j=0;j<m;j++){
      cin>>arr2[j];
      if(!cont2.count(arr2[j])){
        cont2.insert(ii(arr2[j],1));
      }
      else{
        cont2[arr2[j]]++;
      }
    }
    map<int,int>::iterator it;
    int cont=0;
    int ind;
    //cout<<"sigo vivo\n";
    for(it=cont1.begin();it!=cont1.end();++it){
      ind=it->first;
      //cout<<ind<<endl;
      if(!cont2.count(ind)){
        cont+=cont1[ind];
        //cont1.erase(ind);
      }
      else{
        while(cont1[ind]!=cont2[ind]){
          if(cont1[ind]>cont2[ind]) cont1[ind]--;
          else if(cont1[ind]<cont2[ind]) cont2[ind]--;
          cont++;
        }
      }
    }
    //cout<<"sobrevivi a la primera pasada\n";

    for(it=cont2.begin();it!=cont2.end();++it){
      ind=it->first;
      if(!cont1.count(ind)){
        cont+=cont2[ind];
        //cont2.erase(ind);
      }
      else{
        while(cont1[ind]!=cont2[ind]){
          if(cont1[ind]>cont2[ind]) cont1[ind]--;
          else if(cont1[ind]<cont2[ind]) cont2[ind]--;
          cont++;
        }
      }
    }
    ans.push_back(cont);

  }
  for(int i=0;i<ans.size();i++){
    cout<<ans[i]<<endl;
  }



  return 0;
}
