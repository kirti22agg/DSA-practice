#include <iostream>
using namespace std;
int length(char a[]){
    int count=0;
    for(int i=0;a[i]!='\0';i++){
        count++;
    }
    return count;
}
void appendstring(char a1[],char a2[]){
    int j=length(a1);
    for(int i=0;i<=length(a2);i++){
        a1[j]=a2[i];
        j++;
    
    }
    cout<<a1;

}

int main(){
    char a1[100],a2[100];
    cin.getline(a1,100);
    cin.getline(a2,100);
    appendstring(a1,a2);

    return 0;
    



}