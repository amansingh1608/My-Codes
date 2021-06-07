#include<iostream>
#include<vector>
using namespace std;

struct bst{

    int data;
    bst * left;
    bst * right;
};
bst * root=NULL;


bst * create(int data){
    bst * newnode=new bst();
    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;

    return newnode;
}


bst* insert(bst * root,int data){
    if(root==NULL){
        root=create(data);
    }
    if(data<root->data){

        root->left=insert(root->left,data);
    }

    if(data>root->data){

        root->right=insert(root->right,data);
    }
    return root;
}

void inorder(bst * root){


    if(root==NULL){
        return;
    }

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

bst * search(bst *root,int data){


    if(root==NULL || root->data==data){
        return root;
    }
    if(data<root->data){
        return search(root->left,data);    
    }

    return search(root->right,data);
}

vector<bst*> queue;

void levelorder(bst *root){
    queue.push_back(root);
    while(queue.size()){

        bst * temp=queue[0];
        if(temp->left!=NULL){
            queue.push_back(temp->left);
        }
        if(temp->right!=NULL){
            queue.push_back(temp->right);
        }
        cout<<temp->data<<" ";
        queue.erase(queue.begin());

    }
}

vector<bst*> lqueue;
void linelevel(bst *root){
    lqueue.push_back(root);
    lqueue.push_back(NULL);

    while(lqueue.size()>1){
        bst * temp=lqueue[0];
        if(temp==NULL){
            cout<<endl;
            lqueue.erase(lqueue.begin());
            lqueue.push_back(NULL);
            continue;
        }
         if(temp->left!=NULL){
            lqueue.push_back(temp->left);
        }
        if(temp->right!=NULL){

            lqueue.push_back(temp->right);
        }
        cout<<temp->data<<" ";
        lqueue.erase(lqueue.begin());
    }

}


void printk(bst * root,int k){
    if(root==NULL){
        return ;
    }
    if(k==0){
        cout<<root->data<<" ";
    }

    printk(root->left,k-1);
    printk(root->right,k-1);



}


int height(bst * root){
    
    if(root==NULL){
        return 0;
    }

    int l=height(root->left);
    int r=height(root->right);

    return max(l,r)+1;
}
bool islesser(bst * root,int data){
    if(root==NULL){
        return true;
        }

        if(root->data<data && islesser(root->left,data) && islesser(root->right,data)){

            return true;
        }
        else{
            return false;
        }

}

bool isgreater(bst *root,int data){


    if(root==NULL){
        return true;
    }
    if(root->data>data && isgreater(root->left,data)&& isgreater(root->right,data)){
        return true;
    }
    else{
        return false;
    }
}







bool isbst(bst *root){
if(root==NULL){
    return true;
}

if(islesser(root->left,root->data)&&isgreater(root->right,root->data)&&isbst(root->left)&&isbst(root->right)){
    return true;
}
else{
    return false;
}


}

void numberofleafnodes(bst *root,int * counter){

if(root==NULL){
    return ;
}

if(root->left==NULL && root->right==NULL){
    * counter++;
}

numberofleafnodes(root->left,counter);
numberofleafnodes(root->right,counter);
return;


}


bst * findmin(bst*root){
    if(root==NULL){
        return NULL;
    }
    while(root->left!=NULL){
        root=root->left;
    }
    return root;
}

bst * deletes(bst * root,int data){

if(root==NULL){
    return NULL;
}
if(data>root->data){
    root->right=deletes(root->right,data);
}
if(data<root->data){
    root->left=deletes(root->left,data);
}

if(data==root->data){

    if(root->left==NULL & root->right==NULL){
        delete(root);
        root=NULL;
    }

    else if(root->left==NULL){
        bst *temp=root;
        root=root->right;
        delete(temp);
    }
    else if (root->right==NULL){
        bst * temp=root;
        root=root->left;
        delete(temp);
    }
    else{
        bst * temp;
        temp=findmin(root->right);
        root->data=temp->data;
        root->right=deletes(root->right,temp->data);

    }






}
return root;





}




int main(){
root=insert(root,50);
root=insert(root,30);
root=insert(root,75);
root=insert(root,20);
root=insert(root,40);
root=insert(root,65);
root=insert(root,80);
root=insert(root,90);
root=insert(root,78);
root=insert(root,200);


//inorder(root);

//  if(search(root,39)){
//      cout<<"YES"<<endl;
//  }
//  else{
//      cout<<"NO"<<endl;
//  }
// cout<<"level order traversal : ";
// levelorder(root);
// cout<<endl;
// cout<<"the height of the tree is " <<height(root)<<endl;

// cout<<"Line wise level order traversal is: \n";
// linelevel(root);

// if(isbst(root)){
//     cout<<"yes"<<endl;
// }
// else{
//     cout<<"NO"<<endl;
// }
// int counter=0;
// cout<<"the number of leaf nodes are: "<< numberofleafnodes(root,&counter); 
cout<<"Inorder before deletion"<<endl;
inorder(root);
cout<<endl;
cout<<"Inorder after deletion"<<endl;
deletes(root,65);
inorder(root);



}

