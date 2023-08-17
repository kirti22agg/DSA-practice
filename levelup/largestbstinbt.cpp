#include<iostream>
#include<vector>
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
class nodehelper{
    public:
    int subtreesize;
    bool isbst;
    int maxvalinst;
    int minvalinst;
    nodehelper(){
        subtreesize=0;
        isbst=true;
        maxvalinst=INT_MIN;
        minvalinst=INT_MAX;
    }
};
int i=0;
node* createTree(int s,int e,vector<int> pre,vector<int> in){
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
    root->left=createTree(s,k-1,pre,in);
    root->right=createTree(k+1,e,pre,in);
    return root;

}
int ans=0;
nodehelper gethelper(node* root){
    nodehelper myhelper;
    if(root==NULL){
        return myhelper;
    }
    nodehelper Left= gethelper(root->left);
    nodehelper Right= gethelper(root->right);
    myhelper.subtreesize=1+Left.subtreesize+Right.subtreesize;
    myhelper.maxvalinst=max(max(root->data,Right.maxvalinst),Left.maxvalinst);
    myhelper.minvalinst=min(min(root->data,Right.minvalinst),Left.minvalinst);
    myhelper.isbst=Left.isbst && Right.isbst && root->data>=Left.maxvalinst && root->data<Right.minvalinst;
    if(myhelper.isbst){
        ans=max(ans,myhelper.subtreesize);
    }
    return myhelper;


}
int main(){
    int n;
    cin>>n;
    vector<int> pre(n);
    vector<int> in(n);
    for(int i=0;i<n;i++){
        cin>>pre[i];
    }
    for(int i=0;i<n;i++){
        cin>>in[i];
    }
    node* root= createTree(0,n-1,pre,in);
    gethelper(root);
    cout<<ans<<endl;


}