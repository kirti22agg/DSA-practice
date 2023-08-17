#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node(int d){
        data=d;
        next=NULL;
    }

};
void insertatend(node* &head,node* &tail,int d){
    node *n = new node(d);
    if(head==NULL){
        head=n;
        tail=n;
    }
    else{
        tail->next=n;
        tail=n;
    }
}
void reverse(node* &head){

    node* c=head;
    node* prev=NULL;
    node* n=NULL;
    while(c!=NULL){
        n=c->next;
        c->next=prev;
        prev=c;
        c=n;
    }
    head=prev;

}
// node* print(node* head,node* tail,int k){
//     for(int i=0;i<k-1;i++){
//         head=head->next;
//     }
//     return head;

// }
node* kthelement(node* head,int k){
    node* f=head;
    for(int i=0;i<k;i++){
        f=f->next;
    }
    node* s=head;
    while(f!=NULL){
        f=f->next;
        s=s->next;
    }
    return s;

}

int main(){
    node* head=NULL;
    node* tail=NULL;
    insertatend(head,tail,1);
    insertatend(head,tail,2);
    insertatend(head,tail,3);
    insertatend(head,tail,4);
    insertatend(head,tail,5);
    insertatend(head,tail,6);
    insertatend(head,tail,7);
    // reverse(head);
    int k;
    cin>>k;
    // node* ans=print(head,tail,k);
    // cout<<ans->data;
    node* ans=kthelement(head,k);
    cout<<ans->data;



}
