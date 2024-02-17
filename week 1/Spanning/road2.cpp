#include <bits/stdc++.h>

using namespace std;

void bellman_ford_algorithm(vector<pair<pair<int, int>, int> > &edges, vector<int> &vertices, int &n, int &a, int &b){
    vector<int> distance(n, INT_MAX);
    set<int> paths;
    distance[a] = 0;

    int v = vertices.size()-1;

    while(v--){
        for(vector<pair<pair<int, int>, int> >::iterator e = edges.begin(); e < edges.end(); e++){
            if(distance[(*e).first.first] != INT_MAX && distance[(*e).first.first] + (*e).second < distance[(*e).first.second] ) {
                distance[(*e).first.second] = distance[(*e).first.first] + (*e).second;
                paths.insert(distance[(*e).first.second]);
            }
        }
    }


    cout<<*(--paths.end())<<endl;
}

int main(){
    int n, b, a;
    cin>>n;

    vector<vector<int> > matrix(n, vector<int>(n, 0));
    vector<pair<pair<int, int>, int> > edges;
    vector<int> vertices;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin>>b;
            matrix[i][j] = b;
        }
    }

    cin>>b;
    vertices.push_back(--b);
    cout<<0<<endl;

    for(int i = 1; i < n; i++){
        cin>>b;
        vertices.push_back(--b);

        for(int j = 0; j < i; j++) {
            a = vertices[j];

            edges.push_back(make_pair(make_pair(a, b), matrix[a][b]));
            edges.push_back(make_pair(make_pair(b, a), matrix[b][a]));
        }

    //    for(vector<pair<pair<int, int>, int> >::iterator e = edges.begin(); e < edges.end(); e++){
    //        cout<<(*e).first.first<<","<<(*e).first.second<<": "<<(*e).second<<endl;
    //    }

        a = vertices[i-1];

        bellman_ford_algorithm(edges, vertices, n, a, b);

    }

    return 0;
}
