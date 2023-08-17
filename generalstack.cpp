#include <iostream>
#include <vector>
using namespace std;
template<typename T>
class stack{
    private:
    vector<T> v;
    public:
    void push(T data){
        v.push_back(data);
    }
    void pop(){
        v.pop_back();
    }
    T top(){
        return v[v.size()-1];
    }
    int size(){
        return v.size();
    }
    bool empty(){
        return v.size()==0;
    }

};
int main(){
    // stack<int> s;
    // s.push(1);
    // s.push(2);
    // s.push(3);
    // s.push(4);
    // while(!s.empty()){
    //     cout<<s.top()<<" ";
    //     s.pop();

    // }

    stack<char> s;
    s.push('A');
    s.push('B');
    s.push('C');
    s.push('D');
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();

    }

}