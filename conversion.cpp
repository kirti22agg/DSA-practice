#include<iostream>
#include <math.h>
using namespace std;
int main(){
    int sb,db,sn;
    cin>>sb;
    cin>>db;
    cin>>sn;
    int base10=0;
    int count=0;

    while(sn>0){
        int rem=sn%10;
        base10= base10+ rem*(pow(sb,count));
        sn= sn/10;
        count++;
    }

    int rem[32];
    int i=0;
    
    while(base10>0){
        rem[i]=base10%db;
        base10= base10/db;
        i++;
        
    }
    for(int j=i-1;j>=0;j--){
        cout<<rem[j];
    }

}