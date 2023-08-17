#include <iostream>
using namespace std;
void subsequence(char input[],int i,char output[],int j){
    //base case
    if(input[i]=='\0'){
        output[j]='\0';
        cout<<output<<endl;
        return;
    }

    //recursive case
    //exclude kro
    subsequence(input,i+1,output,j);
    //include kro
    output[j]=input[i];
    subsequence(input,i+1,output,j+1);
    
}
int main(){
    char input[100],output[100];
    cin>>input;
    subsequence(input,0,output,0);
}