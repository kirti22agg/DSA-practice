#include<iostream>
using namespace std;
int minsteps(int n){
    //base case
    if(n==1){
        return 0;
    }

    //recursive case
    int opt1,opt2,opt3;
    opt1=opt2=opt3=INT_MAX;
    opt3=minsteps(n-1);

    if(n%3==0){
        opt1=minsteps(n/3);

    }
    if(n%2==0){
        opt2=minsteps(n/2);
    }
    return min(opt1,min(opt2,opt3))+1;
    

}

int topdownminsteps(int n,int*dp){
    //base case
    if(n==1){
        return dp[n]=0;
    }

    //recursive case
    //calculate krne se pehle check
    if(dp[n]!=-1){
        return dp[n];
    }
    int opt1,opt2,opt3;
    opt1=opt2=opt3=INT_MAX;
    opt3=topdownminsteps(n-1,dp);
    
    if(n%3==0){
        opt1=topdownminsteps(n/3,dp);

    }
    if(n%2==0){
        opt2=topdownminsteps(n/2,dp);
    }
    //return krne se pehle store
    return dp[n]=min(opt1,min(opt2,opt3))+1;
    

}

int bottomupminsteps(int n){
    int*dp=new int[n+1];
    //initialization
    dp[1]=0;

    int opt1,opt2,opt3;

    for(int i=2;i<=n;i++){
        opt1=opt2=opt3=INT_MAX;
        opt1=dp[i-1];
        if(i%2==0){
            opt2=dp[i/2];
        }
        if(i%3==0){
            opt3=dp[i/3];
        }
        dp[i]=min(opt1,min(opt2,opt3))+1;

    }
    for(int i=1;i<=n;i++){
        cout<<dp[i]<<" ";
    }
    cout<<endl;
    return dp[n];

}
int main(){
    int n;
    cin>>n;
    int* dp=new int[n+1];
    for(int i=0;i<=n;i++){
        dp[i]=-1;
    }
    cout<<minsteps(n)<<endl;
    cout<<topdownminsteps(n,dp)<<endl;
    cout<<bottomupminsteps(n)<<endl;

}