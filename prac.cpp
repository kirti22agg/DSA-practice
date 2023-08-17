#include<iostream>
using namespace std;
class student {
    private:
    string name;
    int roll;
    int marks;

    public:
    void getdetails(){
        cin>>name;
        cin>>roll;
        cin>>marks;
    }
    void display(){
        cout<<"NAME:"<<name<<" ROLL NO: "<<roll<<" MARKS: "<<marks;
    }

};
int main(){
    student s[5];
    for(int i=0;i<5;i++){
        s[i].getdetails();
    }
    for(int i=0;i<5;i++){
        s[i].display();
    }


    

}
