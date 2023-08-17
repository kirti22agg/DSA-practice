#include<iostream>
using namespace std;
int fibo(int n){
    //base case
    if(n==0||n==1){
        return n;
    }
    //recursive case
    return fibo(n-1)+fibo(n-2);
}
int topdownfibo(int n,int *dp){
    //base case
    if(n==0||n==1){
        return dp[n]=n; //yaha pe bhi return kr rha hai,to ise bhi store
    }
    //calculate krne se pehle check
    if(dp[n]!=-1){
        return dp[n];
    }
    //recursive case
    //return krne se pehle store
    dp[n]=topdownfibo(n-1,dp)+topdownfibo(n-2,dp);
    return topdownfibo(n-1,dp)+topdownfibo(n-2,dp);
    //return dp[n]=topdownfibo(n-1,dp)+topdownfibo(n-2,dp)
}
int bottomupfibo(int n){
    int* arr=new int[n+1];
    //initialization
    arr[0]=0;
    arr[1]=1;
    //loop
    for (int i = 2; i <=n; i++)
    {
        arr[i]=arr[i-1]+arr[i-2];
    }
    int ans=arr[n];
    delete[]arr; //arr ka kam hogya
    return ans; 
    
}
int main(){
    int n;
    cin>>n;
    int* dp=new int[n+1]; //fibo(5) calculate krna h toh 6 buckets chahiye (0 1 2 3 4 5)
    for(int i=0;i<=n;i++){
        dp[i]=-1;  //initializing with a non fibonacci number
    }

    cout<<topdownfibo(n,dp)<<endl;  //in case of a very big value galat hi shi pr atleast ans toh aega, int range se bahar hai isliye galat aara hai
    // cout<<fibo(n)<<endl;
    for(int i=0;i<=n;i++){
        cout<<dp[i]<<" ";
    }
    cout<<endl;
    cout<<bottomupfibo(n)<<endl;
}