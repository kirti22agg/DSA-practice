#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> rightsmaller(vector<int> &v){
    int n=v.size();
    stack <pair<int,int>> s;
    vector<int> right_smaller (n);
    for(int i=0;i<n;i++){
        pair<int,int> cur={v[i],i};
        while((!s.empty()) && cur.first<s.top().first){
                right_smaller[s.top().second]=i;
                s.pop();
        }
        s.push(cur);
    }
    while(!s.empty()){
        right_smaller[s.top().second]=n;
        s.pop();

    }
    return right_smaller;

}
int main(){
    int n;
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    vector<int> right_smaller=rightsmaller(v);
    for(int x:right_smaller){
        cout<<x<<" ";
    }
    return 0;
    
}