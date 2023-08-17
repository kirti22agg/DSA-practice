#include<bits/stdc++.h>
 using namespace std;
void dec2bin(int dec){
    for(int i=128;i!=0;i=i>>1) {
        if(dec&i) cout<<"1"; 
        else cout<<"0"; 
    }
}
int main() {
    int i,j; 
    int dec[4]; 
    int bin[8]={128,64,32,16,8,4,2,1}; 
    cout<<"enter IP address:(with space instead of '.') : "; 
    for(i=0;i<4;i++) cin>>dec[i]; 
    cout<<"IP address is :"<<dec[0]<<"."<<dec[1]<<"."<<dec[2]<<"."<<dec[3]<<endl ; 
    for(i=0;i<4;i++) {
        dec2bin(dec[i]); 
        if(i!=3) cout<<"."; 
    }
    return 0; 
}