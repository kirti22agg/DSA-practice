#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int row=1;
    while(row<=n){
        int space=n-row;
        while(space){
            cout<<" ";
            space=space-1;
        }
        int col=1;
        int value=row;
        while(col<=row){
            cout<<value;
            value=value+1;
            col=col+1;

        }
        int start=1;
        int count=2*row-2;
        while(start<=row-1){
            
            cout<<count;
            count=count-1;
            start=start+1;
        }
        cout<<endl;
        row=row+1;
        
    }
    

}
    