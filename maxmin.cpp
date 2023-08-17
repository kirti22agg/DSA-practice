#include<iostream>
#include<climits>
using namespace std;
int main(){
    int n,min=INT_MAX,max=INT_MIN;
    cin>>n;
    int i=1;
    int num;
    float sum=0.0;
    while(i<=n){
        
        cin>>num;
        sum=sum+num;
        if (max<num)
        {
            max=num;

        }
        if (min>num)
        {
            min=num;
        }
        
        
        i=i+1;
    }
    cout<<"mean is equal to "<<sum/n<<endl<<"maximum number is "<<max<<endl<<"minimum number is "<<min;
   
        
}