#include<iostream>
#include<vector>
using namespace std;

int knapsack(vector<int> wt,vector<int> val,int n,int len){

    vector<vector<int> > t(n+1,vector<int>(len+1));

    for(int i=0;i<=n;i++){
        for(int j=0;j<=len;j++){
            if(i==0 || j==0){
                t[i][j]=0;
            }
        }
    }


    for(int i=1;i<=n;i++){
        for(int j=1;j<=len;j++){
            if(wt[i-1]<=j){

                t[i][j]=max(val[i-1]+t[i][j-wt[i-1]],t[i-1][j]);
            }
            else{
                t[i][j]=t[i-1][j];
            }
        }
    }

    return t[n][len];
}

int main(){
    int n;
    cin>>n;

vector<int> wt;
vector<int> val;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        wt.push_back(temp);
    }

    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        val.push_back(temp);
    }
    int len;
    cin>>len;

    cout<<knapsack(wt,val,n,len)<<endl;



}