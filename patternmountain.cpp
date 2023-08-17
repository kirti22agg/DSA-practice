#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    
    for(int i=1; i<=n; i++ ){
        //1st pattern
        for(int j=1; j<=i; j++){
            cout<<j<<"\t";
        }
        //spaces
        for(int space=1 ; space<=2*(n-i)-1;space++ ){
            cout<<"\t";
        }
        //2nd pattern
        for(int j=i; j>=1; j--){
            if( j !=n){
                cout<<j<<"\t";
            }
        }
        cout<<endl;
    }



}
