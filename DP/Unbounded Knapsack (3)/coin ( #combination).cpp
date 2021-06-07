#include<iostream>
#include<vector>

using namespace std;

int knapsack(vector<int> coins,int w,int n){
    vector<vector<int> > t(n+1,vector<int> (w+1));
    for(int i=0;i<=n;i++){
        for(int j=0;j<=w;j++){
            if(i==0){
                t[i][j]=0;
            }
            if(j==0){
                t[i][j]=1;
            }
        }
    }


    for(int i=1;i<=n;i++){
        for(int j=1;j<=w;j++){

            if(coins[i-1]<=j){
                t[i][j]=t[i][j-coins[i-1]]+t[i-1][j];
            }
            else{
                t[i][j]=t[i-1][j];
            }
        }

    }
    return t[n][w];

}
int main(){
    int n;
    cin>>n;
    vector<int> coins;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        coins.push_back(temp);

    }

    int sum;
    cin>>sum;
    cout<<knapsack(coins,sum,n)<<endl;


}