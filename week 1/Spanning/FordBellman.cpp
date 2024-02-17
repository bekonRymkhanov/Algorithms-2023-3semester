#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ss short short
ll infi=(int) 1e9+9;
struct Graph {
    int V;
    vector<vector<int>> adj;
    Graph(int V){
        this->V = V;
        adj.resize(V+1,vector<int>(V+1));
    };
    void addEdge(int v1,int v2, int w){
        adj[v1][v2]=w;
    };
    void Ford(int s){
        list<int> queue;
        vector<int> weight(V+1,infi);
        queue.push_back(s);
        weight[s]=0;
        for(ll i=0;i<V-1;i++){
            for(ll j=1;j<=V;j++){
                if(adj[queue.front()][j]+weight[queue.front()]<weight[j] && queue.back()!=j && adj[queue.front()][j]!=0){ 
                    queue.push_back(j);
                    weight[j]=adj[queue.front()][j]+weight[queue.front()];
                }
            }
            queue.pop_front();
        }
        for(ll i=0;i<queue.size();i++){ 
            for(ll j=1;j<=V;j++){ 
                if(adj[queue.front()][j]+weight[queue.front()]<weight[j] && queue.back()!=j && adj[queue.front()][j]!=0){
                    cout<<"YES"; 
                    return; 
                } 
            } 
            queue.pop_front(); 
        } 
    }; 

};
 
int main(){
    ll V,E;
    ll v1,v2,w;
    cin>>V>>E;
    Graph graph(V);
    for(ll i=0;i<E;i++){
        cin>>v1>>v2>>w;
        graph.addEdge(v1,v2,w);
    }
    graph.Ford(1);
    return 0;
}