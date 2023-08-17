#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    char ip[15];
    cin>>ip;
    char* ptr;
    ptr=strtok(ip,".");
    int cl=0;
    for(int i=0;i<3;i++){
        cl= (cl*10)+(*(ptr+i)-'0');
    }
    if(cl>=0 && cl<=127){
        cout<<"class A";
    }
    else if(cl>=128 && cl<=191){
        cout<<"class B";
    }
    else if(cl>=192 && cl<=223){
        cout<<"class c";
    }
    else if(cl>=224 && cl<=239){
        cout<<"class D";
    }
    else if(cl>=240 && cl<=255){
        cout<<"class E";
    }
    else {
        cout<<"invalid";
    }
    


}