#include <iostream>
#include <queue>
using namespace std;
#define Minheap priority_queue<int,vector<int>,greater<int> >   
void print( Minheap h ){
    while(!h.empty()){
            cout<<h.top()<<" ";
            h.pop();
    }
    cout<<endl;


}
int main(){
    Minheap h;
    int count =0;
    int k=3; //top 3 products dekhne hai
    int n;
    //hme ye ni pta ki input kitni bar lena h
    while(1){ //continuous input lene ke liye
       cin>>n;
       if(n==-1){
        // while(!h.empty()){
        //     cout<<h.top()<<" ";
        //     h.pop();  //agar aise krenge toh sare hi elements hat jaenge heap se, pr hme aage comparison ke liye chahiye vo elements
            //isliye hm ek function bnake print kraenge, kyuki function ka alag scope hoga, toh main pe affect nhi pdega
        // }
        print(h);
       }
       else{
        if(count<k){
            h.push(n);  //pehle 3 elements toh seedha push honge, uske baad comparison start hoga
            count++;
        }
        else{
            if(h.top()<n){
                h.pop(); //upar wala element hi pop hota hai
                h.push(n);
            }
        }
       }

    }
}