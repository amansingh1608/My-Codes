#include<iostream>
#include<vector>
using namespace std;

void addedge(vector<vector<int> > &adj,int u,int v){

    adj[u].push_back(v);
    adj[v].push_back(u);
}

void bfs(vector<vector<int> > adj,vector <bool> &visited,int s){
    vector<int> queue;
    queue.push_back(s);
    visited[s]=true;

    while(queue.size()){
        int curr=queue[0];
        
        for(int i:adj[curr]){
            if(visited[i]==false){
                queue.push_back(i);
                visited[i]=true;
            }
            
        }
        cout<<curr<<" ";
       
        queue.erase(queue.begin());

    } 

}

void dfs(vector<vector<int> >adj , vector<bool> &visited,int s){

cout<<s<<" ";
visited[s]=true;

for(int i:adj[s]){
    if(visited[i]==false){
        dfs(adj,visited,i);
    }
    
}


}




/////////////////////////// Cycle detection in undirected ///////////////////////////////////////
bool hascycle(vector<int> adj[],int v,int s,int parent,vector<bool> &visited){                 
    visited[s]=true;                                                                                                                                                                     //
    for(int i:adj[s]){                                                                         
        if(visited[i]==true && i!=parent){                                                     
            return true;                                                                        
        }
        if(visited[i]==false){                                                  
            
            if( hascycle(adj,v,i,s,visited)) {  
                return true;                    
            }                                                                                   
    }                                                                                    
}                                                                                               
 return false;
    
}

bool isCyclic(vector<int> adj[], int V)
{
    
  vector<bool> visited(V,false);
   
  
          for(int i=0;i<V;i++){
              if(visited[i]==false){
                  if(hascycle(adj,V,i,-1,visited)){
                      return true;
                  }
              }
              if(visited[i]==true){
                  continue; 
              }
          }
          
          return false;
           
}
/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////// Cycle detection in a directed graph/////////////////////

bool hascycle(vector<vector<int> > adj, int s,vector<bool> &visited,vector<bool> &stack){
    visited[s]=true;
    stack[s]=true;
    for(int i:adj[s]){
        if(visited[i]==true && stack[i]==true){
            return true;
        }
        if(visited[i]==false){
            if(hascycle(adj,i,visited,stack)){
                return true;
            }
        }
    }
    stack[s]=false;
    return false;

}
bool iscyclic(vector<vector<int> > adj){
    vector<bool> visited(adj.size(),false);
    vector<bool> stack(adj.size(),false);

    for(int i=0;i<adj.size();i++){
        if(visited[i]==false){
            if(hascycle(adj,i,visited,stack)){
                return true;
            }

        }
    }
    return false;
}


////////////////////////////////////////////////////////////////////////////////////


/////////////////////////// Topological sort using dfs /////////////////////////////
void topo(int s,vector<vector<int> > adj,vector<bool> &visited,vector<int> &stack){

    visited[s]=true;
    for(int i: adj[s]){
        if(visited[i]==false){
             topo(i,adj,visited,stack);
        }
       
    }

    stack.push_back(s); 
}

void topological(vector<vector<int> > adj){
    vector<bool> visited(adj.size(),false);
    vector<int> stack;
    for(int i=0;i<adj.size();i++){
        if(visited[i]==false){
            topo(i,adj,visited,stack);
        }
    }

    for(int i=stack.size()-1;i>=0;i--){
        cout<<stack[i]<<" ";
    }
    cout<<endl;
}
//////////////////////////////////////////////////////////////////////////


/////// Find the indegree ///////////////////////////////////////////////
vector<int> indegree(vector<vector<int> > adj){
    vector<int> ind(adj.size(),0);

    for(int i=0;i<adj.size();i++){
        for(int j:adj[i]){
            ind[j]++;            
        }
    }

    // print indegree of each vertex///
    //int degree=0;

    // for(int i:indegree){
    //     cout<<degree<<" "<<i<<endl;
    //     degree++;
    // }
    return ind;
}
////////////////////////////////////////////////////////////////////////


/////////// Kahn's algorith  for topological sorting ////////////////////

void kahnutil(vector<vector<int> > adj,vector<bool> &visited,int s){

vector<int> ind=indegree(adj);

vector<int> queue;
for(int i=0;i<ind.size();i++){
    if(ind[i]==0){
        if(visited[i]==false){
            queue.push_back(i);
            visited[i]=true;
        }
        
    }
}
while(queue.size()){

    int temp=queue[0];
    cout<<temp<<" ";
    queue.erase(queue.begin());
    for(int i:adj[temp]){
        ind[i]--;
    }

    for(int i=0;i<ind.size();i++){
        if(visited[i]==false){
            if(ind[i]==0){
                queue.push_back(i);
                visited[i]=true;
            }
            
            
        }
    }


}

}

void kahn(vector<vector<int> > adj){
    vector<bool> visited (adj.size(),false);

    for(int i=0;i<adj.size();i++){
        if(visited[i]==false){
            kahnutil(adj,visited,i);
        }
    }
}


/////////////////////////////////////////////////////////////////////////


///////////////// BFS for shortest path //////////////////////////////////

void shortestpath(vector<vector<int> > adj,int s){

vector<int> visited(adj.size(),false);
vector<int> dist(adj.size(),0);

vector<int> queue;
queue.push_back(s);
visited[s]=true;
while(queue.size()){

    int temp=queue[0];
    queue.erase(queue.begin());
    for(int i:adj[temp]){
        if(visited[i]==false){
             queue.push_back(i);
             visited[i]=true;
             dist[i]=dist[temp]+1;

        }
        
    }



}

int count=0;
for(int i:dist){
    cout<<s<<"---> "<<count<<": "<<i<<endl;
    count++;
}



}


//////////////////////////////////////////////////////////////////////////

int main(){

    int n;
    cin>>n;
    vector<vector<int> > adj(n);

    int e;
    cin>>e;
    for(int i=0;i<e;i++){
        int u,v;
        cin>>u>>v;
        addedge(adj,u,v);

    }
///////// To print out the adjacency list /////////

    // for(int i=0;i<n;i++){
    //     cout<<i<<" ";
    //     for(int j=0;j<adj[i].size();j++){
    //         cout<<adj[i][j]<<" ";
            
    //     }
    //     cout<<endl;
    // }

///////////////////////////////////////////////////

//////////// For BFS /////////////////////////////
//vector<bool> visited(n,false);

// for(int i=0;i<n;i++){
//     if(visited[i]==false){
//         bfs(adj,visited,i);
//     }
// }
//////////////////////////////////////////////////


///////////////  For DFS /////////////////////////

// for(int i=0;i<n;i++){
//     if(visited[i]==false){
//         dfs(adj,visited,i);
//         cout<<endl;
//     }
// }
//////////////////////////////////////////////////

///////////// cycle detection in directed graph/////

// if(iscyclic(adj)){
//     cout<<"contains cyle"<<endl;
// }
// else{
//     cout<<"No, cycle does not exist"<<endl;
// }

///////////////////////////////////////////////////

//////////// For topological sort using dfs////////

 //topological(adj);

///////////////////////////////////////////////////


/////////// Indegree ///////

    //indegree(adj);
///////////////////////////

/////// Kahn algorithm //////

    //kahn(adj);
/////////////////////////////

///// shortest path usng bfs ///
    shortestpath(adj,0);
////////////////////////////////


}