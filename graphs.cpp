#include<iostream>
#include<list>
using namespace std;
class graph{
    public:
    list<int> *l; //list type ka pointer, address of array store krega(list type ka array)
    int n;
    graph(int N){
        n=N;
        l=new list<int>[N];
    }
    void addedge(int u,int v,int bidirec=true){ //by default hm bidirectional ko true lere hai
       l[u].push_back(v);
       if(bidirec){
        l[v].push_back(u);
       }

       
    }

    void print(){
        for(int i=0;i<n;i++){
            cout<<i<<"-->";
            for(auto node:l[i]){
                cout<<node<<" ";
            }
            cout<<endl;
        }
    }
};
int main(){
    int ne,nn; //number of edges,number of nodes
    cin>>nn>>ne;
    graph g(nn);
    for(int i=0;i<ne;i++){
        int u,v;
        cin>>u>>v;
        g.addedge(u,v);
    }
    g.print();


}