#include<iostream>
#include <vector>
using namespace std;
class minHeap{
    private:
    //hm chahte h ki heapify ko bahar access na kr paye isliye pvt,verna public bhi krdo toh dikkat ni
    void heapify(int i){
        int minindex=i;
        int leftchild=2*i;
        int rightchild=2*i+1;
        if(leftchild<v.size() && v[minindex]>v[leftchild]){
            minindex=leftchild;
        }
        if(rightchild<v.size() && v[minindex]>v[rightchild]){
            minindex=rightchild;
        }
        if(minindex!=i){
            swap(v[minindex],v[i]);
            heapify(minindex);
        }
    }
    public:
    vector<int> v;
    minHeap(){
        v.push_back(-1);
    }
    void push(int data){
        v.push_back(data);
        int c=v.size()-1;
        int p=c/2;
        while(c>1 && v[p]>v[c]){
            swap(v[p],v[c]);
            c=p;
            p=p/2;

        }
    }
    int top(){
        return v[1];
    }
    void pop(){
        swap(v[1],v[v.size()-1]);
        v.pop_back();
        heapify(1);
    }
    bool empty(){
        return v.size()==1;
    }


};
int main(){
    minHeap h;
    h.push(1);
    h.push(2);
    h.push(3);
    h.push(17);
    h.push(19);
    h.push(36);
    h.push(7);
    h.push(25);
    h.push(100);
    while(!h.empty()){
        cout<<h.top()<<" ";  //sorted order me aega,push krte hue heap ki property check hori h, also known as heap sort
        h.pop();
    }
    cout<<endl;



}