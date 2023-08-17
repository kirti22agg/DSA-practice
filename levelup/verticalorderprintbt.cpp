#include<iostream>
#include<queue>
#include<unordered_map>
#include<algorithm>
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
    int val;
    int level;
    int timestamp;
    nodehelper(int d,int lvl,int time){
        val=d;
        level=lvl;
        timestamp=time;
    }
};
// node* buildtreelevelwise(){
//     node* root=NULL;
//     int data;
//     cin>>data;
//     if(data==-1){
//         return NULL;
//     }
//     queue<node*> q;
//     q.push(root);
//     while(!q.empty()){
//         node* x=q.front();
//         q.pop(); 
//         int leftdata,rightdata;
//         cin>>leftdata>>rightdata;
//         if(leftdata!=-1){
//             x->left=new node(leftdata);
//             q.push(x->left);
//         }
//         if(rightdata!=-1){
//             x->left=new node(rightdata);
//             q.push(x->right);
//         }


//     }
//     return root;


// }
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
unordered_map<int,vector<nodehelper>> mp;
int leftmostx=0,rightmostx=0;
void traverse(node* root,int lvl,int &time,int xcoordinate){
    if(root==NULL){
        return;
    }
    leftmostx=min(leftmostx,xcoordinate);
    rightmostx=max(rightmostx,xcoordinate);
    nodehelper roothelper= nodehelper(root->data,lvl,time);
    mp[xcoordinate].push_back(roothelper);
    time++;
    traverse(root->left,lvl+1,time,xcoordinate-1);
    traverse(root->right,lvl+1,time,xcoordinate+1);
}
bool comp(nodehelper &a, nodehelper &b){
    if(a.level==b.level){
        return a.timestamp<b.timestamp;
    }
    return a.level<b.level;
}
int main(){
    node* root= BuildTree();
    int time=0;
    traverse(root,0,time,0);
    for(int xcoordinate=leftmostx;xcoordinate<=rightmostx;xcoordinate++){
        vector<nodehelper> &v=mp[xcoordinate];
        sort(v.begin(),v.end(),comp);
        for(int i=0;i<(int)v.size();i++){
            cout<<v[i].val<<" ";
        }
    }
    

}