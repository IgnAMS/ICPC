#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  if(n%2==1) cout<<-1<<endl;
  else{
    int Array[n];
    for(int i=2;i<=n-2;i+=2){
      cout<<i<<" "<<i-1<<" ";
    }
    cout<<n<<" "<<n-1<<endl;
  }

  return 0;
}
