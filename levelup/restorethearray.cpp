#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    vector<int> b(n-1);
    vector<int> a(n);
    for(int &x:b){
        cin>>x;
    }
    

    for(int i=0;i<n-1;i++){
        if(i==0 || b[i]<b[i-1]){
            a[i]=b[i];
        }
        
        else{
            a[i]=b[i-1];
        }
    }
    a.back()=b.back();
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    for(int i=0;i+1<n;i++){
        assert(b[i]==max(a[i],a[i+1]));
    }
}
int main(){
    int t;
    cin>>t; 
    while(t--){
        solve();

    }
    
    return 0;
}