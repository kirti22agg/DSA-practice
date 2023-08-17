#include <iostream>
using namespace std;
void spiralprints(int arr[][100],int rows, int cols){
    int sr=0;
    int er=rows-1;
    int sc=0;
    int ec=cols-1;
    while(sc<=ec&&sr<=er){
        for(int i=sc;i<=ec;i++){
        cout<<arr[sr][i]<<" ";
        
    }
    sr++;
    for(int j=sr;j<=er;j++){
        cout<<arr[j][ec]<<" ";

    }
    ec--;
    if(sr<er){
        for(int i=ec;i>=sc;i--){
        cout<<arr[er][i]<<" ";

    }
    er--;

    }
    if(sc<ec){
        for(int j=er;j>=sr;j--){ 
        cout<<arr[j][sc]<<" ";

    }
    sc++;

    }
    
    

    }
    



}
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
    spiralprints(arr,rows,cols);
    

}