#include<iostream>
using namespace std;
class employee{
    private:
    int empid;
    string name;
    int bsalary;
    int allowance;
    public:
    employee(){
        bsalary=1000;
    }
    void getdetails(){
        cout<<"enter employee id"<<endl;
        cin>>empid;
        cout<<"enter empoyee name"<<endl;
        cin>>name;
        cout<<"enter allowance"<<endl;
        cin>>allowance;

    }
    void dispdetails(){
        cout<<empid<<endl<<name<<endl<<bsalary<<endl<<allowance;
    }


};
int main(){
    employee e[2];
    for(int i=0;i<2;i++){
        e[i].getdetails();
    }
    for(int i=0;i<2;i++){
        e[i].dispdetails();
    }
}
