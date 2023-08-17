#include<iostream>
using namespace std;
class shape{
    public:
    void display(){
        cout<<"this is a shape"<<endl;

    }
};
class polygon:public shape{
    public:
    void display(){
        cout<<"polygon is a shape"<<endl;
    }
};
class rectangle:public polygon{
    public:
    void display(){
        cout<<"rectangle is a polygon"<<endl;
    }
};
class triangle:public polygon{
    public:
    void display(){
        cout<<"triangle is a polygon"<<endl;
    }
};

class square:public rectangle{
    public:
    void display(){
        cout<<"square is a rectangle"<<endl;
    }
};
int main(){
    shape sh;
    polygon pol;
    triangle tri;
    rectangle rec;
    square sq;
    int ch;
    
    cout<<"printing from various classes"<<endl;
    cout<<"1. print all shapes "<<endl<<"2. print polygon is a shape"<<endl<<"3. print rectangle is a polygon"<<endl<<"4. print triangle is a polygon"<<endl<<"5. print square is a rectangle"<<endl;

    cin>>ch;
    switch (ch)
    {
    case 1:{
        sh.display();
        pol.shape::display();
        rec.shape::display();
        tri.shape::display();
        sq.shape::display();
        break;
        }

    case 2:{
        pol.display();
        rec.polygon::display();
        tri.polygon::display();
        sq.polygon::display();
        break;

    }

    case 3:{
        rec.display();
        sq.rectangle::display();
        break;
    }

    case 4: {
        tri.display();
        break;

    }

    case 5:{
        sq.display();
        break;
    }

    default:{
        cout<<"invalid option";
    }
        
        
    
    }

}
