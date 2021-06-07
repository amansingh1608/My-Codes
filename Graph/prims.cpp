#include<iostream>
#include<vector>
using namespace std;

struct edge{
    int v;
    int w;
};

edge findmin(vector<bool> visited,vector<int> weight){
    int miniw=INT_MAX;
    int miniv;

    for(int i=0;i<weight.size();i++){
        if(miniw>weight[i] && visited[i]==false){
            miniw=weight[i];
            miniv=i;

        }

    }
    edge temp;
    temp.v=miniv;
    temp.w=miniw;
    return temp;
}

int prims(vector<vector<edge> > adj){

    vector<bool> visited(adj.size(),false);
    vector<int> parent(adj.size(),-1);
    vector<int> weight(adj.size(),INT_MAX);

    weight[0]=0;
    for(int i=0;i<adj.size();i++){
        edge curr=findmin(visited,weight);

        visited[curr.v]=true;
        for(auto j:adj[curr.v]){

            if(visited[j.v]==false && weight[j.v]>j.w){
                weight[j.v]=j.w;
                parent[j.v]=curr.v;
                
            }

        }
    }


for(int i=1;i<adj.size();i++){
    cout<<parent[i]<<"--"<<i<<": "<<weight[i]<<endl;
}
cout<<endl;

int sum=0;
    for(int i:weight){
        sum+=i;

    }
    return sum;
}

int main(){


    int n;
    cin>>n;
    int e;
    cin>>e;
    vector<vector<edge> > adj(n);
    for(int i=0;i<e;i++){
        int a,b,c;
        cin>>a>>b>>c;
        edge temp;
        temp.v=b;
        temp.w=c;
        adj[a].push_back(temp);
        temp.v=a;
        adj[b].push_back(temp);
    }

    cout<<prims(adj)<<endl;
}