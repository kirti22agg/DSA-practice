#include<iostream>
using namespace std;
int length(char *arr){
    int count=0;
    for(int i=0;arr[i]!='\0';i++){
        count++;
    }
    return count;
    
}
bool ispalinornot(char *arr){
    int i=0,j=length(arr)-1;
    while(i<j){
        if(arr[i]!=arr[j]){
            return false;
            
        }
        i++;
        j--;
        
    }
    return true;

}
int main(){
    
    char arr[100];
    cin.getline(arr,100);
    if(ispalinornot(arr)){
        cout<<"yes";
    }
    else{
        cout<<"no";
    }

}