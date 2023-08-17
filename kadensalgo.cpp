#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int n;
    int arr[1000];
    cin>>n;
    cout<<" The array is: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    int cs=0,ms=0;
    for(int i=0;i<n;i++){
        cs=cs+arr[i];
        if (cs<0)
        {
         cs =0;
        }
        ms = max(ms,cs);
        
    }
    cout<<"maximum sum is: "<<ms;

}