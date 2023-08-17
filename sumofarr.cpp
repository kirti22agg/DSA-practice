#include <iostream>
using namespace std;
//1st method

// int sumofarr(int *a,int n){
//     //base case
//     if(n==0){
//         return 0;
//     }
//     //recursive case
//     int sum= sumofarr(a+1,n-1);
//     int ans=a[0]+sum;

//     return ans;

// }


//2nd method

// int sumofarr(int *a,int n,int i){
//     //base case
//     if(i==n){
//         return 0;
//     }
//     //recursive case

//      int sum= sumofarr(a,n,i+1);
//     int ans=a[i]+sum;
    

//     return ans;

// }


//3rd method

int sumofarr(int *a,int n){
    //base case
    if(n==0){
        return 0;
    }

    //recursive case
    return a[n-1]+sumofarr(a,n-1);

}


int main(){
    int arr[]={1,2,3,4,5};
    int n=sizeof(arr)/sizeof(int);
    int i;
    // int x1=sumofarr(arr,n);
    // int x2=sumofarr(arr,n,0);
    int x3=sumofarr(arr,n);
    cout<<x3;

    // cout<<x;
}