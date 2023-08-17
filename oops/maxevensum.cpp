#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int maxsum(int n,vector<int> nums){
    int possum=0;
    for(int i=0;i<n;i++){
        if(nums[i]>0){
            possum+=nums[i];
        }

    }
    if(possum%2==0){
        return possum;
    }
    int ans=INT_MIN;
    for(int i=0;i<n;i++){
        if(nums[i]%2!=0){
            if(nums[i]>0){
                ans=max(ans,possum-nums[i]);
            }
            else{
                ans=max(ans,possum+nums[i]);
            }
        }
    }
    return ans;

}
int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    cout<<maxsum(n,nums); 



}