#include <iostream>
#include <algorithm>
using namespace std;
bool amiabletoplaceatmid(int *stalls,int n,int dist,int c){
    
   int prev=stalls[0]; //previous cow ko kis jagah rkha(hmne pehli cow ko toh 1st stall pe hi daala)
   int cp=1;   //cows placed =1 (ek cow ko rkh chuke hai)
   for(int i=1;i<n;i++){
    if(stalls[i]-prev>=dist){
        cp++;
        prev=stalls[i];
        if(cp==c){
            return true;  //sari cows place hogai
        }
    }
   }
   if(cp<c){  //koi cow bach gai
    return false;
   }
   return true;  //agar 1 hi cow h and 1 hi stall toh loop toh chalega ni pr rteurn toh true hona chahiye

}

int main(){
    int n,c;
    cin>>n>>c;
    int stalls[1000000009];
    for(int i=0;i<n;i++){
        cin>>stalls[i];
    }
    sort(stalls,stalls+n);
    int s=0;
    int e=stalls[n-1]-stalls[0];
    int ans=0;
    while(s<=e){
        int mid=(s+e)/2;
    
        if(amiabletoplaceatmid(stalls,n,mid,c)){
            ans=mid;  //agar mid pe place kr paa rhe h toh use kahi store kra lenge
            s=mid+1;
        }
        else{
            e=mid-1;
        }
    }
    cout<<ans<<endl;
    
}




