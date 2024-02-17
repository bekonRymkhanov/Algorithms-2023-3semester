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
    void prim(){
        vector<ll> weight(V,infi);
        vector<ll> parent(V);
        vector<bool> visited(V,false);
        weight[0]=0;
        parent[0]=-1;
        for(ll i=0;i<V-1;i++){
            ll minimal=minimumWeight(weight,visited);
            visited[minimal]=1;
            for(ll i=0;i<adj[minimal].size();i++){
                if(adj[minimal][i]<weight[i] && !visited[i] && adj[minimal][i]!=0){
                    weight[i]=adj[minimal][i];
                    parent[i]=minimal;
                }
            }
        }
        printPrim(weight,parent);
    };
    void printPrim(vector<ll> weight,vector<ll> parent){
        ll totalweight=0;
        for(ll i=1;i<V;i++){
            cout<<parent[i]<<" "<<i<<weight[i]<<endl;
        }
        cout<<totalweight;
    }
};
 
int main(){
    ll v1,v2,weight;
    cin>>V>>E;
    Graph graph(V);
    for(ll i=0;i<E;i++){
        cin>>v1>>v2>>weight;
        for(ll i=v1;i<v2;i++){
            graph.addEdge(i-1,i,weight);
        }
    }
    graph.prim();
    
    return 0;
}