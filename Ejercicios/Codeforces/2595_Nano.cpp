#include<iostream>
#include<vector>
using namespace std;

int dc[]={-1, 0, 1,1,1,0,-1,-1};
int dr[]={-1,-1,-1,0,1,1, 1, 0};

int main(){
    int t;
    cin>>t;
    while(t--){
        int r,c,p;
        cin>>r>>c>>p;
        char cancha[r][c];
        vector< pair<int,int> > enemigo;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                cin>>cancha[i][j];
                if(cancha[i][j]=='T'){
                    enemigo.push_back(pair<int,int> (i,j));
                }
            }
        }
        int trops[p];
        /*cout<<"enemigo:\n";
        for(int i=0; i<enemigo.size();i++) {
            cout<<enemigo[i].first<<" "<<enemigo[i].second<<endl;
        }
        cout<<endl;
        */
        for(int i=0;i<p;i++){
            int cont=0;
            int x,y;
            cin>>x>>y;
            x--;
            y--;
            for(int j=0;j<8;j++){
                //cout<<"posicion: "<<x+dc[j]<<" "<<y+dr[j]<<endl;
                if(cancha[x+dc[j]][y+dr[j]] == 'T' && x+dc[j]>=0 && x+dc[j]<r && y+dr[j]>=0 && y+dr[j]<c){
                    //cout<<"aaaa "<<x+dc[j]<<" "<<y+dr[j]<<endl;
                    cont++;
                }
            }
            if(cont>=5){
                cout<<"GRRR\n";
            }
            else{
                cout<<"GG IZI\n";
            }
        }
    }

    return 0;
}
