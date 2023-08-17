#include<iostream>
using namespace std;
string movex(string s){
    //base case
    if(s.length()==0){
        string k="";
        return k;
    }


    //recursive case
    string a=s.substr(0,1);
    string chotistring = movex(s.substr(1));
    if(a=="x"){
        string badistring = chotistring+a;
        return badistring;
    }
    else{
        string badistring = a+chotistring;
        return badistring;
    }
    
}

int main(){
    string s;
    cin>>s;
    string x=movex(s);
    cout<<x<<endl;


}