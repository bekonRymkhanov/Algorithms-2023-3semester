#include <bits/stdc++.h>
using namespace std;
#define ss short int
int cycled;
struct Graph {
    int V;
    bool cycle=false;
    vector<vector<int>> adj;
    list<int> queue;
    vector<ss> visited;
    list<int> cycleVertices;
    Graph(int V){
        this->V = V;
        adj.resize(V+1);
        visited.resize(V+1,0);
    };
    void addEdge(int v, int w){
        adj[v].push_back(w);

    };
    bool DFSCycle(int s,int x,int y){
        visited[s]=2;
        for(auto i:adj[s]){
            if(((s==x && i==y) || (s==y && i==x))) continue;
            if(visited[i]==2){
                 cycle=true;
                 continue;
            }
            DFSCycle(i,x,y);
        }
        visited[s]=1;
        if(cycle) return true;
        return false;
    };
    void DFS(int s){
        queue.push_back(s);
        visited[s]=2;
        for(auto i:adj[queue.back()]){
            if(visited[i]==1) continue;
            if(visited[i]==2){
                cycle=true;
                cycled=i;
                cycleVertices.push_front(i);
                break;
            }
            DFS(i);
            if(cycle){
                cycleVertices.push_front(i);
                if(i==cycled) {
                    cycle=false;
                }
                break;
            }
        }

        visited[s]=1;

    };
};
 
int main(){
    int vertices,edges,x,y;
    cin>>vertices>>edges;
    Graph g(vertices);
    for(int i=0;i<edges;i++){
        cin>>x>>y;
        g.addEdge(x,y);
    }
    for(int i=1;i<=vertices;i++){
        if(g.visited[i]==0){
            g.DFS(i);
        }
        if(g.cycle) break;
    }
    if(g.cycleVertices.size()==0){
        cout<<"YES";
        return 0;
    }
    if(g.cycleVertices.size()==1) g.cycleVertices.push_back(g.cycleVertices.front());
    // for(auto it:g.cycleVertices){
    //     cout<<it<<" ";
    // }
    while(!g.cycleVertices.empty()){
        int x=g.cycleVertices.front();
        g.cycleVertices.pop_front();
        int y=g.cycleVertices.front();

        if(y==0) break;
        g.cycle=false;
        for(int i=1;i<=vertices;i++) g.visited[i]=0;
        for(int i=1;i<=vertices;i++){
            g.cycle|=g.DFSCycle(i,x,y);
        }
        if(!g.cycle){
            cout<<"YES";
            return 0;
        }
    }
    cout<<"NO";
    return 0;
}