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
node* insertatBST(node* root,int data){
    if(root==NULL){
        root = new node(data);
        return root;
    }
    if(data<=root->data){
        root->left=insertatBST(root->left,data);
    }
    else{
        root->right=insertatBST(root->right,data);

    }
    return root;
}

node* buildBST(){
    node* root=NULL;
    int data;
    cin>>data;
    while(data!=-1){
        root=insertatBST(root,data);
        cin>>data;
    }
    return root;

}

node* deleteinBST(node* root,int key){
    //case1 key is present in lst
    if(root->data>key){
        root->left=deleteinBST(root->left,key);
        return root;
    }
    //case2 key is present in rst
    else if(root->data<key){
        root->right=deleteinBST(root->right,key);
        return root;
    }
    //case3 key is equal to root
    else{
        //no child
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }

        //one child
        else if(root->left==NULL && root->right!=NULL){
            node* temp=root->right;
            delete root;
            // return root->right; root toh hmne del krdiya toh aceess kaise krenge
            return temp;
        }
        else if(root->left!=NULL && root->right==NULL){
            node* temp=root->left;
            delete root;
            return temp;
        }

        //two children
        else{ //root=3
            node* replace = root->right;  //6
            //rst ke min se swap
            //ab right st ka min dhundhne ke liye hme uske ekdm left pe jana hoga
            while(replace->left!=NULL){
                replace=replace->left;  //4
            }
            swap(root->data,replace->data);
            //root ki jagah gya 4 aur replace ki jagah gya 3
            root->right=deleteinBST(root->right,replace->data);
            return root; //4 ka link 8 ke sath

        }
    }
}
int main(){
    node* root=buildBST();
    cout<<"before deletion"<<endl;
    printlevel(root);
    cout<<endl;
    deleteinBST(root,3);
    cout<<"after deletion"<<endl;
    printlevel(root);
}