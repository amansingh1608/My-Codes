#include<iostream>
#include<vector>

using namespace std;

struct node{
    int data;
    node* left;
    node* right;
    node(int x){
        data=x;
        left=NULL;
        right=NULL;
    }
};


node * helper(vector<int> in, vector<int> pre,int ins,int ine,int pres,int pree){
    if(ins>ine || pres>pree){
        return NULL;

    }

    int data=pre[pres];
    node * newnode=new node(data);

    int rootindex=-1;

    for(int i=ins;i<=ine;i++){
        if(in[i]==data){
            rootindex=i;
            break;
        }
    }

    int linS=ins;
    int rpreE=pree;
    int rinE=ine;
    int linE=rootindex-1;
    int rinS=rootindex+1;
    int lpreS=pres+1;
    int lpreE=(linE-linS)+lpreS;
    int rpreS=lpreE+1;
    
   
    newnode->left=helper(in,pre,linS,linE,lpreS,lpreE);
    newnode->right=helper(in,pre,rinS,rinE,rpreS,rpreE);

    return newnode;


}  


node * buildtree(vector<int> in,vector<int> pre,int n){



    return helper(in,pre,0,n-1,0,n-1);
}

int solve(node *root,int &res){
     if (root==NULL) return 0; 
    if (!root->left && !root->right) return root->data; 
  
   
    int ls = solve(root->left, res); 
    int rs = solve(root->right, res); 
  
  
    if (root->left && root->right) 
    { 
        res = max(res, ls + rs + root->data); 
  
       
        return max(ls, rs) + root->data; 
    } 
  
    
    return (!root->left)? rs + root->data: 
                          ls + root->data; 
}

int maxPathSum(node* root)
{ 
      
    int res=INT_MIN;
    solve(root,res);
    return res;
}

int main(){

    int n;
    cin>>n;

    vector<int> in;
    vector<int> pre;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        in.push_back(temp);
    }

    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        pre.push_back(temp);

    }

    node *root=buildtree(in,pre,n);
    cout<<maxPathSum(root)<<endl;



    
}