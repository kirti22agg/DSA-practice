#include <iostream>
#include <queue>
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
node* BuildTree(){
    int data;
    cin>>data;
    if(data==-1){
        return NULL;
    }
    else{
        node* root=new node(data);
        root->left=BuildTree(); 
        root->right=BuildTree(); 
        return root; 
    }
    
}

void printlevel(node* root){
    queue<node*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node* x=q.front();
        q.pop();
        if(x==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
    
            }
        }
        else{
            cout<<x->data<<" ";
            if(x->left!=NULL){
                q.push(x->left);
            }
            if(x->right!=NULL){
                q.push(x->right);
            }
        }
    }

}

void RightView(node* root,int level,int &maxlevel){
    //base case
     if(root==NULL){
        return;
     }

    //recursive case
    
    if(level>maxlevel){
        cout<<root->data<<" ";
        maxlevel=level;
    }
        RightView(root->right,level+1,maxlevel);
        RightView(root->left,level+1,maxlevel);


    
}
int main(){
    node* root=BuildTree();
    printlevel(root);

    // RightView(root,1,0);  call by value me direct pass krne me error dega
    int maxlevel=0;
    RightView(root,1,maxlevel);
}

//8 3 1 -1 -1 6 4 -1 -1 7 -1 9 -1 -1 10 -1 14 13 -1 -1 -1