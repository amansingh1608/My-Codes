#include<iostream>
#include<vector>
using namespace std;
struct node{
    int v;
    int w;
};


node findmin(vector<vector<node> > adj, vector<int> dist,vector<bool> visited){
    node answer;

    int miniv;
    int miniw=INT_MAX;

    for(int i=0;i<dist.size();i++){
        if(miniw>dist[i] && visited[i]==false){
            miniw=dist[i];
            miniv=i;
        }

    }
    answer.v=miniv;
    answer.w=miniw;

    return answer;


}

void dijkstra(vector<vector<node> > adj,int s){

vector<bool> visited(adj.size(),false);
vector<int> dist(adj.size(),INT_MAX);
dist[s]=0;

for(int i=0;i<adj.size();i++){

    node curr;
    curr=findmin(adj,dist,visited);
    visited[curr.v]=true;
    for(auto i: adj[curr.v]){
        if(visited[i.v]==false){
            dist[i.v]=min(dist[i.v],dist[curr.v]+i.w);
        }

        
    }

}
int count=0;
for(int i:dist){
    cout<<s<<"-->"<<count<<": "<<i<<endl;
    count++;
}



}


int main(){

    int n;
    cin>>n;
    int e;
    cin>>e;
    vector<vector<node> > adj(n);

    for(int i=0;i<e;i++){
        int a,b,c;
        cin>>a>>b>>c;
        node temp;
        temp.v=b;
        temp.w=c;
        
        adj[a].push_back(temp);
        temp.v=a;
        adj[b].push_back(temp);
    }

    dijkstra(adj,0);




}