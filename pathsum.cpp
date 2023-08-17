#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* right;
    node* left;
    node(int d){
        data=d;
        right=NULL;
        left=NULL;
    }
};
node* buildtree(){
    int data;
    cin>>data;
    if(data==-1){
        return NULL;
    }
    else{
        node* root=new node(data);
        root->left=buildtree();
        root->right=buildtree();
        return root;
    }

}
bool helper(node* root,int target,int sum){
    if(root==NULL){
        return false;
    }
    if(root->left==NULL && root->right==NULL && sum+root->data==target){
        return true;
    }
    bool opt1=helper(root->left,target,sum+root->data);
    bool opt2=helper(root->right,target,sum+root->data);
    return (opt1 || opt2);


}
bool checksum(node* root,int target){
    if(root==NULL){
        return false;
    }
    return helper(root,target,0);
    
}
int main(){
    node* root=buildtree();
    int target;
    cin>>target;
    if(checksum(root,target)){
        cout<<"true";

    }
    else{
        cout<<"false";
    }

}









