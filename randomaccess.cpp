#include<iostream>
#include <fstream>
using namespace std;
class person {
    protected:
    char name[80];
    int age;
    public:
    void getdata(){
        cout<<"\n enter name";
        cin>>name;
        cout<<"\n enter age";
        cin>>age;

    }
    void showdata(){
        cout<<"\n name:"<<name;
        cout<<"\n age:"<<age;
    }
};
int main(){
    char ch;
    person pers;
    fstream file;
    file.open("GROUP.DAT", ios ::out | ios::in | ios::binary);
    int chW;
    int i=10,count=0;
    while(i==10){
        cout<<"\n MENU \n1.INSERT \n2.UPDATE \n3.DISPLAY \n4.EXIT";
    }
    cin>>chW;
    switch(chW){
        case 1:{
            cout<<"enter person data";
            pers.getdata();
            file.seekp(count*sizeof(pers),ios::beg);
            file.write(reinterpret_cast<char*>(&pers),sizeof(pers));
            count++;

        }
        break;
        case 2: {
            file.seekp(0);
            
        }
    }
}