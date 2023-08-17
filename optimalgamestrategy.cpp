#include <iostream>
using namespace std;
#define ll long long int
int coin[40];

ll game(int i,int j){
    //base case
    if(i>j){
        return 0;
    }


    //recursive case
    //option 1
    ll firstpick= coin[i]+min(game(i+2,j),game(i+1,j-1));

    //option 2
    ll lastpick = coin[j]+min(game(i+1,j-1),game(i,j-2));

    return max(firstpick,lastpick);


}
int main(){
    int n;
    cin>>n;
    
    for(int i=0;i<n;i++){
        cin>>coin[i];
    }
    
    cout<<game(0,n-1);

}