#include <iostream>
using namespace std;

class queue{
    int f;
    int n;
    int e;
    int cs; //current size
    int* arr;
    public:
    queue(int s=5){
        n=s;
        arr = new int[s];
        f=0;
        e=n-1;
        cs=0;
        
    }
    void push(int d){
        if(cs<n){
            e=(e+1)%n;
            arr[e]=d;
            cs++;

        }
        else{
            cout<<"queue is full"<<endl;
        }
        
        
        
    }
    
    void pop(){
        if(cs>0){
            f=(f+1)%n;
            cs--;
        }
        else{
            cout<<"queue is empty"<<endl;
        }
        
    }

    int front(){
        return arr[f];
    }

    bool empty(){
        return cs==0;
    }

    int size(){
        return cs;
    }


};
int main(){
    // queue q;  //5 size diya hai by default hmne, elements 7 pass krdiye, toh 2 bar cout krega queue is full
    queue q(7);
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    q.push(7);

    // int n;
    // cin>>n;
    // for(int i=0;i<n;i++){
    //     int temp;
    //     cin>>temp;
    //     q.push(temp);
    // }



    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }


}