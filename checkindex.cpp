#include <iostream>
using namespace std;
bool ispresentornot(int *a,int size,int n,int i){
    //base case
    if(i==size){
        return false;
    }


    //recursive case
    if(a[i]==n){
        return true;
    }
    return ispresentornot(a,size,n,i+1);

}
int firstindex(int *a,int size,int n,int i){
    //base case
    if(i==size){
        return -1;
    }
    //recursive case
    if(a[i]==n){
        return i;
    }
    return firstindex(a,size,n,i+1);
}
int lastindex(int *a,int size,int n,int i){
    //base case
    if(i<0){
        return -1;
    }
    //recursive case
    if(a[i]==n){
        return i;
    }
    return lastindex(a,size,n,i-1);
}
void allindices(int *a,int size,int n,int i){
    //base case
    if(i==n){
        return;
    }
    //recursive case
    if(a[i]==n){
        cout<<i<<" ";
    }
    allindices(a,size,n,i+1);
}

int main(){
    int arr[]={7,2,3,7,8,7,3};
    int size=sizeof(arr)/sizeof(int);
    int n=7;
    bool x=ispresentornot(arr,size,n,0);
    if(x){
        cout<<"7 is present"<<endl;
    }
    else{
        cout<<"7 is not present"<<endl;
    }

    int y=firstindex(arr,size,n,0);
    cout<<"first index of 7 : "<<y<<endl;

    int z=lastindex(arr,size,n,size-1);
    cout<<"last index of 7 : "<<z<<endl;

    cout<<"all indices of 7 : ";
    allindices(arr,size,n,0);

    

}