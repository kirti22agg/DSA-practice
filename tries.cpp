#include<iostream>
#include<unordered_map>
using namespace std;
class node{
    public:
    char data;
    bool isterminal;
    unordered_map<char,node*> h;
    node(char ch){
        data=ch;
        isterminal=false; //by default false krdiya
    }

};
class trie{
    node* root;
    public:
    trie(){
        root=new node('\0');
    }

    void insert(char *word){
        node* temp=root;
        for(int i=0;word[i]!='\0';i++){
            char ch=word[i];
            if(temp->h.count(ch)){
                temp=temp->h[ch];
            }
            else{
                temp->h[ch]=new node(ch);
                temp=temp->h[ch];
            }
        }
        temp->isterminal=true;
    }

    bool search(char *key){
        node* temp=root;
        for(int i=0;key[i];i++){
            char ch=key[i];
            if(temp->h.count(ch)){
                temp=temp->h[ch];
            }
            else{
                return false;
            }
        }
        return temp->isterminal; //jaha temp hai kya vo mera terminal node hai? kyuki agar terminal node hoga tbhi bol skte h ki vo word tha
    }

};

int main(){
    trie t;
    // char arr[100]="hello"; //warning hat jaegi
    // t.insert(arr);
    t.insert("hello");
    t.insert("helloworld");
    t.insert("hell");
    t.insert("coding");
    t.insert("code");

    // if(t.search("hell")){
    //     cout<<"word is present"<<endl;
    // }
    // else{
    //     cout<<"word is not present"<<endl;
    // }

    while(1){
        char key[100];
        // cin>>key;
        cin.getline(key,100);  //agar space bhi dena chahte toh
        if(t.search(key)){
          cout<<"word is present"<<endl;
        }
        else{
          cout<<"word is not present"<<endl;
        }
    }
}