#include <iostream>
using namespace std;

void arrsum( int x, int a[]){
    int sum=0;

    for(int i=0;i<x;i++){
        int key=a[i];
        sum = sum + key;
    }
    cout<<sum;


}

int main(){
    int x;
    cin>>x;
    int a[x];
    for(int i=0;i<x;i++){
        cin>>a[i];
    }
    arrsum(x,a);
}