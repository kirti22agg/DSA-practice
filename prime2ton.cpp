#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int num=2;
    int flag=1;
    while(num<=n){
        int i=2;
        while(i<num){
            if(num%i==0){
                flag=0;
                break;
            }
            else{
                flag=1;
            }
        
            
            i=i+1;
        }
        if (flag==1){
            cout<<num<<endl;
        }
        
        num=num+1;
        
        
    }

}