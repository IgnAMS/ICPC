#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  int Arr[n];
  int mini=100000;
  int maxi=0;

  for(int i=0;i<n;i++){
    cin>>Arr[i];
  }
  int dist;
  bool ohyea=false;
  for(int i=1;i<n-1;i++){
    for(int j=1;j<n;j++){
      int comp=0;
      if(ohyea){
        ohyea=false;
        continue;
      }
      if(j==i){
        comp=1;
        ohyea=true;
      }
      maxi=max(maxi,Arr[j+comp]-Arr[j-1]);
      //cout<<Arr[j+comp]-Arr[j-1]<<"  ";
      //cout<<maxi<<endl;
    }
    mini=min(mini,maxi);
    maxi=0;
    //cout<<"mini: "<<mini<<endl;
  }
  cout<<mini<<endl;


  return 0;
}
