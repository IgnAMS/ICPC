#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  map<char,int> mapa;
  char arr[2*n-2];
  char a,b;
  int cont=0;
  for(int i=0;i<2*n-2;i+=2){
    cin>>arr[i];
    cin>>arr[i+1];
    if(!mapa.count(arr[i])){
      mapa.insert(pair<char,int>(arr[i],1));
    }
    else mapa[arr[i]]++;

    if(!mapa.count(arr[i+1]-'A'+'a')){
      cont++;
    }
    else{
      if(mapa[arr[i+1]-'A'+'a']<=0) cont++;
      else mapa[arr[i+1]-'A'+'a']--;
    }
  }
  cout<<cont<<endl;

  return 0;
}
