#include<bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin>>t;
  vector<int> ans;
  while(t--){
    int a,b,c,r;
    cin>>a>>b>>c>>r;
    if(b<a){
      int aux=b;
      b=a;
      a=aux;
    }
    int mini=c-r;
    int maxi=c+r;
    int cont=0;
    if((a<mini && mini<b)){
      cont+=mini-a;
    }
    if(a<maxi && maxi<b){
      cont+= b-maxi;
    }
    //cout<<mini<<" "<<maxi<<endl;
    if(((mini<=a && mini<=b) || (maxi>=b && maxi>=a)) && !((mini<=a && b<=maxi)) && !((a<mini && mini<b) || (a<maxi && maxi<b))){
      cont+=b-a;
      //cout<<"entre"<<endl;
    }
    ans.push_back(cont);
  }
  for(int i=0;i<ans.size();i++) cout<<ans[i]<<endl;


  return 0;
}
