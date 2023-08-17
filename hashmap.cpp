#include<iostream>
using namespace std;
class node{
    public:
    int val;
    string key;
    node* next;
    node(string k,int v){
        val=v;
        key=k;
        next=NULL;
    }
};
class hashmap{
    int ts; //table size
    int cs; //current size
    node** arr; //table ka pointer

    int hashfunction(string key){
		int ans=0;
		int mul=1;
		for(int i=0;i<key.length();i++){
			ans+=(key[i]%ts*mul%ts)%ts;
			mul=(mul*29)%ts;
		}
		ans=ans%ts;
		return ans;
	}

    void rehashing(){
		node**oldarr=arr;
		int oldts=ts;
		// double the size of table
		arr=new node*[2*ts];
		ts=2*ts;
		cs=0;
		for (int i = 0; i < ts; ++i)
		{
			arr[i]=NULL;
		}
		// copy key value pairs in new table from old table;
		for(int i=0;i<oldts;i++){
			node*head=oldarr[i];
			while(head){
				insert(head->key,head->val);
				head=head->next;

			}
		}
		delete[]oldarr;
	}


    public:
    //constructor
    hashmap(int size=7){ //default size kuchbhi le skte ho
       cs=0;
       ts=size;
       arr= new node*[ts];
       for(int i=0;i<ts;i++){
        arr[i]=NULL;  //initially jitne bhi pointers h un sb ko null pe point kra rhe h
       }

    }

    
    void insert(string key ,int val){
		int index=hashfunction(key);
		node*n=new node(key,val);
		n->next=arr[index];
		arr[index]=n;
		cs++;
		if((cs/(ts*1.0))>0.6){
			rehashing();
		}

	}

    

    void print(){
        for(int i=0;i<ts;i++){
            cout<<i<<"-->";
            node* head=arr[i]; //linked list ke pehle node ka address hoga arr[i] pe
            while(head){
                cout<<head->key<<" ";
                head=head->next;

            }
            cout<<endl;
        }
    }
    
    node* search(string key){
        int index=hashfunction(key);
        node* head=arr[index];
        while(head){
            if(head->key==key){
                return head;
            }
            head=head->next;
        }
        return NULL;
    }

    int &operator[](string key){
        node* ans=search(key);
        //if ans is NULL,key is not present-->we have to insert this key
        if(ans==NULL){
            int g;
            insert(key,g);
            ans=search(key);
            return ans->val;
        }
        //if ans is not NULL,key is present
        else{
            return ans->val;
        }
    }
};



int main(){
    hashmap h;
    h.insert("mango",100);
    h.insert("kiwi",150);
    h.insert("apple",60);
    h.insert("banana",180);
    h.insert("grapes",60);
    h.print();
    cout<<endl;
    cout<<"after inserting papaya"<<endl;
    h["papaya"]=200;  //insertion

    h.print();
    
    cout<<endl;
    

    cout<<"price of papaya is "<<h["papaya"]<<endl;
    
    cout<<"price of kiwi is "<<h["kiwi"]<<endl; //search
    h["kiwi"]=300;  //updation
    cout<<"price of kiwi after updation is "<<h["kiwi"]<<endl; 
   



    



}