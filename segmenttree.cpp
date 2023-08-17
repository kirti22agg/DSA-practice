#include<iostream>
using namespace std;
const int N=1e5+2;
int arr[N],tree[2*N-1];
void build(int node,int s,int e){
    if(s==e){
        tree[node]=arr[s]; //reaches leaf node
        return;
    }
    int mid=(s+e)/2;
    build(2*node,s,mid); //leftchild ko call krke uska segment create krega
    build(2*node+1,mid+1,e); //rightchild ko call krke uska segment create krega

    tree[node] = tree[2*node]+tree[2*node+1]; //leftsum+rightsum

}

int query(int node,int s,int e,int l,int r){
    if(s>r || e<l){
        return 0;  //no overlapping
    }
    //complete segment //l s... e r
    if(s>=l && e<=r){
        return tree[node];
    }
    //partial overlap
    // l...s...r..e  or s...l..e...r
    //we have to use divide and conquer
    int mid=(s+e)/2;
    int q1= query(2*node,s,mid,l,r);
    int q2=query(2*node+1,mid+1,e,l,r);

    return q1+q2;

}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    build(1,0,n-1);
    for(int i=1;i<=2*n-1;i++){
        cout<<tree[i]<<" ";
    }
    cout<<endl;
    int l,r;
    cin>>l>>r;
    int ans= query(1,0,n-1,l,r);
    cout<<ans<<endl;

}