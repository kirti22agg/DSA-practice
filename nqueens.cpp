#include <iostream>
using namespace std;
bool queenplacekrsktehkya(int board[][50],int i, int j,int n){
    //rows and cols
    for(int k=0;k<n;k++){
        if(board[k][j]==1 || board[i][k]==1){  //us row ya col me already placed hai toh tum ni kr skte
            return false;
        }

    }
    //diagonals 
      //right
      int r=i,c=j;
      while(i>=0 && j<n){
        if(board[i][j]==1){
            return false;
        }
        i--;
        j++;
      }

      //left
      while(r>=0 && c>=0){   //i j use kr chuke h toh values change ho chuki hongi
        if(board[r][c]==1){
            return false;
        }
        r--;
        c--;
      }
      return true;

}
bool nqueens(int board[][50],int i,int n){
    //base case
    if(i==n){
        for(int k=0;k<n;k++){
            for(int l=0;l<n;l++){
                cout<<board[k][l]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        // return true;
        return false;  //to print all solns
    }

    //recursive case
    for(int j=0;j<n;j++){
        if(queenplacekrsktehkya(board,i,j,n) == true){
            board[i][j]=1;
            bool kyabakiqueensplacehosktih = nqueens(board,i+1,n);
            if(kyabakiqueensplacehosktih==true){
                return true;
            }
            else{
               board[i][j]=0; //backtracking
            }
        }

    }
    return false; //kahi place ho hi nhi paya first row me



}
int main(){
    int board[50][50] = {0};
    int n;
    cin>>n;
    nqueens(board,0,n);
}