#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"number of elements: ";
    cin>>n;
    
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int key;
    cout<<"The number to be searched is: ";
    cin>>key;
    for(int i=0;i<=n;i++){
        if(arr[i]==key){
            cout<<"The number is present at index: "<<i;
            break;
        }
        if(i==n){
            cout<<"key is invalid";
        }
        
        
        
    }

    
    

    
}