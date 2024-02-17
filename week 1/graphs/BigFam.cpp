#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll infi=(int) 1e9+7;

struct Graph {
    ll V;
    vector<list<ll>> adj;
    vector<bool> visited;
    ll BigFam=0;

    Graph(ll V){
        this->V = V;
        adj.resize(V+1);
        visited.resize(V+1,false);
    }
    void addEdge(ll v,ll w){

        adj[v].push_back(w);

    }
    void BFS(ll s){
        BigFam++;
        list<ll> queue;
        visited[s] = true;
        queue.push_back(s);
        while (!queue.empty()){
            // cout<<queue.front()<<" ";
            for(ll i:adj[queue.front()]){
                if(adj[i].size()>adj[queue.front()].size()) BigFam++;
                if(visited[i]) continue;
                queue.push_back(i);
                visited[i]=true;
                
            }
            queue.pop_front();
        }
    }
};

int main(){
    ll size,value1,value2,edges,lowest=infi;
    cin>>size>>edges;
    Graph graph(size);
    for(ll i=0;i<edges;i++){
        cin>>value1>>value2;
        graph.addEdge(value1,value2);
        if(value1<lowest) lowest=value1;
    }
    for(ll i=1;i<=size;i++){
        if(!graph.visited[i])     graph.BFS(i);
    }
    cout<<graph.BigFam;

    return 0;
}