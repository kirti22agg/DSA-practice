#include <iostream>
#include <cstring>
using namespace std;
int stringtoint(char arr[],int l){
    //base case
    if(l==0){
        return 0;
    }


    //recursive case
    int digit=arr[l-1]-'0';
    int ans= stringtoint(arr,l-1)*10 + digit;
    return ans;

}
int main(){
    char arr[100];
    cin>>arr;
    int l=strlen(arr);
    int x=stringtoint(arr,l);
    int y=x+100; //to check ki int meconvert hua ya ni
    cout<<x<<endl;
    cout<<y;

}