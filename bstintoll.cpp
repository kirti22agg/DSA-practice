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

class linkedlist{
    public:
    node* head;
    node* tail;
    linkedlist(){
        head=NULL;
        tail=NULL; 
    }

};
linkedlist BSTtoLL(node* root){
    linkedlist L;
    //base case
    if(root==NULL){
        return L; //head=null,tail=null
    }

    //recursive case
    //case 1
    if(root->left==NULL && root->right==NULL){
        L.head=root;
        L.tail=root;
        return L;
    }
    //case 2
    else if(root->left!=NULL && root->right==NULL){
        linkedlist Left = BSTtoLL(root->left);
        Left.tail->right = root;
        L.head=Left.head;
        L.tail=root;
        return L;
    }
    //case 3
    else if(root->left==NULL && root->right!=NULL){
        linkedlist Right = BSTtoLL(root->right);
        root->right =Right.head;
        L.head=root;
        L.tail=Right.tail;
        return L;
    }
    //case 4
    else{
        linkedlist Left = BSTtoLL(root->left);
        linkedlist Right = BSTtoLL(root->right);
        Left.tail->right = root;
        root->right =Right.head;
        L.head=Left.head;
        L.tail=Right.tail;
        return L;

    }
}

void printll(node* head){
    while(head!=NULL){
        cout<<head->data<<"-->";
        head=head->right;
    }
    cout<<"NULL"<<endl;
}
int main(){
    node* root=buildBST();
    printlevel(root);
    linkedlist l=BSTtoLL(root);
    printll(l.head);
}