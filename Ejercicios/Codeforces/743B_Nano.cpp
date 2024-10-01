#include<bits/stdc++.h>
using namespace std;

int main(){
  unsigned long long n,k;
  cin>>n>>k;
  if(k%2!=0){
    cout<<1<<endl;
    return 0;
  }


  unsigned long long medio=pow(2,n-2);
  k= k/2;
  int ind=n;
  //cout<<k<<" "<<medio<<endl;
  unsigned long long top=pow(2,n-1)-1;
  unsigned long long low=1;
  while(k!=medio){
    if(k>medio){
      low=medio+1;
      medio=(low+top)/2;
    }
    else if(k<medio){
      top=medio-1;
      medio=(low+top)/2;
    }
    ind--;
  }
  cout<<ind<<endl;



  //cout<<asd[k-1]<<endl;



  return 0;
}
