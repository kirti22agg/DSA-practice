#include<iostream>
using namespace std;
int factorial(int no){
    int ans=1;
    for(int i=1;i<=no;i++){
        ans=ans*i;
    }
    return ans;
}
int ncr(int n,int r){
    int result= factorial(n)/(factorial(r)*factorial(n-r));
    return result;
}

int main(){
    int n;
    cin>>n;
    for(int row=1;row<=n;row++){
        for(int col=1;col<=row;col++){
            int x= ncr(row-1,col-1);
            cout<<x<<"\t";
        }
        cout<<endl;

    }
    
    
    

    return 0;
    

}

