#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* left;
    node* right;
    node(int d){
        data=d;
        left=NULL;
        right=NULL;
    }

};
node* insertinbst(node* root,int data){
    if(root==NULL){
        root=new node(data);
        return root;
    }
    if(root->data>=data){
        root->left=insertinbst(root->left,data);
    }
    else{
        root->right=insertinbst(root->right,data);
    }
    return root;

}
node* buildbst(){
    node* root=NULL;
    int data;
    cin>>data;
    while(data!=-1){
        root=insertinbst(root,data);
        cin>>data;
    }
    return root;
}

node* lca(node* root,node* p,node* q){
    if(root==NULL){
        return NULL;
    }
    if(root->data>p->data && root->data>q->data){
        return lca(root->left,p,q);
    }
    else if(root->data<p->data && root->data<q->data){
        return lca(root->right,p,q);
    }
    else{
        return root;
    }
  
}
int main(){
    node* root=buildbst();
    int n,m;
    cin>>n>>m;
    node* p=new node(n);
    node* q=new node(m);
    node* x=lca(root,p,q);
    cout<<x->data;

}