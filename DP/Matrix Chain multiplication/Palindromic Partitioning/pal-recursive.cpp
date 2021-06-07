#include<iostream>
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

int solve(string s,int i,int j){
    if(i>=j){
        return 0;
    }
    if(ispalindrome(s,i,j)){
        return 0;
    }

    int ans=INT_MAX;
    for(int k=i;k<=j-1;k++){
        int temp=solve(s,i,k)+solve(s,k+1,j)+1;
        ans=min(ans,temp);
    }
    return ans;

}

int main(){

    string s;
    cin>>s;

    cout<< solve(s,0,s.size()-1)<<endl;
}