#include <iostream>
#include <algorithm>
using namespace std;
string s1;
void dictionaryorder(string in, string out){
    //base case
    if(in.length()==0){
        if(out>s1){
            cout<<out<<endl;
        }
        return;

    }

    //recursive case
    for(int i=0;i<in.length();i++){
        string chotistring = in.substr(0,i) + in.substr(i+1);  //hme ek character htane ke baad bhi strimg sorted order me chahiye bski ki isliye ye use kiya
        dictionaryorder(chotistring, out + in[i]);  //eg-abc; dictionaryorder(bc," "+a)


    }
}
using namespace std;
int main(){
    string s; //cab
    cin>>s;
    s1=s;  //original input string ko kahi store bhi krana pdega, kyuki usi se toh compare krenge baadme
    sort(s.begin(),s.end());  //abc
    dictionaryorder (s, ""); //empty string jisme hm apna output store krenge

}