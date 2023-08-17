#include<iostream>
#include<cstring>
#include<unordered_map>
#include<list>
#include<queue>
using namespace std;
template<typename T>
//generic graph, kisi bhi data type ke liye chal jaega
class graph{
    // unordered_map<string,list<string>> h;
    unordered_map<T,list<T>> h;
    public:
    // void addEdge(T u,T v,bool bidirec=false)
    void addEdge(T u,T v,bool bidirec=false){
        h[u].push_back(v);
        if(bidirec){
            h[v].push_back(u);
        }

    }
    
    void printlist(){
        for(auto node:h){
            cout<<node.first<<" : ";
            for(auto neighbour:node.second){
                cout<<neighbour<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }

    void bfs(T start){
        queue<T> q;
        unordered_map<T,bool> visited;
        q.push(start);
        visited[start]=true;
        unordered_map<T,int> distance;
        distance[start]=0;
        while(!q.empty()){
            T node=q.front();
            q.pop();
            cout<<node<<" ";
            for(auto children:h[node]){
                if(!visited[children]){
                q.push(children);
                visited[children]=true;
                distance[children]=distance[node]+1;
                }
            }
        }
        cout<<endl;
        for(auto temp:distance){
            cout<<"min distance of "<<temp.first<<" from start is "<<temp.second<<endl;
        }
        cout<<endl;

    }

    //single source shortest path
    int sssp(T start,T dest){
        queue<T> q;
        unordered_map<T,bool> visited;
        unordered_map<T,T> parent;
        q.push(start);
        visited[start]=true;
        unordered_map<T,int> distance;
        distance[start]=0;
        parent[start]=start;  //0 ka parent 0 khud
        while(!q.empty()){
            T node=q.front();
            q.pop();

            for(auto children:h[node]){
                if(!visited[children]){
                q.push(children);
                visited[children]=true;
                distance[children]=distance[node]+1;
                parent[children]=node;
                }
            }
        }

        T temp=dest;
        while(temp!=parent[temp]){
            cout<<temp<<"<--";
            temp=parent[temp];
        }
        
        cout<<temp<<endl;

        return distance[dest];



    }



};
int main(){
    // graph<string> g;
    // g.addEdge("Putin", "Trump");
	// g.addEdge("Putin", "Modi");
	// g.addEdge("Putin", "Pope");
	// g.addEdge("Modi", "Trump", true);
	// g.addEdge("Modi", "Yogi", true);
	// g.addEdge("Yogi", "Prabhu");
	// g.addEdge("Prabhu", "Modi");
    // g.printlist();
    graph<int> g;
    int ne,nn;
	cin>>nn>>ne;
	
	for(int i=0;i<ne;i++){
		int u,v;
		cin>>u>>v;
		g.addEdge(u,v);  //bidirec ko true lenge is case me by default

	}
	g.printlist();
    cout<<"BFS"<<endl;
    g.bfs(0);
    // cout<<g.sssp(0,5);
    // 6 7
    // 1 0
    // 0 4
    // 4 2
    // 2 1
    // 2 3
    // 3 4
    // 3 5


    // int board[50] = {0};  //baki jagah zero

	// board[2] = 13; //2 se 15 tk seedhi hai
	// board[5] = 2;
	// board[9] = 18;
	// board[18] = 11;
	// board[17] = -13;
	// board[20] = -14;
	// board[24] = -8;  //24 se 16 tk saanp hai
	// board[25] = -10;
	// board[32] = -2;
	// board[34] = -22;

    // for(int u=0;u<36;u++){
    //     for(int dice=1;dice<=6;dice++){
    //         int v = u + dice + board[u+dice];
    //         g.addEdge(u,v);  //bidirec ni hoga, toh use false krdenge
    //     }
    // }
    // cout<<g.sssp(0,36)<<endl;






}