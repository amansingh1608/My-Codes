#include<iostream>
#include<vector>

using namespace std;

struct edge{
    int s;
    int d;
    int w;

};

void bellman(vector<edge> edges,int v){
    vector<int> dist(v,INT_MAX);

    dist[0]=0;

    for(int i=0;i<v-1;i++){

        for(auto j:edges){
            if(dist[j.s]<INT_MAX){

                if(dist[j.d]>dist[j.s]+j.w){
                    dist[j.d]=dist[j.s]+j.w;
                }

            }


        }


    }
int count=0;
    for(int i:dist){
        cout<<0<<"-->"<<count<<": "<<i<<endl;
        count++;
    }





}


int main(){
    int v;
    cin>>v;

    int e;
    cin>>e;

vector<edge> edges(e);

    for(int i=0;i<e;i++){
        int a,b,c;
        cin>>a>>b>>c;
        edge temp;
        temp.s=a;
        temp.d=b;
        temp.w=c;
        edges.push_back(temp);

    }
    bellman(edges,v);

}


