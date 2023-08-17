#include <iostream>
using namespace std;
class Pair{
    public:
    int a;
    int b;

    Pair(int a, int b){
        this->a=a;
        this->b=b;
    }

    bool operator<(Pair &y){
        if(a<y.a && b<y.b){    //hmne jo pass kiya vo hai y, yani y ka a and b hai hmare pas, and jiske sath compare krna hai yani x ke a and b
            return true;
        }
        else{
            return false;
        }

    }

};
int main(){
    Pair x(10,25);
    Pair y(15,30);
    if(x<y){
        cout<<"x is less than y"<<endl;
    }
    else{
        cout<<"x is greater than y"<<endl;
    }

}