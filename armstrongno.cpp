#include<iostream>
#include<math.h>
using namespace std;
int countdigits(int n){
    int count=0;
    while(n!=0){
        n=n/10;
        count=count+1;
    }
    return count;
}
bool armstrong(int n){
    int sum=0;
    int originalnum=n;
    int x=countdigits(n);
    while(originalnum>0){
        
        int rem=originalnum%10;
        sum= sum+pow(rem,x);
        originalnum=originalnum/10;
    }
    if(sum==n){
        return true;
    }
    else{
        return false;
    }
}
int main(){
    int n;
    cin>>n;
    if(armstrong(n)){
        cout<<"true";
    }
    else{
        cout<<"false";
    }



}