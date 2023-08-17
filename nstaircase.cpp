#include <iostream>
using namespace std;
 
// int nstairs(int n){
//     if(n==0){
//         return 1;
//     }
//     if(n<0){
//         return 0;
//     }
//     return nstairs(n-1)+nstairs(n-2)+nstairs(n-3); //for k=3
     

// }
int nstairswithk(int n,int k){
    if(n==0){
        return 1;
    }
    if(n<0){
        return 0;
    }
    int ans=0;
    for(int i=1;i<=k;i++){
        ans+=nstairswithk(n-i,k); 

    }
    return ans;

}
 
int main(){
    int n;
    cin>>n;
    // cout<<nstairs(n)<<endl;
    int k;
    cin>>k;
    cout<<nstairswithk(n,k)<<endl;
}