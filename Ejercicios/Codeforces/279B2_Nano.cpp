#include<bits/stdc++.h>
using namespace std;

int main(){

  int n,t;
  cin>>n>>t;
  int tiemp[n];

  for(int i=0;i<n;i++){
    cin>>tiemp[i];
  }
  int maxi=0;
  for(int i=0;i<n;i++){
    int sum=0;
    int ind=i-1;
    for(int j=i;j<n;j++){
      sum+=tiemp[j];
      if(sum>t){
        j--;
        break;
      }
      ind=j;
    }
    maxi=max(maxi,ind-i+1);
  }

  cout<<maxi<<endl;



  return 0;
}
