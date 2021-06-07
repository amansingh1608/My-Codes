#include<iostream>
#include<vector>

using namespace std;

bool issafe(int i,int j,int n,vector<vector<int> > mat){


    if(i<0 || j<0 || i>=n || j>=n || mat[i][j]==0){
        return false;
    }
    return true;
}



bool exist(int s,int d,vector<vector<int> > adj){

    vector<int> queue(adj.size());
    vector<bool> visited(adj.size(),false);

    queue.push_back(s);
    visited[s]=true;
    while(queue.size()){

        int temp=queue[0];
        queue.erase(queue.begin());
        for(int j:adj[temp]){
            if(visited[j]==false){
                 queue.push_back(j);
                 visited[j]=true;
            }
           
            if(j==d){
                return true;
            }
        }


    }
    return false;


}




int main(){

    int n;
    cin>>n;

    vector<vector<int> > mat(n,vector<int> (n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int temp;
            cin>>temp;
            mat[i][j]=temp;

        }
    }



vector<vector<int> > adj(n*n);

int s=-1,d;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int temp=mat[i][j];

            if(temp!=0){

                if(issafe(i-1,j,n,mat)){
                adj[(i*n)+j].push_back((i-1)*n+j);
            }
            if(issafe(i+1,j,n,mat)){

                adj[(i*n)+j].push_back((i+1)*n+j);
            }

            if(issafe(i,j-1,n,mat)){

                adj[(i*n)+j].push_back((i*n)+(j-1));
            }
            if(issafe(i,j+1,n,mat)){

                adj[(i*n)+j].push_back((i*n)+(j+1));
            }

            if(mat[i][j]==1){
                s=(i*n)+j;
            }
            if(mat[i][j]==2){
                d=(i*n)+j;
            }





            }
            

        }
    }
    

   
if(exist(s,d,adj)){
    cout<<" YES PATH EXISTS "<<endl;
}
else{
    cout<<" NO PATH DOES'NT EXISTS "<<endl;
}
    

}