#include<iostream>
using namespace std;
void multiply(int a[],int &n,int no){
     //call by reference kiya hai kyuki n ki value change hogi, pehle 1, fir 2, so on
     int carry=0;
     for(int i=0;i<n;i++){
        int product= no*a[i]+carry;
        a[i]=product%10;    // example= 5!= 1*2*3*4*5, 6*4 agar krna hai, toh abhi toh n=1 hi hai, toh ek bar chalega ye loop
        carry=product/10;   // product=24; a[i]=24%10=4; carry=24/10=2
     }
     while(carry!=0){
        a[n]=carry%10;
        carry=carry/10;
        n++;
     }


}
void factorial(int num){
    int a[1000];
    for(int i=0;i<1000;i++){
        a[i]=0;
    }
    a[0]=1;

    int n=1; //counts till how many places i have to go
    for(int i=2;i<=num;i++){
        multiply(a,n,i);
    }
    for(int i=n-1;i>=0;i--){ //to print
          
          cout<<a[i];


    }
    cout<<endl;

}
int main(){
	int num;
	cin>>num;
	factorial(num);

	

}
