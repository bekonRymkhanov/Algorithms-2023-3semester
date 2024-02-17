#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll infi=(int) 1e9+7;
struct Graph {
    int V;
    vector<vector<int>> adj;
    Graph(int V){
        this->V = V;
        adj.resize(V+1);
    };
    void addEdge(int v, int w,int c){
        adj[v].push_back(w);

    };
    void BFS(int s){
        vector<bool> visited;
        visited.resize(V, false);
        list<int> queue;
        visited[s] = true;
        queue.push_back(s);
        while (!queue.empty()){
            for(auto i:adj[queue.front()]){
                if(!visited[i]){
                    queue.push_back(i);
                    visited[i]=true;
                }
            }
            queue.pop_front();
        }
    };
};
 
int main(){
    ll ver1,ver2,cost;
    ll vertices,edges;
    cin>>vertices>>edges;
    Graph g(vertices);
    for(ll i=0;i<edges;i++){
        cin>>ver1>>ver2>>cost;

    }

    return 0;
}