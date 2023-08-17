#include <iostream>
#define ll long long int
using namespace std;
void mergetwosortedarr(ll *a,ll s,ll e){
    ll mid=(s+e)/2;

    ll i=s;
    ll j=mid+1;
    ll *temp = new ll[2000000];
    ll k=s;
    while(i<=mid && j<=e){
        if(a[i]<a[j]){
            temp[k]=a[i];
            k++;
            i++;
        }
        else{
            temp[k]=a[j];
            k++;
            j++;
        }
    }
    while(i<=mid){  //bacha hua element check krega
       temp[k]=a[i];
       i++;
       k++;

    }
    while(j<=e){
        temp[k]=a[j];
        j++;
        k++;

    }
    for(ll i=s;i<=e;i++){
        a[i]=temp[i];  //copying temp to a
    }
    delete []temp;

}
void mergesort(ll *a,ll s,ll e){
    //base case
    if(s>=e){
        return;
    }

    //recursive case
    ll mid=(s+e)/2;
    mergesort(a,s,mid);
    mergesort(a,mid+1,e);
    mergetwosortedarr(a,s,e);

}
int main(){
    int n;
    cin>>n;
    ll *arr=new ll[2000000];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    mergesort(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    delete []arr;
}