#include "node.h"
using namespace std;
template<typename T>

class stack{
    private:
    node<T>* head;
    int len;
    public:
    stack(){
        head=NULL;
        len=0;
    }
    void push(T d){
        node<T>* n = new node<T>(d);
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
            node<T>* n = head;
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
    T top(){
        return head->data;
    }

};