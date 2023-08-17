#include <iostream>
using namespace std;
int binarysearch(int *arr,int key,int s,int e){
    //base case
    if(s>e){
        return -1;
    }



    //recursive case
    int mid=(s+e)/2;
    if(arr[mid]>key){
       return  binarysearch(arr,key,s,mid-1);

    }
    if(arr[mid]==key){
        return mid;
    }
    else{
        return binarysearch(arr,key,mid+1,e);
    }

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
    int q=binarysearch(arr,key,0,n-1);
    cout<<q<<endl;
}