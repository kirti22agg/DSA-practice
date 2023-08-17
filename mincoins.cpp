#include<iostream>
using namespace std;
int mincoins(int *coins,int amount,int n){
    //base case
    if(amount==0){
        return 0;
    }
    //recursive case
    int ans=INT_MAX;
    for(int i=0;i<n;i++){
        if(amount-coins[i]>=0){
            int chotaamount=amount-coins[i];
            int chotaans=mincoins(coins,chotaamount,n);

            if(chotaans!=INT_MAX && chotaans<ans){
                ans=chotaans+1;

            }
        }
        
    }
    return ans;
}
int topdownmincoins(int *coins,int amount,int n,int*dp){
    //base case
    if(amount==0){
        return dp[amount]=0;
    }
    //recursive case
    if(dp[n]!=-1){
        return dp[amount];

    }
    int ans=INT_MAX;
    for(int i=0;i<n;i++){
        if(amount-coins[i]>=0){
            int chotaamount=amount-coins[i];
            int chotaans=topdownmincoins(coins,chotaamount,n,dp);

            if(chotaans!=INT_MAX && chotaans<ans){
                ans=chotaans+1;

            }
        }
        
    }
    return dp[amount]=ans;
}

int bottomupmincoins(int *coins,int amount,int n){
    int *dp=new int[amount+1];
    for(int i=0;i<=amount;i++){
        dp[i]=INT_MAX;
    }
    //initialization
    dp[0]=0;
    for(int rup=1;rup<=amount;rup++){
        for(int i=0;i<n;i++){
            if(rup-coins[i]>=0){
                int chotaamount=rup-coins[i];
                dp[rup]=min(dp[chotaamount]+1,dp[rup]);
            }

        }
    }
    for(int i=0;i<=amount;i++){
        cout<<dp[i]<<" ";
    }
    cout<<endl;
    return dp[amount];
}
int main(){
    int coins[]={1,3,5,10};
    int n=sizeof(coins)/sizeof(int);
    int amount;
    cin>>amount;
    cout<<mincoins(coins,amount,n)<<endl;
    int* dp=new int[amount+1];
    for(int i=0;i<=amount;i++){
        dp[i]=-1;
    }
    cout<<topdownmincoins(coins,amount,n,dp);
    cout<<endl;
    cout<<bottomupmincoins(coins,amount,n);


}