#include<bits/stdc++.h>
using namespace std;

vector<int> conts(26,0);
void getcont(deque<char> a){
  conts.assign(26,0);
  for(int i=0;i<a.size();i++){
    conts[a[i]-'a']++;
  }
}


int main(){
  int t;
  cin>>t;
  string linea;
  string linea2;
  deque<char> asd;

  while(t--){
    cin>>linea>>linea2;
    vector<int> conts2(26,0);
    asd.clear();

    for(int i=0;i<linea.size();i++){
      conts2[linea[i]-'a']++;
      asd.push_back(linea2[i]);
    }
    getcont(asd);
    bool meh=false;
    bool same=true;
    for(int j=0;j<26;j++){
      if(conts[j]!=conts2[j]) same=false;
      //cout<<conts[j]<<" "<<conts2[j]<<endl;
    }
    if(same){
      meh=true;
    }
    //cout<<endl;

    for(int i=linea.size();i<linea2.size() && !meh;i++){
      asd.push_back(linea2[i]);
      asd.pop_front();
      getcont(asd);
      same=true;
      for(int j=0;j<26;j++){
        if(conts[j]!=conts2[j]) same=false;
        //cout<<conts[j]<<" "<<conts2[j]<<endl;
      }
      //cout<<endl;
      if(same){
        meh=true;
      }

    }
    if(meh) cout<<"YES\n";
    else cout<<"NO\n";

  }



  return  0;
}
