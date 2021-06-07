#include<iostream>
#include<vector>
using namespace std;

void dij(vector<vector<int> > adj,int s){
    vector<bool> visited(adj.size(),false);
    vector<int> dist(adj.size(),INT_MAX);
    dist[0]=0;
    for(int i=0;i<adj.size();i++){
        int mini=INT_MAX;
        int miniv;


        for(int j=0;j<dist.size();j++){
            if(mini>dist[j] && visited[j]==false){
                mini=dist[j];
                miniv=j;
            }
                
        }
        visited[miniv]=true;        
        
        for(int j=0;j<adj.size();j++){
            if(adj[miniv][j]>0 && visited[j]==false){
                dist[j]=min(dist[j],dist[miniv]+adj[miniv][j]);
            }
        }


    }
int count=0;
    for(auto i:dist){

        cout<<s<<"-->"<<count<<": "<<i<<endl;
        count++;
    }



}

int main(){

    int n;
    cin>>n;
    int e;
    cin>>e;
    vector<vector<int> > adj(n,vector<int> (n,0));
    for(int i=0;i<e;i++){
        int a,b,c;
        cin>>a>>b>>c;
        adj[a][b]=c;
        adj[b][a]=c;
    }

    dij(adj,0);

    





}