#include<bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin>>t;
  vector<vector<int> > anss;
  while(t--){
    int n1,n2;
    cin>>n1;
    vector<int> pol1(n1+1);
    for(int i=0;i<n1+1;i++){
      cin>>pol1[i];
    }
    //cout<<"termine de ingresar el pol1\n";
    cin>>n2;
    cout<<n2<<endl;
    vector<int> pol2(n2+1);
    for(int i=0;i<n2+1;i++){
      cin>>pol2[i];
    }
    //cout<<"termine de ingresar el pol2\n";
    vector<int> ans(n1+n2+1,0);
    for(int i=0;i<n1+1;i++){
      for(int j=0;j<n2+1;j++){
        //cout<<"en el grado "<<i+j<<" se acaba de sumar "<<pol1[i]*pol2[j]<<endl;
        ans[i+j]+=pol1[i]*pol2[j];
      }
    }
    while(ans[ans.size()-1]==0 && ans.size()>1){
      ans.pop_back();
    }
    cout<<ans.size()-1<<endl;
    for(int j=0;j<ans.size();j++){
      cout<<ans[j];
      if(j<ans.size()-1) cout<<" ";
    }
    cout<<endl;
  }
  return 0;
}
