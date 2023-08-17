#include<iostream>
using namespace std;
int main() {
    int init,step,fin;
    cin>>init>>step>>fin;
    float f=init;
    
    while(f<=fin){
        
        int c=(5.0/9)*(f-32);
        cout<<f<<"     "<<c<<endl;
        f=f+step;



    }
}