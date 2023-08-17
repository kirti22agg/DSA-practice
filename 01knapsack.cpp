#include<iostream>
#include<cstring>
using namespace std;
int knapsack(int *price,int *weight,int capacity,int n,int dp[][100])
{
    //base case
    if(n==0 || capacity==0){
        return dp[n][capacity]= 0;
    }

    //recursive case
    if(dp[n][capacity]!=-1){
        return dp[n][capacity];
    }
    int op1=INT_MIN,op2=INT_MIN;
    //include
    if(capacity>=weight[n-1]){
        op1= price[n-1]+knapsack(price,weight,capacity-weight[n-1],n-1,dp);
       
    }
    //exclude
    op2=knapsack(price,weight,capacity,n-1,dp);


    return dp[n][capacity]=max(op1,op2);


}

int bottomup(int *price,int *weight,int capacity,int n){
    int dp[100][100]={0};
    for(int i=1;i<=n;i++){
        for(int j=1;j<=capacity;j++){
            int op1=INT_MIN,op2=INT_MIN;
    
            if(j>=weight[i-1]){
               op1=price[i-1]+dp[i-1][j-weight[i-1]];
            }
            op2=dp[i-1][j];
            dp[i][j]=max(op1,op2);
        }
    }
    return dp[n][capacity];

}
int main(){
    int price[]={10,40,100,30};
    int weight[]={5,4,8,4};
    int n=sizeof(price)/sizeof(int);
    int capacity=15;
    int dp[100][100];
    memset(dp,-1,sizeof(dp));
    cout<<knapsack(price,weight,capacity,n,dp)<<endl;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=capacity;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<bottomup(price,weight,capacity,n);

}