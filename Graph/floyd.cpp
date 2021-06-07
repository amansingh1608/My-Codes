#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;


void floyd(vector<vector<long> > adj ){

    vector<vector<long> > mat(adj.size(),vector<long> (adj.size()));
    for(int i=0;i<adj.size();i++){
        for(int j=0;j<adj.size();j++){
            mat[i][j]=adj[i][j];
        }
    }

    for(int k=0;k<adj.size();k++){
        
        for(int i=0;i<adj.size();i++){
            for(int j=0;j<adj.size();j++){
                if(i==k || j==k){
                    continue;
                }
                
                    mat[i][j]=min(mat[i][j], (mat[i][k] + mat[k][j]) );
            


            }
        }



    }

    for(int i=0;i<adj.size();i++){
        for(int j=0;j<adj.size();j++){

            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }



}






int main(){


    int n;
    cin>>n;
    vector<vector<long> > adj(n,vector<long>(n,INT_MAX));
    for(int i=0;i<n;i++){
        adj[i][i]=0;
    }

    int e;
    cin>>e;
    for(int i=0;i<e;i++){
        int a,b,c;
        cin>>a>>b>>c;
        adj[a][b]=c;
    }

    floyd(adj);
}