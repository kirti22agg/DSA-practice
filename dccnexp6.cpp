#include<stdio.h> 
#include<string.h> 
int main() {
    char ip[10000],op[10000]; 
    scanf("%s",&ip); 
    int p=0,i; 
    char temp; 
    for(i=0;ip[i]!='\0';i++) {
        if(ip[i]=='1') p++; 
        op[i]=ip[i]; 
    }
    if(p%2==0){ 
        op[i]='0'; 
        temp='1';
    } 
    else{ 
        op[i]='1'; 
        temp='0';
    } 
    op[i+1]='\0'; 
    printf("Even Parity: %s",op); 
    op[i]=temp; 
    printf("\nOdd Parity: %s",op); 
}