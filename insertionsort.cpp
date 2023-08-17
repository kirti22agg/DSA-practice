#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[1000];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int i,j;
    for(i=1;i<=n-1;i++){
        int current= arr[i];
        j = i-1;
        for(j;j>=0 && arr[j]>current;j--){
            arr[j+1]=arr[j];

        }
        arr[j+1]=current;
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    

}

    