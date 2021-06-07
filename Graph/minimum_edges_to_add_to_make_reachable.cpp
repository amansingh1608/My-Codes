#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>
using namespace std;

void dfs(int s,vector<vector<int> > adj,vector<bool> &visited,vector<bool > & good){
    
    visited[s]=true;
    good[s]=true;
    //good.push_back(s);
    for(int i:adj[s]){
        if(visited[i]==false){
            dfs(i,adj,visited,good);
        }
        
    }
    
    
}

void dfs2(int s,vector<bool> &visited2,vector<bool> visited,vector<vector<int> > adj,int &count){
    
    visited2[s]=true;
    if(visited[s]==false){

        count++;
    }
    for(int i:adj[s]){
        if(visited2[i]==false){
            dfs2(i,visited2,visited,adj,count);
        }
        
    }
    
    
    
    
}
void dfs3(int s,vector<bool> &isgood,vector<vector<int> > adj){
    
    isgood[s]=true;
    for(int i:adj[s]){
        if(isgood[i]==false){
            dfs3(i,isgood,adj);
        }
    }
}

bool comp(pair<int,int> a,pair<int,int> b){
    if(a.first==b.first){
        return a.second<b.second;
    }
	return a.first>b.first;
}

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n,m,c;
        cin>>n>>m>>c;
        vector<vector<int> > adj(n);
        for(int i=0;i<m;i++){
            int u,v;
            cin>>u>>v;
            
            adj[u-1].push_back(v-1);
        }
        
        vector<bool> visited(n,false);
        vector<bool> good(n,false);
    
        vector<int>bad;
        
        
       dfs(c-1,adj,visited,good);

        vector<pair<int,int> > countv;

        for(int i=0;i<n;i++){
            if(good[i]==false){
                vector<bool> visited2(n,false);
                 int count=0;
                 dfs2(i,visited2,visited,adj,count);
                countv.push_back(make_pair(count,i));  
            }
        }
                
        
        
        
        sort(countv.begin(),countv.end(),comp);
        vector<bool> isgood(n,false);
        int ans=0;
        
        for(auto i:countv){
            if(isgood[i.second]==false){
                dfs3(i.second,isgood,adj);
                ans++;
            }
           
            
        }
        cout<<ans<<endl;
        
        
        
        
    }
    
}