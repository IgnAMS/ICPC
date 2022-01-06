#include<bits/stdc++.h>
using namespace std;
int main(){
  int t,n;
  int cont=0;
  cin>>t;
  while(t--){
    cont++;
    cin>>n;
    vector<int> asd;
    int h;
    for(int i=0;i<n;i++){
      cin>>h;
      asd.push_back(h);
    }
    sort(asd.begin(),asd.end());
    int ind=n/2;
    cout<<"Case "<<cont<<": "<<asd[ind]<<endl;

  }

  return 0;
}
