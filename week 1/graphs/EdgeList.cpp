#include <bits/stdc++.h>
using namespace std;
struct Graph {
    int V;
    vector<list<int> > adj;
    Graph(int V){
        this->V = V;
        adj.resize(V);
    };
    void addEdge(int v, int w){
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
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
 
    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n";
    g.BFS(2);
 
    return 0;
}