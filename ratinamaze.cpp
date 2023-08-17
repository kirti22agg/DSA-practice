#include <iostream>
using namespace std;
int sol[100][100]={0};
bool ratinamaze(char maze[][10],int i,int j,int m,int n){
    //base case
    if(i==n-1 && j==m-1){
        sol[i][j]=1;  //last pe jb pahucha toh vaha bhi tih 1 dalna pdega hme
        for(int k=0;k<n;k++){   //printing the sol matrix
            for(int l=0;l<m;l++){
                cout<<sol[k][l]<<" ";
            }
            cout<<endl; 

        }
        cout<<endl;
        // return true;  //EK PATH PRINT HOGA
        //AB AGAR HME SAARE PATHS PRINTS KRANE HAI, TOH HM COMPILER KO BOLENGE KI PATH NI MILA
        return false;
        //ab vo vapis check krega ki koi aur path toh ni hai?

    }

    //recursive case
    sol[i][j]=1; //puts 1 at current position
    //checking for right
    if(j+1<m && maze[i][j+1]!='X'){
        bool kyarightsepathexistkrtah = ratinamaze(maze,i,j+1,m,n);
        if(kyarightsepathexistkrtah==true){
            return true;
        }

    }
    //checking for down
    if(i+1<n && maze[i+1][j]!='X'){
        bool kyadownsepathexistkrtah = ratinamaze(maze,i+1,j,m,n);
        if(kyadownsepathexistkrtah==true){
            return true;
        }
        
    }
    sol[i][j]=0;  //dono if ni chale toh
    return false;

}
int main(){
    char maze[][10]={
        "0X00",
        "000X",
        "000X",
        "XX00"
    };
    int m=4; //cols
    int n=4; //rows
    bool ans=ratinamaze(maze,0,0,m,n);
    if(ans==false){
        cout<<"path does not exist"<<endl; 
    }

}