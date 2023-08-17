#include<iostream>
using namespace std;
int main() {
	int n,no;
	cin>>n;
	for(int i=1; i<=n; i++){
		cin>>no;
		int count =0;
		while(no>0){
			count= count+(no&1);
			no = no>>1;

		}
		cout<<count;
	}
	return 0;
}