#include<iostream>
using namespace std;
int main(){
    char arr[100];
    cin.getline(arr,100);
    int count =0;
    for(int i=0;arr[i]!='\0';i++){
        count++;

    }
    cout<<count;
    return 0;
}