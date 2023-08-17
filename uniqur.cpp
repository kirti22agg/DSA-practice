#include <iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int uni=0;
    for(int i=0;i<n; i++){
        int num;
        cin>>num;
        
        uni=(uni^num);
    }
    cout<<uni;

}