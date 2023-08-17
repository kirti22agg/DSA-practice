#include<iostream>
#include <string>
using namespace std;
string replacepi(string s,int i){
	if(i+1>=s.length()){
		return s;
	}
	if(s[i]=='p' && i+1<s.length() && s[i+1]=='i' ){
        s = s.substr(0,i) + "3.14" + s.substr(i+2);
    }
    return replacepi(s,i+1);
    
}
int main() {
	int t;
    string s;
    cin>>t;
	while(t--){
        cin>>s;
		cout<<replacepi(s,0);

    }
		

	return 0;
}