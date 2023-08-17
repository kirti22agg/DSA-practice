#include <iostream>
using namespace std;
char keys[10][10] = {
    " ",
    " ",
    "ABC",
    "DEF",
    "GHI",
    "JKL",
    "MNO",
    "PQRS",
    "TUV",
    "WXYZ"
};
void smartkeypad(char inp[],int i, char out[], int j){
      //base case
      if(inp[i]=='\0'){
        out[j]='\0';
        cout<<out<<endl;
        return;
      }


      //recursive case
      //eg- inp[]==23
      //extracting first digit i.e. 2
      int digit = inp[i] - '0'; 
      for(int k=0; keys[digit][k]!='\0';k++){
        //2 yani abc, ab ek ek krke ise output me store bhi kraenge,output ke zero index pe
        //j putput array ka iterator hai, i input array ka
        out[j] = keys[digit][k];
        smartkeypad(inp,i+1,out,j+1); //i+1 (2 ke liye hm kr chuke, tih ab 3 ke liye recursion krega)
                                      //j+1 (ouput array ke 0th index pe hm daal chuke hai, toh ab next pe jange)
        
      }
}
int main(){
    char inp[100];
    cin>>inp;
    char out[100];
    smartkeypad(inp,0,out,0);  
 
    return 0;
}