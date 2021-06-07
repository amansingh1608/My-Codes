#include<iostream>
#include<vector>
using namespace std;

bool ispalindrome(string s,int i,int j){

    while(i<=j){
        if(s[i]==s[j]){
            i++;
            j--;
            continue;
        }
        else{
            return false;
        }
    }
    return true;
}

int solve(string s,int i,int j,vector<vector<int> > &t){
    if(i>=j){
        return 0;
    }
    if(ispalindrome(s,i,j)){
        return 0;
    }

    if(t[i][j]!=-1){
        return t[i][j];
    }
    else{

        int ans=INT_MAX;
        for(int k=i;k<=j-1;k++){
            int temp=(t[i][k]==-1 ? solve(s,i,k,t) : t[i][k]) + (t[k+1][j]==-1 ? solve(s,k+1,j,t) : t[k+1][j])+1;
             ans=min(ans,temp);
        }   

        return t[i][j]=ans;
    }
    
    

}

int main(){

    string s;
    cin>>s;
    vector<vector<int> > t(s.size()+1,vector<int> (s.size()+1,-1));

    cout<< solve(s,0,s.size()-1,t)<<endl;
}