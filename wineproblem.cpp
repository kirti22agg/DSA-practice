#include<iostream>
using namespace std;
int wineproblem(int l,int r,int *price,int day){
    //base case
    if(l>r){
        return 0;
    }
    //recursive case
    int opt1=price[l]*day+wineproblem(l+1,r,price,day+1);
    int opt2=price[r]*day+wineproblem(l,r-1,price,day+1);
    return max(opt1,opt2);


}
int topdownwineproblem(int l,int r,int *price,int day,int dp[][100]){
    //base case
    if(l>r){
        return dp[l][r]=0;
    }
    //recursive case
    if(dp[l][r]!=-1){
        return dp[l][r];
    }
    int opt1=price[l]*day+topdownwineproblem(l+1,r,price,day+1,dp);
    int opt2=price[r]*day+topdownwineproblem(l,r-1,price,day+1,dp);
    return dp[l][r]=max(opt1,opt2);


}

int bottomupwineproblem(int*price,int n){
    int dp[100][100]={0};
    //diagonals pe kaam kiya
    for(int i=0;i<n;i++){
        dp[i][i]=n*price[i];
        
    }
    //baki ka 
    for(int i=n-2;i>=0;i--){
        for(int j=0;j<n;j++){
            if(i<j){
                int day=n-(j-i);
                int opt1=day*price[i]+dp[i+1][j];
                int opt2=day*price[j]+dp[i][j-1];
                dp[i][j]=max(opt1,opt2);
            }
        }
    }
    return dp[0][n-1];
}
int main(){
    int price[]={2,3,5,1,4};
    int n=sizeof(price)/sizeof(int);
    cout<<wineproblem(0,n-1,price,1)<<endl;
    int dp[100][100];
    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
          dp[i][j]=-1;
        }
    }
    cout<<topdownwineproblem(0,n-1,price,1,dp)<<endl;
    cout<<bottomupwineproblem(price,n)<<endl;
    
}