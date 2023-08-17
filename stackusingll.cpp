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
class stack{
    private:
    node* head;
    int len;
    public:
    stack(){
        head=NULL;
        len=0;
    }
    void push(int d){
        node* n = new node(d);
        n->next=head;
        head=n;
        len++;

    }
    void pop(){
        if(head==NULL){
            return;
        }
        else if(head->next==NULL){
            delete head;
            head = NULL;
            len--;
        }
        else{
            node*n = head;
            head = head->next;
            delete n;
            len--;

        }
        
    }
    bool empty(){
        return head==NULL;
    }
    int size(){
        return len;
    }
    int top(){
        return head->data;
    }

};
int main(){
    stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push('A'); //ASCII value, agar char me hi print krana h toh upar har jagah char krdo data type
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();

    }

}