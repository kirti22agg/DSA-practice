#include<iostream>
using namespace std;
int main(){
    int n,flag,i=2;
    cin>>n;
    while(i<n){
        if(n%i==0){
            flag=1;
        
        }
        
        i=i+1;

    }
    if(flag==1){
        cout<<"not prime";
    }
    else{
        cout<<"prime";

    }
    
}