#include<iostream>
using namespace std;
int mincoins(int *coins,int i,int target){
    //base case
    if(i==0){
        if(target%coins[0]==0){
            return target/coins[0];
        }
        else{
            return -1;
        }
    }

    //recursive case
    int nottake=0 + mincoins(coins,i-1,target);
    int take=INT_MAX;
    if(coins[i]<=target){
         take= 1+mincoins(coins,i,target-coins[i]);
    }
    return min(nottake,take);
}
int main(){
    int coins[]={4,7,10};
    int n=3;
    int target=3;
    cout<<mincoins(coins,n-1,target);

}