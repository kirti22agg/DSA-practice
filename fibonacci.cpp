#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int ffn=0,sfn=1;
    int c=ffn+sfn;
    while(c<=n){
        if(n==ffn || n==sfn){
        cout<<"Yes, it is a part of fibonacci series";
        return 0;
    }
    
    if(n==c){
        cout<<"Yes, it is a part of Fibonacci series";
        return 0;
    }
    
    ffn=sfn;
    sfn=c;
    c=ffn+sfn;

    }
    cout<<"no, it is not a part of fibonacci series";
    return 0;
    
    
}