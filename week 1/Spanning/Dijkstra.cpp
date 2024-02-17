#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ss short int
ll V,E;
ll infi=(int) 1e9+9;

struct Graph {
    int V;
    vector<vector<ll>> adj;
    Graph(int V){
        this->V = V;
        adj.resize(V,vector<ll>(V,0));
    };
    void addEdge(int v, int w,int u){
        adj[v][w]=u;
        adj[w][v]=u;
    };
    void parent(ll i,vector<ll> parentSet){
        if(parentSet[i]==-1) {
            cout<<i<<" ";
            return;

        }
        parent(parentSet[i],parentSet);
        cout<<i<<" ";

    };
    int minimumWeight(vector<ll> weight,vector<bool> visited){
        ll min=infi;
        int index;
        for(ll i=0;i<V;i++){
            if(weight[i]<min && !visited[i]) {
                min=weight[i];
                index=i;
            }
        }
        return index;
    };
    void Dijkstra(){
        vector<ll> weight(V,infi);
        vector<ll> parent(V,-1);
        vector<bool> visited(V,false);
        weight[0]=0;
        parent[0]=-1;
        for(ll i=0;i<V-1;i++){
            ll minimal=minimumWeight(weight,visited);
            visited[minimal]=1;
            for(ll i=0;i<adj[minimal].size();i++){
                if(adj[minimal][i]+weight[minimal]<weight[i] && !visited[i] && adj[minimal][i]!=0){
                    weight[i]=adj[minimal][i]+weight[minimal];
                    parent[i]=minimal;
                }
            }
        }
        printDijkstra(weight,parent);
    };
    void printDijkstra(vector<ll> weight,vector<ll> parentSet){
        for(ll i=0;i<V;i++){
            parent(i,parentSet);
            cout<<weight[i]<<endl;
        }
    }
};
 
int main(){
    priority_queue<int> queue;
    queue.
    ll v1,v2,weight;
    cin>>V>>E;
    Graph graph(V);
    for(ll i=0;i<E;i++){
        cin>>v1>>v2>>weight;
        graph.addEdge(v1,v2,weight);
    }
    graph.Dijkstra();
    
    return 0;
}