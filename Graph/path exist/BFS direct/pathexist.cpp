#include<iostream>
#include<vector>
using namespace std;



bool issafe(int i,int j,vector<vector<int> > adj,int n){
    if(i<0 || i>=n || j<0 || j>=n || adj[i][j]==0){
        return false;
    }
    return true;
    
    
}

bool is_possible(vector <vector <int> > &adj, int n) {
    int si,sj,di,dj;
    vector<pair<int,int> > queue;
    vector<vector<bool> > visited(n,vector<bool> (n,false));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(adj[i][j]==1){
                si=i;
                sj=j;
            }
            if(adj[i][j]==2){
                di=i;
                dj=j;
            }
        }
    }
    
    queue.push_back(make_pair(si,sj));
    visited[si][sj]=true;
    
    
    while(queue.size()){
        pair<int,int> curr=queue[0];
        queue.erase(queue.begin());
        int i=curr.first;
        int j=curr.second;
        if(i==di && j==dj){
            return true;
        }
        
        if( issafe(i-1,j,adj,n) && visited[i-1][j]==false){
            queue.push_back(make_pair(i-1,j));
            visited[i-1][j]=true;
        }
        if(issafe(i,j+1,adj,n) && visited[i][j+1]==false){
            queue.push_back(make_pair(i,j+1));
            visited[i][j+1]=true;
        }
        if(issafe(i+1,j,adj,n) && visited[i+1][j]==false){
            queue.push_back(make_pair(i+1,j));
            visited[i+1][j]=true;
        }
        if(issafe(i,j-1,adj,n) && visited[i][j-1]==false){
            queue.push_back(make_pair(i,j-1));
            visited[i][j-1]=true;
        }
        
    }
    
    return false;

   
    
    
    
    
}


int main(){

    int n;
    cin>>n;
vector<vector<int> > adj(n,vector<int> (n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int temp;
            cin>>temp;
            adj[i][j]=temp;


        }
    }



    if(is_possible(adj,n)){
        cout<<"Path exist"<<endl;
    }
    else{
        cout<<"Path doesnt exist"<<endl;
    }
}