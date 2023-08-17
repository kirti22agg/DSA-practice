#include <iostream>
using namespace std;
void permutation(char *input,int i){
    //base case

    if(input[i]=='\0'){
        cout<<input<<endl;

        return;

    }

    //recursive case
    for(int j=i;input[j]!='\0';j++){
        swap(input[i],input[j]);
        permutation(input,i+1);
        swap(input[i],input[j]); //change ko nullify krenge
        
    }

}
int main(){
    char input[100];
    cin>>input;
    permutation(input,0);
}