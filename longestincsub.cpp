#include<iostream>
#include <vector>
using namespace std;
int lis(int *a,int n){
    int dp[1000];
    for(int i=0;i<1000;i++){
        dp[i]=1;  //min ek size ki to hogi hi subsequence
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(a[i]>a[j]){
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
    }
    //finding the max element in array
    int ans=1;
    int i=0; //to store the index
    for(int j=0;j<n;j++){
        if(ans<dp[j]){
            ans=dp[j];
            i=j;
        }
        

    }
    //printing lis
    vector<int> v;
    int len=ans;
    v.push_back(a[i]);
    len--; //ek element daal diya
    for(int j=i-1;j>=0;j--){
        if(dp[j]==len && a[j]<v[v.size()-1]){
            v.push_back(a[j]);
            len--;
            if(len==0){ //jitni length thi subsequence ki vo puri bhar gai
                break;
            }
        }
    }
    for(int i=v.size()-1;i>=0;i--){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    return ans;


}
int main(){
    int a[]={1,3,2,6,4,7,3,8};
    int n=sizeof(a)/sizeof(int);
    cout<<lis(a,n)<<endl;
    

}