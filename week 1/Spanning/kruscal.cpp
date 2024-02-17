#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ss short int
ll V,E;
ll infi=(int) 1e9;

struct Graph {
    int V;
    vector<vector<ll>> adj;
    vector<ll> ind;
    Graph(int V){
        this->V = V;
        ind.resize(V+1);

    };
    void addEdge(int v, int w,int weight){
        adj.push_back({weight,v,w});
    };
    ll parent(ll i){
        if(ind[i]==i) return i;
        return parent(ind[i]);
    };
    void unite(ll x,ll y){
        ind[x]=y;
    };

    void Kruscal(){
        sort(adj.begin(),adj.end());
        for(ll i=0;i<V;i++)
            ind[i]=i;
        for(auto it:adj){
            ll cost=it[0];
            ll v1=parent(it[1]);
            ll v2=parent(it[2]);
            if(v1!=v2){
                ind[v1]=v2;
                cout<<v1<<" -> "<<v2<<" "<<cost<<endl;
            }

        }
    };
};
 

int main(){
    ll v1,v2,weight;
    cin>>V>>E;
    Graph graph(V);
    for(ll i=0;i<E;i++){
        cin>>v1>>v2>>weight;
        graph.addEdge(v1,v2,weight);
    }
    graph.Kruscal();
    
    return 0;
}