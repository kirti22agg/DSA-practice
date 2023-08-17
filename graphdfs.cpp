#include<iostream>
#include<cstring>
#include<unordered_map>
#include<list>
#include<queue>
using namespace std;
template<typename T>
//generic graph, kisi bhi data type ke liye chal jaega
class graph{
    unordered_map<T,list<T> >h;
    //hm nhi chahte ki dfshelper ko main me call kr paye toh hmne ise private krdiya
    void dfshelper(T src,unordered_map<T,bool> &visited){ //by reference kyuki we want changes reflect ho
    // unordered_map<int,bool> visited; //yaha isliye ni liya kyuki dfs ko call krenge jb toh firse naya map bn jaega, pr hme ek hi chhaiye isliye ise main me bnaya
        visited[src]=true;
        cout<<src<<" ";
        for(auto c:h[src]){
            if(!visited[c]){
                dfshelper(c,visited);  //recursion
            }
        }
    

    }

    public:
    void addEdge(T u,T v,bool bidir=true){
		h[u].push_back(v);
		if(bidir){
			h[v].push_back(u);
		}

	}
	void printlist(){
		for(auto node:h){
			// node-->key value
			cout<<node.first<<" : ";
			for(auto neighbour:node.second){
				cout<<neighbour<<" ";
			}
			cout<<endl;


		}
		cout<<endl;

	}

    

    void dfs(T src){
        int comp=1;
        unordered_map<int,bool> visited;  //agar hm unordered map ko main me ni bnana chahte
        dfshelper(src,visited);
        cout<<endl;
        for(auto node:h){
            if(!visited[node.first]){
                dfshelper(node.first,visited);
                cout<<endl;
                comp++;
            }
        }
        cout<<endl;
        cout<<"total number of components are "<<comp<<endl;
    }
};
int main(){
    graph<int> g;
    // int ne,nn;
	// cin>>nn>>ne;
	
	// for(int i=0;i<ne;i++){
	// 	int u,v;
	// 	cin>>u>>v;
	// 	g.addEdge(u,v);  //bidirec ko true lenge is case me by default

	// }
    g.addEdge(0,1);
    g.addEdge(0,4);
    g.addEdge(2,1);
    g.addEdge(2,4);
    g.addEdge(3,4);
    g.addEdge(3,2);
    g.addEdge(3,5);  //user input ni lena pdega

    g.addEdge(11,12);
    g.addEdge(13,12);
    g.addEdge(14,12);

    g.addEdge(100,200);
    g.addEdge(200,300);
    g.addEdge(300,100);

    
	// g.printlist();


    // unordered_map<int,bool> visited;
    g.dfs(0);


}