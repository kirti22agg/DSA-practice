#include<iostream>
using namespace std;
class vector{
    public:
    int *arr;
    int ms; //maximum size yani capacity
    int cs; //current size yani size
    //constructor
    vector(int s=2){  //hm starting me hi isko ek size dere hai, 2 ka, starting array ka size
      ms=s;
      cs=0; //abhi koi element nhi dala hai
      arr = new int[ms];

     }

     //member functions
     void push_back(int data){
        if(ms==cs){
            int *oldarr = arr;
            int oldms = ms;
            arr = new int[2*ms];
            ms*=2;
            //to copy elements of old array into the new array
           for(int i=0;i<oldms;i++){
            arr[i]=oldarr[i];
            
          }
        delete []oldarr;  //oldarr ka koi kaam ni h ab

        }
        arr[cs]=data;
        cs++;
        


     }
     void pop_back(){
        if(cs>0){
            cs--;
        }

     }
     int size(){
        return cs;

     }
     int capacity(){
        return ms;

     }
     int operator[](int i){
         return arr[i];

     }

};
int main(){
    vector v;
    v.push_back(1);
    v.push_back(3);
    v.push_back(5);
    v.push_back(7);
    v.push_back(9);

    cout<<"size : "<<v.size()<<endl;
    cout<<"capacity : "<<v.capacity()<<endl;

    v.pop_back();
    cout<<"size : "<<v.size()<<endl;
    cout<<"capacity : "<<v.capacity()<<endl;

    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";   //[] kya indicate krta h ye hmari vector class ko ni pta, toh ab operator overloading
    }




}