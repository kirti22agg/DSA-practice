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

node* createBSTusingarray(int *arr,int s,int e){
    //base case
    if(s>e){
        return NULL;
    }

    //recursive case
    int mid=(s+e)/2;
    node* root= new node(arr[mid]);
    root->left=createBSTusingarray(arr,s,mid-1);
    root->right=createBSTusingarray(arr,mid+1,e);
    return root;

}

int main(){
    int arr[]={1,2,3,4,8,9,10};
    int n=sizeof(arr)/sizeof(int);
    node* root=createBSTusingarray(arr,0,n-1);
    printlevel(root);

}
