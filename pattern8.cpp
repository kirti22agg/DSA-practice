#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    
    int i=1;
    while(i<=n){
        int j=1;
        char value= 'A';
        while(j<=n-i+1){
            
            cout<<value;
            j=j+1;
            value=value+1;
        }
        int start=1;
        char ch= 'A'+n-i;
        while(start<=n-i+1){
            cout<<ch;
            start=start+1;
            ch = ch-1;
            
        }
        i=i+1;
        cout<<endl;
    }




}
