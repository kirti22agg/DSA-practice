#include<iostream>
#include<cstring>
using namespace std;
int elephantways(int i,int j){
    //base case
    if(i==0 && j==0){
        return 1;
    }
    //recursive case
    int ans=0;
    for(int k=0;k<i;k++){
        ans = ans+elephantways(k,j);
    }
    for(int k=0;k<j;k++){
        ans = ans+elephantways(i,k);
    }
    return ans;
}
int topdownelephantways(int i,int j,int dp[][100]){
    //base case
    if(i==0 && j==0){
        return dp[i][j]=1;
    }
    //recursive case
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int ans=0;
    for(int k=0;k<i;k++){
        ans = ans+topdownelephantways(k,j,dp);
    }
    for(int k=0;k<j;k++){
        ans = ans+topdownelephantways(i,k,dp);
    }
    return dp[i][j]=ans;
}
int bottomupelephantways(int i,int j){
    int dp[100][100]={0};
    
    for(int l=0;l<=i;l++){
        
        for(int m=0;m<=j;m++){
            if(l==0 && m==0){
              dp[l][m]=1;
            }
            else{
               int ans=0;

                for(int k=0;k<i;k++){
               ans = ans+dp[k][m];
            }
            for(int k=0;k<j;k++){
               ans = ans+dp[l][k];
            }
            dp[l][m]=ans;

            }
            
            
        }
    }
    
    return dp[i][j];

}
int main(){
    int i,j;
    cin>>i>>j;
    cout<<elephantways(i,j)<<endl;
    int dp[100][100];
    memset(dp,-1,sizeof(dp));
    cout<<topdownelephantways(i,j,dp)<<endl;
    for(int l=0;l<=i;l++){
        for(int m=0;m<=j;m++){
            cout<<dp[l][m]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<bottomupelephantways(i,j)<<endl;




}