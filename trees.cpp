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
        root->left=BuildTree();  //left subtree
        root->right=BuildTree(); //right subtree
        return root;  //root ka address hota h toh pura tree access kr skte h
    }
    
}

void preorder(node* root){  
    //base case
    if(root==NULL){
        return;
    }

    //recursive case
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);

}

void inorder(node* root){
    //base case
    if(root==NULL){
        return;
    }

    //recursive case
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);

}

void postorder(node* root){
    //base case
    if(root==NULL){
        return;
    }

    //recursive case
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";

}

int countnodes(node* root){
    if(root==NULL){
        return 0;
    }
    return countnodes(root->left)+countnodes(root->right)+1;

}

int height(node* root){
    if(root==NULL){
        return 0;
    }
    return max(height(root->right),height(root->left))+1;
}

int sumofnodes(node* root){
    if(root==NULL){
        return 0;
    }
    return sumofnodes(root->left)+sumofnodes(root->right)+root->data;

}

void mirrortree(node* root){
    if(root==NULL){
        return;
    }
    swap(root->left,root->right);
    mirrortree(root->left);
    mirrortree(root->right);
}

int diameter(node* root){
    if(root==NULL){
        return 0;
    }
    int opt1=diameter(root->left);
    int opt2= diameter(root->right);
    int opt3= height(root->left)+height(root->right);
    return max(opt1,max(opt2,opt3));
    
}

class Pair{
    public:
    int dia;
    int h;
};

Pair fastdiameter(node* root){
    Pair p;

    //base case
    if(root==NULL){
        p.h=0;
        p.dia=0;
        return p;
    }
    //recursive case

    Pair left = fastdiameter(root->left);
    Pair right = fastdiameter(root->right);
    p.h = max(left.h,right.h)+1;
    int opt1 = left.h+right.h;
    int opt2 = left.dia;
    int opt3 = right.dia;
    p.dia =  max(opt1,max(opt2,opt3));

    return p;
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

node* BuildTreeLevel(){
    node* root=NULL;
    cout<<"Enter the data of root"<<endl;

    int data;
    cin>>data;
    if(data==-1){
        return NULL;
    }
    root = new node(data);
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
    node* x= q.front();
    q.pop();
    cout<<"Enter data of children of "<<x->data<<endl;
    int leftdata,rightdata;
    cin>>leftdata>>rightdata;
    if(leftdata!=-1){
        x->left = new node(leftdata);
        q.push(x->left);
    }
    if(rightdata!=-1){
        x->right = new node(rightdata);
        q.push(x->right);
    }
    }
    return root;
}

int pre[]={8,3,1,6,4,7,16,14,13};  //globally declare krdiya, tum pass bhi kra skte the
int in[]={1,3,4,6,7,8,16,13,14};
int i=0;

node* createTree(int s,int e){
    //base case
    if(s>e){
        return NULL;
    }

    //recursive case
    int d=pre[i];
    i++;
    node* root = new node(d);
    int k;
    for(int j=s;j<=e;j++){
        if(in[j]==d){
            k=j;
            break;
        }
    }
    root->left=createTree(s,k-1);
    root->right=createTree(k+1,e);
    return root;

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

bool searchinBST(node* root,int key){
    if(root==NULL){
        return false;
    }

    //recursive case
    if(root->data==key){
        return true;
    }
    else if(root->data>key){
        return searchinBST(root->left,key);
    }
    else{
        return searchinBST(root->right,key);
    }
}

void printRange(node* root,int k1,int k2){
    //base case
    if(root==NULL){
        return;
    }

    //recursive case
    printRange(root->left,k1,k2);
    if(root->data>=k1 && root->data<=k2){
        cout<<root->data<<" ";
    }
    printRange(root->right,k1,k2);

}
bool isBST(node* root,int min,int max){
    //base case
    if(root==NULL){
        return true; 
    }
    //recursive case
    if((root->data>=min && root->data<=max) && isBST(root->left,min,root->data) && isBST(root->right,root->data,max)){
        return true;
    }
    return false;


}

class pairr{
    public:
    int height;
    bool balanced;
    pairr(){
        height=0;
        balanced=true; 
    }

};

pairr isbalancedornot(node* root){
    //base case
    pairr p;
    if(root==NULL){
        return p;
    }
    //recursive case
    pairr left=isbalancedornot(root->left);
    pairr right=isbalancedornot(root->right);
    p.height=max(left.height,right.height)+1;
    if((left.balanced==true && right.balanced==true)&& abs(left.height-right.height)<=1){
        p.balanced=true;
    }
    else{
        p.balanced=false;
    }
    return p;
}
int main(){
    //8 3 1 -1 -1 6 4 -1 -1 7 -1 -1 16 -1 14 13 -1 -1 -1
    // node* root= BuildTree();
    // preorder(root);
    // cout<<endl;
    // inorder(root);
    // cout<<endl;
    // postorder(root);
    // cout<<endl;
    // cout<<"total nodes : "<<countnodes(root)<<endl;
    // cout<<"height : "<<height(root)<<endl;
    // cout<<"sum of nodes : "<<sumofnodes(root)<<endl;
    // mirrortree(root);
    // preorder(root);
    // cout<<endl;
    // inorder(root);
    // cout<<endl;
    // postorder(root);
    // cout<<endl;
    // cout<<"diameter : "<<diameter(root)<<endl;

    // Pair x=fastdiameter(root);
    // cout<<"diameter : "<<x.dia<<endl;
    // cout<<"height : "<<x.h<<endl;
    // printlevel(root);
    // cout<<endl;

    // cout<<"Create a tree level wise"<<endl;
    // node*root2 = BuildTreeLevel();
    // preorder(root2);

    // int n=sizeof(in)/sizeof(int); //number of elements dekhne ke liye

    // node* root3=createTree(0,n-1);
    // preorder(root3);
    // cout<<endl;
    // inorder(root3);
    // cout<<endl;
    // postorder(root3);
    // cout<<endl;

    // printlevel(root3);

    node* root4=buildBST();
    preorder(root4);
    cout<<endl;
    inorder(root4);
    cout<<endl;
    postorder(root4);
    cout<<endl;

    printlevel(root4);
    // int key;
    // cout<<"Enter number to be searched"<<endl;
    // cin>>key;
    // if(searchinBST(root4,key)){
    //     cout<<"key is present"<<endl;

    // }
    // else{
    //     cout<<"not present"<<endl;
    // }
    // cout<<"print numbers in range "<<endl;
    // printRange(root4,7,13);

    if(isBST(root4,INT_MIN,INT_MAX)){
        cout<<"it is BST"<<endl;

    }
    else{
        cout<<"it is not BST"<<endl;
    }
    pairr y=isbalancedornot(root4);
    if(y.balanced){
        cout<<"the tree is balanced"<<endl;
    }
    else{
        cout<<"tree is not balanced"<<endl;
    }
    




}