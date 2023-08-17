#include<iostream>
#include<vector>
using namespace std;
string ans="";
string solve(int n,string s,int i){
if(i==n){
    return ans;
}
int ind;  
 if(s[i+1]=='_'){
    ans+='W';

 }
 else if(s[i+1]=='*'){
    
    for(int k=i+2;k<n;k++){
        if(s[k]!='*'){
            ans+='J';
            ind=k;
            break;
        }
    }
    i=ind-1;

    
 }
 return solve(n,s,i+1);






}
int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    cout<<solve(n,s,0);


}