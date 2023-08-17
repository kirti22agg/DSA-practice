#include <iostream>
#include <cstring>
using namespace std;
class car{
    private:
    int price;
    public:
    // char name[100];  //static memory allocation
    char *name;
    int modelno;
    int seats;
    
    //constant data members
    const int tyres;  

    //static data members
    static int cou;
    //default constructor
    car():tyres(4){ 
        cout<<"default constructor called"<<endl;
        name=NULL;  //jb bhi object create ho toh name null point pe kre kyuki dma me pointer ko garbage pe point ni krate kbhi
        cou++;
    }

    //parameterized constructor
    car(char *n,int m,int s,int p):tyres(4){  
        cout<<"parametrized constructor called"<<endl;
        name = new char[strlen(n)+1];  //null pe point krane ki koi zarurat ni h kyuki seedha use value mil hi rhi hai, directly memory allocate krdo, kitni? strlen(n)+1 ek jagah null ki
        strcpy(name,n);
        modelno=m;
        seats=s;
        price=p;
        cou++;
    }

    //copy constructor
    car(car &x):tyres(4){    //in x we have c
       cout<<"copy constructor called"<<endl;
    //    name=x.name;   //shallow copy
       name = new char[strlen(x.name)+1];  //deep copy
       strcpy(name,x.name);
    
       modelno=x.modelno;
       seats=x.seats;
       price=x.price;
       cou++;

    }

    //copy assignment operator
    void operator=(car x){
         cout<<"copy assignment operator called"<<endl;
    //    name=x.name;   //shallow copy
       name = new char[strlen(x.name)+1];  //deep copy
       strcpy(name,x.name);
    
       modelno=x.modelno;
       seats=x.seats;
       price=x.price;

    }

    ~car(){
        cout<<"Destructor called for car "<<name<<endl;
        delete []name;
        cou--;
    }

    
    //member functions
    void update(char *n){

        //isme hm check krenge ki agar vo null hai toh use memory allocate krenge pehle
        if(name!=NULL){   //manlo maine pehle likha a.update("bmw") and then likha a.update("duster"), toh ab to memory me null ni tha na,bmw tha, toh pehle use delete krenge and then null pe vapis
            delete []name;
            name=NULL;
        }
        name = new char[strlen(n)+1];
        strcpy(name,n); //ab isne pehle memory allocate kri and then copy kiya,seedha null me ni kiya

    }
    void print()const{   //constant function, jinme koi change ni aata
    cout<<name<<endl;
    cout<<modelno<<endl;
    cout<<seats<<endl;
    cout<<price<<endl;

    }
    void setprice(int p){  //setter
       if(p<200){
        price =200;  //price kbhi negative na aye, min 200 toh aye hi har bar
       }
       else{
         price = p;
       }

    }
    int getprice(){
        return price;
    }
};

int car::cou=0;  //initialization of static data member
int main(){
    car A;
    // strcpy(A.name,"BMW");  //NULL hai initially isme , ab tum NULL me hi BMW ko copy krva rhe ho, toh segmentation fault dega, NULL ko hm access nhi kr skte
    //toh ab hm ek naya func bnayenge
    A.update("BMW");
    A.modelno=2017;
    A.seats=4;
    A.setprice(50000);
    // cout<<A.name<<endl;
    // cout<<A.modelno<<endl;
    // cout<<A.seats<<endl;
    // cout<<A.price<<endl;   //agar meko A.price ko directly print krana h, toh hm getter use kremge
    // cout<<A.getprice()<<endl;
    A.print();
    cout<<endl<<endl;
    car C("Audi",2020,4,600000);
    C.print();
    cout<<endl<<endl;
    car D=C;  //copy constructor is called. D is formed
    D.print();

    cout<<endl<<endl;

    //deep and shallow copy
    D.name[0]='J';
    C.print();
    cout<<endl<<endl;
    D.print();
    cout<<endl<<endl;  

    //copy assignment operator
    car E;
    E=A;  //operator overloading
    E.print();

    cout<<"total number of cars are : ";
    cout<<car::cou<<endl;


    

}