#include<iostream>
using namespace std;
int main() {
    int n;
    cin>>n;
    int row=1;
    while (row<=n){
        int col=1;
        while(col<=n-row+1){
            cout<<col;
            col=col+1;
        }
        int star=1;
        while(star<=row-1){
            cout<<"*";
            star=star+1;
        }
        int stars=1;
        while(stars<=row-1){
            cout<<"*";
            stars=stars+1;
        }
        int start=1;
        int value=n-row+1;
        while(start<=n-row+1){
            cout<<value;
            value=value-1;
            start=start+1;
        }
    
        cout<<endl;
        row=row+1;

    }

}