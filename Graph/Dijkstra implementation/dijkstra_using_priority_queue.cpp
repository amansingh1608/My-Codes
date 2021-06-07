#include<iostream>
#include<vector>
#include<queue>
using namespace std;


void dijkstra(vector <vector <pair<int,int> > > adj,int s){
    vector<bool> visited(adj.size(),false);
    vector<int> dist(adj.size(),INT_MAX);

    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;

    
    pq.push(make_pair(0,s));
    dist[s]=0;

    for(int i=0;i<adj.size();i++){

        pair<int,int> mini=pq.top();
         pq.pop();
        
        int miniv=mini.second;
        int miniw=mini.first;

        visited[miniv]=true;
       

        for(auto j:adj[miniv]){
            
            pair<int,int> temp=j;
            if(visited[temp.first]==false){
                dist[temp.first]=min(dist[temp.first],dist[miniv]+temp.second);

                pq.push(make_pair(dist[temp.first],temp.first));
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


vector < vector <pair<int,int> > > adj(n);

    for(int i=0;i<e;i++){
        int a,b,c;
        cin>>a>>b>>c;
        adj[a].push_back(make_pair(b,c));
        adj[b].push_back(make_pair(a,c));    
        
   }

   dijkstra(adj,0);

}