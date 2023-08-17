#include<iostream>
using namespace std;
int main(){
    int n, rev=0,esum=0,osum=0;

    cin>>n;
    while(n>0){
        int rem=n%10;
        rev= rev*10 + rem;
        n= n/10;
    }
    int erev=rev/10;
    while(rev>0){
        int orem=rev%10;
        osum=osum+orem;
        rev=rev/100;
    }
    
    
    while(erev>0){
        int erem=erev%10;
        esum=esum+erem;
        erev=erev/100;
    }
    cout<<osum<<endl<<esum;
    
    return 0;
}