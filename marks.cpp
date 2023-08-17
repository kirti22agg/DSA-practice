#include<iostream>
using namespace std;
class physics;
class chemistry;
class maths;
class Marks{
    protected:
    int rollno;
    string name;
    int marks[3];
    public:
    Marks(){};
    Marks(int roll,string n){
        rollno=roll;
        name=n;

    }
    void display(){
        cout<<"roll no: "<<rollno<<endl;
        cout<<"name  : "<<name<<endl;
    }
    friend int gettotalmarks(Marks&,physics&,chemistry&,maths&);

};
class physics:public Marks{
    private:
    int mark;
    public:
    physics(){};
    physics(int mark){
        this->mark=mark;
    }
    friend int getphysicsmarks(physics&);

};
class chemistry:public Marks{
    private:
    int mark;
    public:
    chemistry(){};
    chemistry(int mark){
        this->mark=mark;
    }
    friend int getchemistrymarks(chemistry&);

};
class maths:public Marks{
    private:
    int mark;
    public:
    maths(){};
    maths(int mark){
        this->mark=mark;
    }
    friend int getmathsmarks(maths&);

};

