#include<iostream>
using namespace std;
#define ll long long int
ll n,m,x,y; //n->total students,m->total discount coupons,x->coupons needed for 100% scholarship,y->coupons to be paid if student performs bad

bool abletogivescholarship(int ans){
    return (ans*x <= m + (n-ans)*y);  
    //lhs= total number of coupons required = bache(ans)*ek bache ko kitne dene h(x)
    //rhs= jitnr mere pas total coupons available hai(m) + jo baki bache (n-ans) unse hm coupons le bhi skte hai*y(jitnr coupons hm unse le skte)
}
int main(){

    cin>>n>>m>>x>>y;
    //search space will be 0 to total number of students, at min kisiko nhi milegi,at max sbko
    int s=0;
    int e=n;
    int ans=0;
    //mid nikalke dekhenge kya utne number of students ko scholarship de skte h
    while(s<=e){
        int mid=(s+e)/2;
        if(abletogivescholarship(mid)){
        ans=mid;
        s=mid+1;

    }
    else{
        e=mid-1;
    }

    }
    cout<<ans;
    
    
    
}