#include<iostream>
using namespace std;
int length(char a[]){
    int count=0;
    for(int i=0;a[i]!='\0';i++){
        count++;
    }
    return count;
}
void copy(char a[],char b[]){
    int blen=length(b);
    int i=0;
    while(i<=blen){
        a[i]=b[i];
        i++;

    }


}
int main(){
    int n;
    int maxlength = INT_MIN;
    char maxstring[100];
    cin>>n;
    cin.ignore();  //number ke baad string lere hai
    char arr[100];
    for(int i=0;i<n;i++){
        cin.getline(arr,100);
        int l= length(arr);
        if(maxlength<l){
            maxlength=l;
            copy(maxstring,arr);
            
        }
    


    }

        
    
    
    cout<<"maximum length string is: "<<maxstring<<endl;
    
    cout<<"maximum length: "<<maxlength;



}