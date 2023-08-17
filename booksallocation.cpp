#include<iostream>
using namespace std;
bool isvalid(int books[],int n,int m, int capacity){
    int st=1;
    int currentpage=0;
    for(int i=0;i<n;i++){
        if(currentpage+books[i]>capacity){
            st++;
            currentpage=books[i]; //next student ko aage se shuru krna h lena pages ko
            if(st>m){
                return false;
            }


        }
        else{
            currentpage+=books[i];
        }

    }
    return true;



}
int bookallocation(int arr[],int n,int m){
    int totalpages=0;
    int s,e;
    for(int i=0;i<n;i++){
        totalpages+=arr[i];
    }

    e=totalpages; 
    s=arr[n-1];
    int finalans;
    while(s<=e){
        int mid=(s+e)/2;
        if (isvalid(arr,n,m,mid)){
            finalans=mid;  //agar vohi sahi hua toh kahi store bhi toh krana pdega na
            e=mid-1;


        }
        else{
            s=mid+1;
        }

    } 
    return finalans;

}
int main(){
    int t;
    int arr[100]; //pages
    cin>>t;
    while(t--){
        int n; //books
        int m; //students
        cin>>n>>m;
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int x=bookallocation(arr,n,m);
        cout<<x;

    }
}