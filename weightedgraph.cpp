#include<iostream>
#include<cstring>
#include<unordered_map>
#include<list>
#include<queue>
#include <set>
using namespace std;
template<typename T>
class graph{
    unordered_map<T,list<pair<T,int>>> h;
    public:
    void addEdge(T src,T des, int dist,bool bidir=true){
        h[src].push_back(make_pair(des,dist));
        if(bidir){
           h[des].push_back(make_pair(src,dist));

        }
    }

    void printlist(){
        for(auto node:h){
            cout<<node.first<<" : ";
            for (auto neighbour:node.second){
                cout<<"("<<neighbour.first<<","<<neighbour.second<<") ";
            }
            cout<<endl;
        }
    }

    int dijkstra(T src,T dest){
        unordered_map<T,int> distance;
        for(auto node:h){
            distance[node.first]=INT_MAX;
        }
        distance[src]=0;
        unordered_map<T,T> p; //to remember the parent of the node
        p[src]=src;
        set<pair<int,T>> s;
        s.insert(make_pair(0,src));
        while(!s.empty()){
        auto node=*(s.begin());
        s.erase(s.begin());
        int parentdist=node.first;
        T parent=node.second;
        
        for(auto children:h[parent]){
            int edgedist=children.second;
            if(distance[children.first]>parentdist+edgedist){
                auto f=s.find(make_pair(distance[children.first],children.first));
                if(f!=s.end()){
                    s.erase(f);
                }
                p[children.first]=parent;
                distance[children.first]=parentdist+edgedist;
                s.insert(make_pair(distance[children.first],children.first));
            }
        }
        }

        // for(auto node:distance){
        //     cout<<"min distance of "<<node.first<<" from src is "<<node.second<<endl;
        // }
        // cout<<endl;
        auto temp=dest;
        while(temp!=src){
            cout<<temp<<"<--";
            temp=p[temp];
        }
        cout<<temp<<endl;

        return distance[dest];

    }

};
int main(){
    graph<string> g;
	g.addEdge("Amritsar", "Agra", 1);
	g.addEdge("Amritsar", "Jaipur", 4);
	g.addEdge("Delhi", "Jaipur", 2);
	g.addEdge("Delhi", "Agra", 1);
	g.addEdge("Bhopal", "Agra", 2);
	g.addEdge("Bhopal", "Mumbai", 3);
	g.addEdge("Jaipur", "Mumbai", 8);
	g.printlist();
    cout<<g.dijkstra("Amritsar","Mumbai");

}