#include<iostream>
using namespace std;

struct trie{
    trie * child[256];
    bool isend;

    trie(){
        for(int i=0;i<256;i++){
            child[i]=NULL;
            isend=false;
        }
    }
};

void insert(trie *root,string s){
    trie *curr=root;


    for(int i=0;i<s.size();i++){
        if(curr->child[s[i]]==NULL){
            curr->child[s[i]]=new trie();
           
        }
         curr=curr->child[s[i]];
       
    }
    curr->isend=true;
        
        
}
bool search(trie *root,string s){
    trie *curr=root;

    for(int i=0;i<s.size();i++){
        if(curr->child[s[i]]!=NULL){
            curr=curr->child[s[i]];
            continue;
        }
        else{
            return false;
        }

    }

    if(curr->isend!=true){
        return false;
    }
    return true;

    
}



int main(){
    string arr[]={"geek","geeks","bad","bat","batman","cat","cut","zoo","battle"};
    trie *root=new trie();

    for(int i=0;i<9;i++){
        insert(root,arr[i]);
    }


cout<<"enter the number of words you want to search: "<<endl;
    int t;
    cin>>t;
    while(t--){
         string tofind;
        cin>>tofind;

        if(search(root,tofind)){
            cout<<"Found"<<endl;
        }
        else{
            cout<<"Not Found"<<endl;
        }

    }
   





}