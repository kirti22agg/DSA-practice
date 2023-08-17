using namespace std;
template<typename T>

class node{
    public:
    T data;
    node<T>* next;  //header file create krte hue hme pointer ko bhi batana padta hai ki vo kis type ke data ko point kr rha h 
    node(T d){
        data=d;
        next=NULL;
    }

};