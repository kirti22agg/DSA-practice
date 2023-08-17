#include <iostream>
using namespace std;
int* f(int n){
    int* arr = new int[1000];
    for(int i=0;i<n;i++){
        cin>>*(arr+i);
    }
    return arr;
}
int main(){

    int n;
    cin>>n;
    
    int* aptr=f(n);  //address return hora h toh pointer me hi store kraenge
    for(int i=0;i<n;i++){
        cout<<*(aptr+i)<<" ";
    }

    delete []aptr;
    aptr=NULL;

}