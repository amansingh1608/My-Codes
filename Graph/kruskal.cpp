#include<iostream>
#include<vector>
using namespace std;
struct edge{
    int s;
    int d;
    int w;

};

bool comp(edge a,edge b){

    if(a.w==b.w){
        return a.s<b.s;
    }
    return a.w<b.w;
}

bool hascycle(vector<vector<int> > adj,vector<bool> &visited,int parent,int s){
    visited[s]=true;
    for(int i:adj[s]){
        if(visited[i]==true && i!=parent){
            return true;
        }
        if(visited[i]==false && hascycle(adj,visited,s,i)){
            return true;
        }

    }
    return false;

}


bool iscyclic(vector<vector<int> > adj,int s){
    vector<bool> visited (adj.size(),false);

    if(hascycle(adj,visited,-1,s)){
        return true;
    }
    else{
        return false;
    }



}

int kruskal(vector<edge> edges,int v){

    sort(edges.begin(),edges.end(),comp);
    vector<vector<int> > adj(v);
    vector<int> weights;

    for(auto i:edges){
    adj[i.s].push_back(i.d);
    adj[i.d].push_back(i.s);    
    if(iscyclic(adj,i.s)==false){
        weights.push_back(i.w);
        continue;
    } 
    else{
        adj[i.s].pop_back();
        adj[i.d].pop_back();
        edges.erase(edges.begin());
    }   


    }

    int sum=0;
    for(int i:weights){
        sum+=i;

    }

    return sum;


}



int main(){

    int n;
    cin>>n;
    int e;
    cin>>e;
    vector<edge> edges;
   
    for(int i=0;i<e;i++){
        int a,b,c;
        cin>>a>>b>>c;
        edge temp;
        temp.s=a;
        temp.d=b;
        temp.w=c;
        edges.push_back(temp);

    }

    cout<< kruskal(edges,n)<<endl;
}