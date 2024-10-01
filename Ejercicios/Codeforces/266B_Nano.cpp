#include<bits/stdc++.h>
using namespace std;
int main(){
  int n, t;
  cin>>n>>t;
  char asd[n];
  for(int i=0;i<n;i++){
    cin>>asd[i];
  }
  for(int i=0;i<t;i++){
    for(int j=0;j<n;j++){
      if(asd[j]=='B' && asd[j+1]=='G' && j+1<n){
        char aux=asd[j];
        asd[j]=asd[j+1];
        asd[j+1]=aux;
        j++;
      }
    }
  }

  for(int i=0;i<n;i++){
    cout<<asd[i];
  }
  cout<<endl;

  return 0;
}
