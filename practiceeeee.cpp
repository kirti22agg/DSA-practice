#include<iostream>
using namespace std;
int uniquepaths(int rows,int cols,int i,int j){
    if(i==rows-1 && j==cols-1){
        return 1;
    }
    if(i>=rows || j>=cols){
        return -1;
    }

    
}
int main(){
    int rows,cols;
    cin>>rows>>cols;
    uniquepaths(rows,cols,0,0);
}