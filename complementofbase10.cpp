#include<iostream>
#include<math.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int ans=0;

    for(int i=0;n>0;i++){
        ans=ans+pow(2,i)*(!(n%2));
        n=n/2;

    }
    

    
    
    cout<<ans;





}