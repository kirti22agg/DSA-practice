#include<iostream>
#include<queue>
using namespace std;
class node{
    public:
    int val;
    node* left;
    node* right;
    node(int d){
        val=d;
        left=NULL;
        right=NULL;
    }
};
node* buildtree(){
    int data;
    cin>>data;
    if(data=-1){
        return NULL;
    }
    else{
        node* n=new node(data);
        n->left=buildtree();
        n->right=buildtree();
        return n;
    }
}
void preorder(node* root){
    if(root==NULL){
        return;
    }
    cout<<root->val<<" ";
    preorder(root->left);
    preorder(root->right);
}
void inorder(node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}
int totalnodes(node* root){
    if(root==NULL){
        return 0;
    }
    return totalnodes(root->left)+totalnodes(root->right)+1;
}
int height(node* root){
    if(root==NULL){
        return 0;
    }
    return max(height(root->left),height(root->right))+1;
}
int sum(node* root){
    if(root==NULL){
        return 0;
    }
    return sum(root->right)+sum(root->left)+root->val;
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
    int opt2=diameter(root->right);
    int opt3=height(root->left)+height(root->right);
    return max(opt1,(opt2,opt3));
}
class pairr{
    public:
    int dia;
    int h;
};
pairr fastdiameter(node* root){
    pairr p;
    if(root==NULL){
        p.dia=0;
        p.h=0;
        return p;
    }
    pairr left=fastdiameter(root->left);
    pairr right=fastdiameter(root->right);
    p.h=max(left.h,right.h)+1;
    int opt1=left.dia;
    int opt2=right.dia;
    int opt3=left.h+right.h;
    p.dia= max(opt1,(opt2,opt3));
    return p;

}
void levelorder(node* root){
    queue<node*> q;
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
            cout<<x->val<<" ";
            if(x->left!=NULL){
                q.push(x->left);
            }
            if(x->right!=NULL){
                q.push(x->right);
            }
        }
    }
}
node* buildtreelevel(){
    node* root=NULL;
    cout<<"enter root"<<endl;
    int data;
    cin>>data;
    if(data==-1){
        return NULL;
    }
    root=new node(data);
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        node* x=q.front();
        q.pop();
        cout<<"enter children of "<<x->val<<endl;
        int leftchild,rightchild;
        cin>>leftchild>>rightchild;
        if(leftchild!=-1){
            x->left=new node(leftchild);
            q.push(x->left);
        }
        if(rightchild!=-1){
            x->right=new node(rightchild);
            q.push(x->right);
        }

    }
    return root;
}
int pre[]={8,3,1,6,4,7,16,14,13};
int in[]={1,3,4,6,7,8,16,13,14};
int i=0;
node* createtree(int s,int e){
    if(s>e){
        return NULL;
    }
    int d=pre[i];
    i++;
    node* root=new node(d);
    int k;
    for(int j=s;j<=e;j++){
        if(in[j]==d){
            k=j;
            break;
        }
    }
    root->left=createtree(s,k-1);
    root->right=createtree(k+1,e);
    return root;
}
node* insertinbst(node* root,int data){
    if(root==NULL){
        root=new node(data);
        return root;
    }
    if(data<=root->val){
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
bool searchinbst(node* root,int key){
    if(root==NULL){
        return false;
    }
    if(root->val==key){
        return true;
    }
    else if(root->val>=key){
        return searchinbst(root->left,key);

    }
    else{
        return searchinbst(root->right,key);
    }
}
void printnumbers(node* root,int k1,int k2){
    if(root==NULL){
        return;
    }
    if(root->val>=k1 && root->val<=k2){
        cout<<root->val<<" ";
    }
    printnumbers(root->left,k1,k2);
    printnumbers(root->right,k1,k2);
}
bool isbst(node* root,int min,int max){
    if(root==NULL){
        return true;
    }
    if((root->val>=min && root->val<max) && isbst(root->left,min,root->val) && isbst(root->right,root->val,max)){
        return true;
    }
    return false;
}
class linkedlist{
    public:
    node* head;
    node* tail;
    linkedlist(){
        head=NULL;
        tail=NULL;
    }

};
linkedlist bstintoll(node* root){
    linkedlist L;
    if(root==NULL){
        return L;
    }
    if(root->left==NULL && root->right==NULL){
        L.head=root;
        L.tail=root;
        return L;
    }
    else if(root->left!=NULL && root->right==NULL){
        linkedlist Left=bstintoll(root->left);
        Left.tail->right=root;
        L.head=Left.head;
        L.tail=root;
        return L;
    }
    else if(root->left==NULL && root->right!=NULL){
        linkedlist Right=bstintoll(root->right);
        root->right=Right.head;
        L.head=root;
        L.tail=Right.tail;
        return L;
    }
    else{
        linkedlist Left=bstintoll(root->left);
        linkedlist Right=bstintoll(root->right);
        Left.tail->right=root;
        root->right=Right.head;
        L.head=Left.head;
        L.tail=Right.tail;
        return L;
    }
}
void printll(node* head){
    while(head){
        cout<<head->val<<" ";
        head=head->right;
    }
}
int main(){
    node* root=buildbst();
    // int k1,k2;
    // cin>>k1>>k2;
    // printnumbers(root,k1,k2);
    linkedlist L=bstintoll(root);
    printll(L.head);
}