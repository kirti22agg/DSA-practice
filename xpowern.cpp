#include <iostream>
using namespace std;
int powerfun(int x,int n){
    //base case
    if(n==0){
        return 1;
    }

    //recursive case
    return x*powerfun(x,n-1);

}
int main(){
    int x,n;
    cin>>x>>n;
    int ans=powerfun(x,n);
    cout<<ans;
}