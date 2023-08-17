#include<iostream>
using namespace std;
#define ll long long int
ll a[1000005],prefix[1000005];

int main(){
    int t;  //no. of test cases
    cin>>t;
    while(t--){
        int n;  //no. of elements
        cin>>n;
        //initializing prefix array values with zero
        for(int i=0;i<1000005;i++){
            prefix[i]=0;
        }
        ll sum=0;
        prefix[0]=1; //0 ek bar toh aega hi aega kyuki null set hmesha hoga and uska sum bhi zero hoga, and 0%n also zero
        for (int i=0;i<n;i++){
            cin>>a[i];
            sum+=a[1];
            sum = sum%n;
           sum = (sum+n)%n; //negative values
           prefix[sum]++;  //prefix ke us wale index pe jaake ek add krna hai
         }
         ll ans=0;
         for (int i=0;i<n;i++){
             ll no=prefix[i];
             ans+= (((no)*(no-1))/2);  //nC2


         }
         cout<<ans<<endl;

    }
    return 0;
    
}

