#include<iostream>
#include<climits>
using namespace std;
int main(){
    int n;
    cout<<"number of elements: ";
    cin>>n;
    
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int max=INT_MIN, index;
    

    for(int i=0;i<n;i++){
        if(max<arr[i]){
            max=arr[i];
            index=i;
        }
        
    }
    cout<<"largest number is: "<<max<<" present at index: "<<index;
    

}