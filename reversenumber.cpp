#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int ans=0;
    while(n!=0){
        int x=n%10;
        ans=ans*10+x;
        n=n/10;

    }
    cout<<ans;
}