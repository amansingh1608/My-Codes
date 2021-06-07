#include<iostream>
#include<vector>

using namespace std;
struct node{
    int tt;
    int x,y;
};
bool issafe(int i,int j,int n,int m){
    if(i>n-1 || j>m-1 || i<0 || j<0){
        return false;
    }
    return true;
    
}

int main()
 {
    
    int t;
    cin>>t;
    
    while(t--){
        int n,m;
        cin>>n>>m;
        
        vector<vector<int> > adj;
        for(int i=0;i<n;i++){
            vector<int> xx;
            for(int j=0;j<m;j++){
                int temp;
                cin>>temp;
                xx.push_back(temp);
            }
            adj.push_back(xx);
        }
        
        vector<node> queue;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(adj[i][j]==2){
                    node temp;
                    temp.tt=0;
                    temp.x=i;
                    temp.y=j;
                    queue.push_back(temp);
                }
            }
        }
        
        node curr;
        while(queue.size()){
             curr=queue[0];
            queue.erase(queue.begin());
            
            int i=curr.x;
            int j=curr.y;
            int t=curr.tt;
            
            if(issafe(i-1,j,n,m) && adj[i-1][j]==1){
                adj[i-1][j]=2;
                node temp;
                temp.tt=t+1;
                temp.x=i-1;
                temp.y=j;
                queue.push_back(temp);
            }
            if(issafe(i+1,j,n,m) && adj[i+1][j]==1){
                adj[i+1][j]=2;
                node temp;
                temp.tt=t+1;
                temp.x=i+1;
                temp.y=j;
                queue.push_back(temp);
            }
            if(issafe(i,j-1,n,m) && adj[i][j-1]==1){
                adj[i][j-1]=2;
                node temp;
                temp.tt=t+1;
                temp.x=i;
                temp.y=j-1;
                queue.push_back(temp);
            }
            if(issafe(i,j+1,n,m) && adj[i][j+1]==1){
                adj[i][j+1]=2;
                node temp;
                temp.tt=t+1;
                temp.x=i;
                temp.y=j+1;
                queue.push_back(temp);
            }
        }
        int flag=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(adj[i][j]==1){
                    flag=1;
                    break;
                }
            }
        }
        
        if(flag==0){
           
           cout<<curr.tt<<endl;
        }
        else{
            cout<<"-1"<<endl;
        }
        
        
       
        
        
        
        
    
    
    }
	
}