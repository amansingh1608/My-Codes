#include<iostream>
#include<vector>
#include<queue>
using namespace std;

//  vector<int> findmin(vector<vector<bool> > visited,vector<vector<int> > dist,int n){
//      int minii,minij;
//      int miniw=INT_MAX;

//      for(int i=0;i<n;i++){
//          for(int j=0;j<n;j++){
//              if(visited[i][j]==false && miniw>dist[i][j]){
//                  miniw=dist[i][j];
//                  minii=i;
//                  minij=j;                
//              }
//          }       

//      }
//      vector<int> ans;
//      ans.push_back(minii);
//      ans.push_back(minij);
//      ans.push_back(miniw);
//      return ans;

// }


int dij(vector<vector<int> > adj,int n){

    priority_queue< pair<int, pair<int,int>  >, vector< pair<int, pair<int,int>  > >, greater< pair<int, pair<int,int>  > > > pq;
    vector <vector<bool> > visited(n,vector<bool>(n,false));
    vector<vector<int> > dist(n,vector<int> (n,INT_MAX));
    pq.push( make_pair(adj[0][0],make_pair(0,0)) );
    dist[0][0]=adj[0][0];

    for(int i=0;i<n*n;i++){

        int minii,minij,miniw;
        pair<int, pair<int,int>  > curr=pq.top();
        pq.pop();
        minii=curr.second.first;
        minij=curr.second.second;
        miniw=curr.first;      
        


        visited[minii][minij]=true;

        if( minii-1 >= 0 && minii-1 <= n-1 && minij >= 0 && minij<= n-1 && visited[minii-1][minij]==false ){

            if(dist[minii-1][minij]> miniw+adj[minii-1][minij]){
                dist[minii-1][minij]=min (dist[minii-1][minij], miniw + adj[minii-1][minij]);
                pq.push( make_pair(dist[minii-1][minij], make_pair(minii-1,minij)    )         );

            }

            

        }

        if( minii+1 >= 0 && minii+1 <= n-1 && minij >= 0 && minij<= n-1 && visited[minii+1][minij]==false ){

            if(dist[minii+1][minij]> miniw+adj[minii+1][minij]){
                dist[minii+1][minij]=min (dist[minii+1][minij], miniw + adj[minii+1][minij]);
                pq.push( make_pair(dist[minii+1][minij], make_pair(minii+1,minij)    )         );

            }

            

        }

        if( minii >= 0 && minii <= n-1 && minij-1 >= 0 && minij-1<= n-1 && visited[minii][minij-1]==false ){

            if(dist[minii][minij-1]> miniw+adj[minii][minij-1]){
                dist[minii][minij-1]=min (dist[minii][minij-1], miniw + adj[minii][minij-1]);
                pq.push( make_pair(dist[minii][minij-1], make_pair(minii,minij-1)    )         );

            }

           

        }

        if( minii >= 0 && minii <= n-1 && minij+1 > 0 && minij+1<= n-1 && visited[minii][minij+1]==false ){

            if(dist[minii][minij+1]> miniw+adj[minii][minij+1]){
                dist[minii][minij+1]=min (dist[minii][minij+1], miniw + adj[minii][minij+1]);
                pq.push( make_pair(dist[minii][minij+1], make_pair(minii,minij+1)    )         );

            }

            
        }      



    }


    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         cout<<dist[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    return dist[n-1][n-1];


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

    cout<<dij(adj,n)<<endl;

}