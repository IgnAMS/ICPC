#include <bits/stdc++.h>
using namespace std;

const int MAX_CHAR = 26;



int main() {
  string algo;
  getline(cin,algo);
  vector<char> uno;
  vector<char> dos;
  bool primer=true;

  for(int i=0;i<algo.length();i++){
    if(algo[i]==','){
      primer = false;
      continue;
    }
    if(primer){
      uno.push_back(algo[i]);
    }
    else{
      dos.push_back(algo[i]);
    }


  }
  for(int i=0;i<uno.size();i++){
    cout<<uno[i];
  }
  cout<<endl;
  for(int i=0;i<dos.size();i++){
    cout<<dos[i];
  }
  cout<<endl;

	return 0;
}



