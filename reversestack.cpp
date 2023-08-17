#include<iostream>
#include<stack>
using namespace std;

void insertatbottom(stack<int> &s,int te){
    //base case
    if(s.empty()){
        s.push(te);
        return;
    }

    //recursive case
    int top=s.top();
    s.pop();
    insertatbottom(s,te);
    s.push(top);

}
void reversestack(stack<int> &s){  //final print me bhi toh vo change dikhna chahiye
    //base case
    if(s.empty()){
        return;
    }
    //recursive case
    int te = s.top();
    s.pop();
    reversestack(s);
    insertatbottom(s,te);

}
void print(stack<int> s){
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();

    }
    cout<<endl;

}

int main(){
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    // while(!s.empty()){
    //     cout<<s.top()<<" ";
    //     s.pop();

    // }
    //mere sare elements pop huye print krane ke liye, toh ab empty stack bacha hoga toh kuch reverse krane ko ni hoga,isliye we'll use a print function
    print(s);
    reversestack(s);
    print(s);
    // while(!s.empty()){
    //     cout<<s.top()<<" ";
    //     s.pop();

    // }
    
}