#include<iostream>
#include<cstring>
using namespace std;
int editdistance(char *s1,char *s2,int i,int j,int dp[][100]){
    //base case
    //i is length of s1, j is length of s2
    if(i==0){
        return dp[i][j]=j;
    }
    if(j==0){
        return dp[i][j]=i;
    }
    //recursive case
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    if(s1[i-1]==s2[j-1]){
        //ignore
        return dp[i][j]=editdistance(s1,s2,i-1,j-1,dp);
    }
    else{
        //replace
        int op1=1+editdistance(s1,s2,i-1,j-1,dp);
        //insert
        int op2=1+editdistance(s1,s2,i,j-1,dp);
        //delete
        int op3=1+editdistance(s1,s2,i-1,j,dp);

        return dp[i][j]= min(op1,min(op2,op3));
    }
    
}

int bottomup(char *s1,char *s2){
    int dp[100][100];
    int n=strlen(s1);
    int m=strlen(s2);
    dp[0][0]=0;
    for(int k=1;k<=n;k++){
        dp[k][0]=k;
    }
    for(int k=1;k<=m;k++){
        dp[0][k]=k;
    }

    for(int i=1;i<=n;i++ ){
        for(int j=1;j<=m;j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j]=dp[i-1][j-1];
            }
            else{
                dp[i][j]=min(dp[i-1][j-1]+1,min(dp[i-1][j]+1,dp[i][j-1]+1));

            }
        }
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return dp[n][m];
}
int main(){
    char s1[1000],s2[1000];
    int dp[100][100];
    memset(dp,-1,sizeof(dp));
    cin>>s1>>s2;
    int i=strlen(s1);
    int j=strlen(s2);
    cout<<editdistance(s1,s2,i,j,dp)<<endl;
    cout<<bottomup(s1,s2)<<endl;

}