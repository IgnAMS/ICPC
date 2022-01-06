#include<bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    int h;
    vector<bool> asd(n,false);
    cin>>h;
    int arr[h];
    int cont=0;
    //cout<<"que hago? "<<n<<endl;
    for(int i=0;i<h;i++){
      cin>>arr[i];
      for(int j=arr[i];j<=n;j+=arr[i]){
        if(j%7== 6 || j%7==0) continue;
        if(!asd[j-1]){
          asd[j-1]=true;
          cont++;
        }
      }
    }
    cout<<cont<<endl;



  }



  return 0;
}
