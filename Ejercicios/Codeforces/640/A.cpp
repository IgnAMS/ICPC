#include<bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin>>t;
  vector<vector<string> > ans;
  //cout<<t<<endl;
  while(t--){
    vector<string> caso;
    string linea;
    cin>>linea;
    //cout<<linea<<" "<<linea.length()<<endl;
    string aux="";
    for(int i=0;i<linea.length();i++){
      if(linea[i]!='0'){
        aux+=linea[i];
        for(int j=0;j<linea.length()-i-1;j++){
          aux+='0';
        }
        caso.push_back(aux);
        aux="";
      }
    }
    ans.push_back(caso);
  }
  for(int i=0;i<ans.size();i++){
    cout<<ans[i].size()<<endl;
    for(int j=0;j<ans[i].size();j++){
      cout<<ans[i][j]<<" ";
    }
    cout<<endl;
  }


  return 0;
}
