#include<iostream>
#include<cstring>
using namespace std;
int mincost(int cost[][4],int i,int j){
    //base case
    if(i==0&&j==0){
        return cost[i][j];
    }
    if(i<0||j<0){
        return INT_MAX;
    }

    //recursive caes
    int opt1=mincost(cost,i,j-1);
    int opt2=mincost(cost,i-1,j);
    return min(opt1,opt2)+cost[i][j];

}
int topdownmincost(int cost[][4],int i,int j,int dp[][100]){
    //base case
    if(i==0&&j==0){
        return dp[i][j]=cost[i][j];
    }
    if(i<0||j<0){
        return INT_MAX;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    //recursive case
    int opt1=topdownmincost(cost,i,j-1,dp);
    int opt2=topdownmincost(cost,i-1,j,dp);
    return dp[i][j]=min(opt1,opt2)+cost[i][j];

}

int bottomupmincost(int cost[][4],int i,int j){
    int dp[100][100];
    //dp[0][0]=cost[0][0] initialization
    //iterating over the dp array
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(i==0 && j==0){
                dp[i][j]=cost[i][j];
            }
            //1st row
            else if(i==0){
                dp[i][j]=cost[i][j]+dp[i][j-1];
            }
            //ist col
            else if(j==0){
                dp[i][j]=cost[i][j]+dp[i-1][j];
            }
            //baki ka
            else{
                dp[i][j]=min(dp[i-1][j],dp[i][j-1])+cost[i][j];
            }


        }

    }
    return dp[i][j];

}
int main(){
    int cost[][4]={
        {2,1,3,4},
        {3,1,1,10},
        {1,6,1,1},
        {2,7,4,3}
    };
    int dp[100][100];
    // for(int i=0;i<100;i++){
    //     for(int j=0;j<100;j++){
    //       dp[i][j]=-1;
    //     }
    // }
    memset(dp,-1,sizeof(dp));
    int i=1,j=2;
    cout<<mincost(cost,i,j)<<endl;
    cout<<topdownmincost(cost,i,j,dp)<<endl;
    cout<<bottomupmincost(cost,i,j)<<endl;


}