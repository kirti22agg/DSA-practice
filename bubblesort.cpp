#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[1000];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<=n-2;i++){
        int cnt=0;
        for(int j=0;j<=n-2-i;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                cnt++;
            }
        }
        if (cnt==0){
            break;
        
        }
    }
    
    
    for(int i=0;i<n;i++){
        cout<<arr[i]<<endl;
    }
    

}

    