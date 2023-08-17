#include<iostream>
using namespace std;
int length(char a[]){
    int count=0;
    for(int i=0;a[i]!='\0';i++){
        count++;
    }
    return count;
}

int main(){
    char arr[100];
    cin.getline(arr,100);
    int n;
    cin>>n;
    int larr=length(arr);
    
    int j=larr-1;
    while(j>=0){
        arr[j+n]=arr[j];
        j--;
    }
    int k=larr;
    int l=0;
    for (int i=0;i<n;i++){
        arr[l]=arr[k];
        k++;
        l++;
    }
    arr[larr]='\0';


    cout<<arr;
    
}