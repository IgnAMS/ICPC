#include<bits/stdc++.h>
using namespace std;
int main(){
  vector<int> mults;
  mults.push_back(1);
  mults.push_back(2);
  mults.push_back(4);
  mults.push_back(8);
  mults.push_back(16);
  mults.push_back(32);
  mults.push_back(64);
  mults.push_back(128);
  mults.push_back(256);
  mults.push_back(512);
  mults.push_back(1024);
  mults.push_back(2048);
  mults.push_back(4096);
  mults.push_back(8192);
  mults.push_back(16384);
  mults.push_back(32768);
  mults.push_back(65536);
  mults.push_back(131072);
  mults.push_back(262144);
  mults.push_back(524288);
  mults.push_back(1048576);
  mults.push_back(2097152);
  mults.push_back(4194304);
  mults.push_back(8388608);
  mults.push_back(16777216);
  mults.push_back(33554432);
  mults.push_back(67108864);
  mults.push_back(134217728);
  mults.push_back(268435456);
  mults.push_back(536870912);
  int a;
  cin>>a;


  int ind=mults.size()-1;
  deque<char> linea;
  bool primer=true;
  while(a!=0){
    //cout<<"a vale: "<<a<<", mulst[ind]: "<<mults[ind]<<endl;
    if(a<mults[ind]){
      if(!primer){
        linea.push_back('0');
      }
    }
    else{
      primer=false;
      linea.push_back('1');
      a-=mults[ind];
      if(a==0) break;
    }

    ind--;
  }
  for(int i=0;i<ind;i++){
    linea.push_back('0');
  }

  reverse(linea.begin(),linea.end());

  while(linea.front()=='0') linea.pop_front();

  int ans=0;
  for(int i=0;i<linea.size();i++){
    int mult=1;
    for(int j=0;j<linea.size()-i-1 && linea[i]=='1';j++){
      mult*=2;
    }
    if(linea[i]=='0') mult=0;
    //cout<<linea[i]<<" "<<mult<<endl;
    ans+=mult;
  }
  cout<<ans<<endl;

  return 0;
}
