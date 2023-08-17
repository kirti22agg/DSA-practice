#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    if(1<=n<10){
        for(int row=1;row<=n;row++){
            int count=1;
            for(int col=1;col<=row;col++){
                cout<<count<<" ";
                count++;
            }
            
            for(int stars=0;stars<=n-row;stars++){
                cout<<"*"<<" ";
            }
            cout<<endl;
        }
        
    }
}