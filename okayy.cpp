#include<iostream>
using namespace std;
class test{
    public:
    test(){
        cout<<"constructor called"<<endl;
    }
    ~test(){
        cout<<"destructor called"<<endl;
    }
};
int main(){
    test t1;
    int x=1;
    if(x){
        test t2;
    }

}