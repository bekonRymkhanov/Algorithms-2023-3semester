#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ss short short
ll infi=(int) 1e9+9;

int main(){
    ll V,E;
    int v1,v2,cost;
    cin>>V>>E;
    vector<vector<ll>> adj(V+1,vector<ll>(V+1,infi));
    while(E--){
        cin>>v1>>v2>>cost;
        adj[v1][v2]=cost;
    }
    for(ll k=1;k<=V;k++){
        for(ll i=1;i<=V;i++){
            for(ll j=1;j<=V;j++){
                if(adj[i][j]>adj[i][k]+adj[k][j] && adj[i][k]!=infi && adj[k][j]!=infi){
                    adj[i][j]=adj[i][k]+adj[k][j];
                }
            }
        }
    }
    while(true){
        cin>>v1>>v2;
        cout<<adj[v1][v2]<<endl;
    }
    return 0;
}