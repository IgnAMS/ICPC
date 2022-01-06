#include<bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin>>t;
  int x,y,z;
  int cont=0;
  while(t--){
    cont++;
    cin>>x>>y>>z;
    int ans;
    vector<int> asd;
    asd.push_back(x);
    asd.push_back(y);
    asd.push_back(z);
    sort(asd.begin(),asd.end());
    printf("Case %d: %d\n",cont,asd[1]);

  }



  return 0;
}
