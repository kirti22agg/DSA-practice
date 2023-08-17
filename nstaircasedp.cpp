#include<iostream>
using namespace std;
int ways(int n,int k){
    //base case
    if(n==0){
        return 1;
    }
    if(n<0){
        return 0;
    }
    //recursive case
    int ans=0;
    for(int i=1;i<=k;i++){
        ans=ans+ways(n-i,k);

    }
    return ans;

}
int topdownways(int n,int k,int*dp){
    //base case
    if(n==0){
        return dp[n]=1;
    }
    if(n<0){
        return 0;
    }
    //recursive case
    if(dp[n]!=-1){
        return dp[n];
    }
    int ans=0;
    for(int i=1;i<=k;i++){
        ans=ans+topdownways(n-i,k,dp);

    }
    return dp[n]=ans;

}
int bottomupways(int n,int k){
    int *dp=new int[n+1];
    dp[0]=1;
    for(int i=1;i<=n;i++){
        int ans=0;
        for(int j=1;j<=k;j++){
            if(i>=j){  //taki negative pe na jaye
               ans=ans+dp[i-j];
            }
            
        }
        dp[i]=ans;
    }
    return dp[n];
}

int nstaircaseoptimized(int n,int k){
    int *dp=new int[n+1];
    dp[0]=1;
    dp[1]=1;
    for(int i=2;i<=n;i++){
        if(i-1-k>=0){
            dp[i]=2*dp[i-1]-dp[i-1-k];
        }
        else{
            dp[i]=2*dp[i-1];
        }
    }
    //k wala loop hatt gya toh timt complexity O(n)
    return dp[n];
}
int main(){
    int n,k;
    cin>>n>>k;
    cout<<ways(n,k)<<endl;
    int *dp=new int[n+1];
    for(int i=0;i<=n;i++){
        dp[i]=-1;
    }
    cout<<topdownways(n,k,dp)<<endl;
    cout<<bottomupways(n,k)<<endl;
    cout<<nstaircaseoptimized(n,k)<<endl;

}