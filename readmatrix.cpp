#include <iostream>
using namespace std;
int main(){
    int arr[100][100];
    int rows,cols;
    cin>>rows;
    cin>>cols;
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            cin>>arr[i][j];
        }
    }
    // for(int i=0;i<rows;i++){
    //     for(int j=0;j<cols;j++){
    //         cout<<arr[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    int target,i,j;
    cin>>target;
    for(i=0;i<rows;i++){
        for(j=0;j<cols;j++){
            if(arr[i][j]==target){
                cout<<"number found at index "<<i<<", "<<j<<endl;
                // return 0; // agar aage kuch code ho jo hme implement krna ho toh break use kremge
                break;  // ab ye is loop se bahar jaega break ki vjah se 
            
            }
            if(j!=cols){
                break;    // ab hme ise next loop se bhi toh bahar nikalna pdega, j==cols ho jata toh vo automatically bahar aa jata,pr abhi vo break ki vajah se bahar aya, yani j!=cols
            }
            
        }
        
    

    }
    if(i==rows){
        cout<<"number not present";

    }
    return 0;

    

}