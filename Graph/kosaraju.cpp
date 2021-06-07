#include<iostream>
#include<vector>
using namespace std;




void dfs(vector<int> adj[],vector<bool> &visited,int v,int s,vector<int> &order){
    
    
    visited[s]=true;
    for(int i:adj[s]){
        if(visited[i]==false){
            dfs(adj,visited,v,i,order);
        }
    }
    order.push_back(s);
    
}


void connected(vector<int> adj[],vector<bool> &visited2,int v,int s){
    visited2[s]=true;
    
    for(int i:adj[s]){
        if(visited2[i]==false){
            connected(adj,visited2,v,i);
        }
    }
}

int kosaraju(int V, vector<int> adj[])
{
    // Your code here
    vector<bool> visited(V,false);
    vector<int> order;

    for(int i=0;i<V;i++){
        if(visited[i]==false){
                dfs(adj,visited,V,i,order);
        }
    }
    

cout<<"--------order--------"<<endl;
    for(int i:order){
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<"---------order-------"<<endl;

   
    
    vector<bool> visited2(V,false);
    
    vector<int> adj2[V];
    
    for(int i=0;i<V;i++){
        for(int j:adj[i]){
            
            adj2[j].push_back(i);
        }
    }
    
    
    int count=0;
    reverse(order.begin(),order.end());
    for(int i:order){
        if(visited2[i]==false){
            count++;
            connected(adj2,visited2,V,i);
            
        }
        
    }
    
    
    
    
    return count;
}

int main(){


    int n;
    cin>>n;
    int e;
    cin>>e;
    vector<int> adj[n];
    for(int i=0;i<e;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        
    }

    cout<<kosaraju(n,adj)<<endl;
}