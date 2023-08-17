#include <iostream>
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
class queue{
    private:
    node* head;
    node* tail;
    int len;
    public:
    queue(){
        head=NULL;
        tail=NULL;
        len=0;
    }
    void push(int d){
        node* n=new node(d);
        if(head==NULL){
            head=n;
            tail=n;
        }
        else{
            tail->next=n;
            tail=n;
        }
        
        len++;
    }
    
    void pop(){
        if(head==NULL){
            return;
        }
        else if(head->next==NULL){
            delete head;
            head = NULL;
            tail = NULL;
            len--;

        }
        else{
            node* n=head;
            head=head->next;
            delete n;
            len--;
        }
    }

    int front(){
        return head->data;
    }

    bool empty(){
        return head==NULL;
    }

    int size(){
        return len;
    }


};
int main(){
    queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }




}