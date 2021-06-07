#include<iostream>
#include<vector>
#include<string>
using namespace std;


vector<int> multiply(vector<int> res,int n){
    
    int carry=0;
    
    for(int i=0;i<res.size();i++){
        
        int prod=res[i]*n+carry;
        res[i]=prod%10;
        carry=prod/10;
    }
    
    while(carry){
        res.push_back(carry%10);
        carry=carry/10;
    }
    reverse(res.begin(),res.end());
    return res;
   
}

int main(){

    string s1,s2;
    cin>>s1>>s2;

    bool positive=true;
    if(s1[0]=='-' && s2[0]=='-'){
        positive=true;
        s1.erase(s1.begin());
        s2.erase(s2.begin());
    }   
    else if(s1[0]=='-' || s2[0]=='-'){
        positive=false;
        s1[0]=='-' ? s1.erase(s1.begin()) : s2.erase(s2.begin());
    } 

       vector<int> num1;
       for(int i=s1.size()-1;i>=0;i--){
           num1.push_back(s1[i]-'0');
       }
      
       int k=0;
       vector<int> ans (s1.size()+s2.size(),0);


       for(int i=s2.size()-1;i>=0;i--){
           vector<int> res;
           res=multiply(num1,s2[i]-'0');
           for(int z=0;z<k;z++){
               res.push_back(0);
           }
           
            int carry=0;
            
            int lastofans=ans.size()-1;
            
           for(int j=res.size()-1;j>=0;j--){
               int temp=ans[lastofans]+res[j]+carry;
               ans[lastofans]=temp%10;
               carry=temp/10;
               lastofans--;
           }

           if(carry>0){

               ans[lastofans]+=carry;
           }
          k++;
           

       }


    

    string finalans="";
       if(positive==false){
           finalans+="-";
       }
       
       bool first=false;
       for(int i=0;i<ans.size();i++){
           if(ans[i]==0 && first==false){
               continue;
           }
           first=true;
           finalans+=to_string(ans[i]);
       }
       cout<<finalans<<endl;



}