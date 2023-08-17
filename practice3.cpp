#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int space;
    for(int i=1;i<=n;i++){
        int space=n-i;
        while(space){
            cout<<"  ";
            space=space-1;
        }
         for(int j=1;j<=2*i-1;j++){
            cout<<"*"<<" ";
        }
        
        cout<<endl;

    }
    
    
    for(int i=1;i<n;i++){
        int space=i;
        while(space){
            cout<<"  ";
            space=space-1;
        }
        for(int j=1;j<=2*n-2*i-1;j++){
            cout<<"*"<<" ";
        }
        cout<<endl;

    }
    
}