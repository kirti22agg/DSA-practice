#include<iostream>
#include<queue>
using namespace std;
int minindex(queue<int> &q,int sortedindex){
    int min_index=-1;
    int min_val=INT_MAX;
    int n=q.size();
    for(int i=0;i<n;i++){
        int curr=q.front();
        q.pop();
        if(curr<=min_val && i<=sortedindex){
            min_index=i;
            min_val=curr;
        }
        q.push(curr);

    }
    return min_index;

}
void insertatend(queue<int> &q,int min_index){
    int min_val;
    int n=q.size();
    for(int i=0;i<n;i++){
        int curr=q.front();
        q.pop();
        if(i!=min_index){
            q.push(curr);
        }
        else{
            min_val=curr;
        }
    }
    q.push(min_val);

}
void sortqueue(queue<int> &q){
    for(int i=1;i<=q.size();i++){
        int min_index= minindex(q,q.size()-i);
        insertatend(q,min_index);
    }
}
int main(){
    queue<int> q;
    q.push(11);
    q.push(5);
    q.push(4);
    q.push(21);
    sortqueue(q);
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;

    
}