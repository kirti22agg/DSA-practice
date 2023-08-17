#include <iostream>
using namespace std;
bool issortedornot(int *a,int n){
    //base case
    if(n==0 || n==1){
        return true;
    }
    //recursive case
    bool issort=issortedornot(a+1,n-1);
    if(a[0]<a[1]&&issort==true){
        return true;
    }
    return false;

}
int main(){
    int a[]={1,4,5,9,8};
    int n=sizeof(a)/sizeof(int);
    if(issortedornot(a,n)){
        cout<<"array is sorted";
    }
    else{
        cout<<"array is not sorted";
    }

}