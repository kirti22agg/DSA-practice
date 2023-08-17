#include<iostream>
using namespace std;
class father;
class mother{
    private:
    int salary;
    friend void total_salary(mother,father);
    public:
    mother(){};
    mother(int s){
        salary=s;
    }

};
class father:public mother{
    private:
    int salary;
    friend void total_salary(mother,father);
    public:
    father(){};
    father(int s){
        salary=s;
    }
    
};
void total_salary(mother m,father f){
    cout<<m.salary+f.salary;

}
int main(){
    father f(1000);
    mother m(1500);
    total_salary(m,f);
}