#include<iostream>
using namespace std;
int multiply(int a,int b){
    //base case
    if(b==0){
        return 0;
    }

    //recursive case
    

   int ans=a+multiply(a,b-1);
   return ans;




}
int main(){
    int a,b;
    cin>>a>>b;
    int x=multiply(a,b);
    cout<<x;
}