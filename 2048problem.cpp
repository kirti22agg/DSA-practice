#include <iostream>
using namespace std;
void printnumrev(int n){
    string s[]={"zero","one","two","three","four","five","six","seven","eight","nine"};
    //base case
    if(n==0){
        return;
    }
    //recursive case
    int digit=n%10;
    cout<<s[digit]<<" ";
    printnumrev(n/10);

}
void printnum(int n){
    string s[]={"zero","one","two","three","four","five","six","seven","eight","nine"};
    //base case
    if(n==0){
        return;
    }
    //recursive case
    int digit=n%10;
   
    printnum(n/10);
    cout<<s[digit]<<" ";

}
int main(){
    int n;
    cin>>n;
    printnumrev(n);
    cout<<endl;
    printnum(n);

}