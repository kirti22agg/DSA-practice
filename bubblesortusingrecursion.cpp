#include <iostream>
using namespace std;
void bubblesort(int *a,int n,int i){
    //base case
    if(i==n-1){
        return;
    }
    //recursive case
    for(int j=0;j<=n-2-i;j++){
            if(a[j]>a[j+1]){
                swap(a[j],a[j+1]);
    
            }
    }
    bubblesort(a,n,i+1);

}
void bubblesort2(int *a,int n,int i,int j){  //to remove the j loop
    
    if(i==n-1){
        return;
    }
    if(j==n-1-i){  //ek element apni jagah pe pahunch chuka hai
        bubblesort2(a,n,i+1,0);
    }
    else{
        if(a[j]>a[j+1]){
                swap(a[j],a[j+1]);
    
            }
            bubblesort2(a,n,i,j+1);
        
    }
    



}
int main(){


    int n;
    cin>>n;
    int arr[1000];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    // bubblesort(arr,n,0);
    bubblesort2(arr,n,0,0);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    
}