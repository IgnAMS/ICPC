#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,t;
  cin>>n>>t;
  int tiemp[n];
  int asd=0;
  int cont=0;
  bool xd=true;
  for(int i=0;i<n;i++){
    cin>>tiemp[i];
    asd+=tiemp[i];
    if(asd>t && xd){
      cont=i;
      xd=false;
    }
    else if(asd<=t){
      cont=i+1;
    }
  }
  if(cont==n){
    //cout<<"no entre aca\n";
    cout<<n<<endl;
    return 0;
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
