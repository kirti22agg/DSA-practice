#include <iostream>
#include <ctime>
using namespace std;
int partitionhelper(int *arr,int s,int e){  //jis se hm mid ka index return krenge
    int i=s-1;
    int pivot = arr[e];
    for(int j=s;j<=e-1;j++){
        if(arr[j]<=pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[e]);
    return i+1;

}
int partition(int *arr,int s,int e){  //if the array given is sorted, we have to unsort it
    srand(time(0));
    int r= s+ rand()%(e-s);
    swap(arr[r],arr[e]);
    return partitionhelper(arr,s,e);  //ab make sure hogya ki tc har bar nlogn hi aaye


}
void quicksort(int *arr,int s,int e){
    //base case
    if(s>=e){  //equal isliye kyuki jb vo pivot(arr[e]) pe pahuch gya hoga toh koi kaam ni krna
        return;
    }

    //recursive caes
    int p = partition(arr,s,e);
    quicksort(arr,s,p-1);  //pivot jo hoga uski toh position fix hogai,vo shi jagah pahuch gya,uske aage peeche wale sort krne h ab
    quicksort(arr,p+1,e);  //tail recursion-->without returning anything


}
int main(){
    int n;
    int arr[100];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    quicksort(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

}