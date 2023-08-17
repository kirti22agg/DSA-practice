#include<iostream>
using namespace std;
int main(){
    int n,maximumsum=INT_MIN;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"printing array"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    for(int i=0;i<=n-1;i++){
        for(int j=0;j<=n-1;j++){
            int sum=0;
            for(int k=i;k<=j;k++){
                // cout<<arr[k]<<" ";
                sum=sum+arr[k];
            }
            if(sum>maximumsum){
                maximumsum=sum;
            }

            cout<<endl;
        }
    }
    cout<<"maximum subarray sum is: " <<maximumsum<<endl;
}