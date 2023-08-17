#include <iostream>
using namespace std;
int main(){

    //1d array
    // int *arrptr = new int[100];
    // for(int i=0; i<5; i++){
    //     cin>>*(arrptr+i);
    // }
    // for(int i=0; i<5; i++){
    //     // cout<<*(arrptr+i)<<" ";
    //     cout<<arrptr[i]<<" ";
    // }

    // delete []arrptr;
    // arrptr = NULL;

    //2darray
    int** arr; //stack memory me jaega aise declare krne se
    int rows,cols;
    cin>>rows>>cols;
    arr = new int* [rows];
    for(int i=0;i<rows;i++){
        arr[i]= new int [cols];
    }

    //taking input
    int number=1;
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            // cin>>arr[i][j];
            arr[i][j]=number;
            number++;
        }
    }

    //printing array
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            
           cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    //deleting array
    for(int i=0;i<rows;i++){
        delete []arr[i];
    }
    delete []arr; 
    arr = NULL; 

    
}