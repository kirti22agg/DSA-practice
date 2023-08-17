#include<iostream>
using namespace std;
class mammals{
    public:
    void display1(){
        cout<<"i am mammal"<<endl;
        

    }

};
class marineanimals{
    public:
    void display2(){
        cout<<"i am marine animal"<<endl;

    }

};
class BlueWhale: public mammals,public marineanimals{
    public:
    void display3(){
        cout<<"i belong to both categories"<<endl;
    }


};
int main(){
    mammals m;
    marineanimals ma;
    BlueWhale bw;

    m.display1();
    ma.display2();
    bw.display3();
    bw.display1();
    bw.display2();

}
