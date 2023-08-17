#include<iostream>
using namespace std;
int mss(int arr[],int n){
    if(n==1){
        return arr[0];
    }
    int m=n/2; //dividing array into two parts
    int lss=mss(arr,m); //left subarray sum
    int rss=mss(arr+m,n-m); //right subarray sum

    //calculating css(crossing subarray sum)
    int leftsum=INT_MIN;
    int rightsum=INT_MIN;
    int sum=0;
    for(int i=m;i<n;i++){
        sum+=arr[i];
        rightsum=max(rightsum,sum);
    }
    sum=0;
    for(int i=m-1;i>=0;i--){
        sum+=arr[i];
        leftsum=max(leftsum,sum);
    }
    int css=rightsum+leftsum;
    return max(css,max(lss,rss));
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<mss(arr,n)<<endl;


}