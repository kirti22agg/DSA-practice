#include<iostream>
#include<unordered_map>
using namespace std;

int main(){
    unordered_map<string,int> h;
    h["mango"]=100;
    h.insert({"grapes",60});
    pair<string,int> p("apple",150);
    h.insert(p);
    h.insert(make_pair("cherry",120));

   

}
   


    

