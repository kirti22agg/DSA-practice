#include<iostream>
using namespace std;
int binarysearch(int a[],int n,int key){
    int s=0;
    int e=n-1;
    while(s<=e){
    int mid=(s+e)/2;
    if(a[mid]==key){
        return mid;
    }
    else if(a[mid]>key){
        e=mid-1;
    }
    else{
        s=mid+1;
    }
    }
    return -1;
}
int main(){
    int n;
    cin>>n;
    int arr[100];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int key;

    cin>>key;
    int q=binarysearch(arr,n,key);
    if(q==-1){
        cout<<"key not found";
    }
    else{
        cout<<"key found at "<<q;
    }

}