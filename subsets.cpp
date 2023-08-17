#include<iostream>
#include<math.h>

using namespace std;
int main(){
    int n;
    int arr[1000];
    cin>>n;
    cout<<" The array is: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    

    for(int i=0; i<=pow(2,n)-1;i++){
        int bitpos=0;
        while(n!=0){

            if(n&1==1){
                cout<<arr[bitpos]<<" ";
            }
            n=n>>1;
        bitpos++;

        }
        
        cout<<endl;

        
    }
    
    
}