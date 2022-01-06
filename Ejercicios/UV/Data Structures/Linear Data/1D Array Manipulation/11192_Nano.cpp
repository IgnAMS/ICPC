#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  while(cin>>n){
    if(n==0) break;

    string linea;
    cin>>linea;
    int ind=0;
    int help=linea.length()/n;
    vector<string> ans;
    for(int j=0;j<n;j++){
      string aux="";
      for(int i=ind+help-1;i>=ind;i--){
        aux+=linea[i];
      }
      ans.push_back(aux);
      ind+=help;
    }
    for(int i=0;i<n;i++){
      cout<<ans[i];
    }
    cout<<endl;
  }

  return 0;
}
