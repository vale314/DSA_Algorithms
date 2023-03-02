/*

    Indexado en 0.

    Grafos de ejemplo
        /0\
      1-----2

    Entrada:
    3
    2
    1 2
    2
    0 2
    2
    0 1
    
    
    // 
    
    
    5
    3
    1 2 3
    0
    1
    4
    0
    0

    //Creacion del grafo:
        Se solicita la cantidad de vertices
        sobre cada vertice preguntamos la catidad de vertices conectados a el 'K'.

        iteramos sobre ese vertice en la lista y a agregamos cada conexcion "u".


*/


#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

void imprimirListaAdj(int V,vector<vector<int>> &adj){
    for(int i = 0; i < V; i++){
        cout << i << "-> ";
        for(int j = 0; j < adj[i].size(); j++)
            cout << adj[i][j] << " - ";
        cout << endl;
    }
    cout << endl;
}

void print_bfs(int V, vector<vector<int>> &graph){
    
    if(V == 0) return;
    
    map<int, bool> visit;
    queue<int> q;
    
    q.push(0);
    while(!q.empty()){
        int current = q.front();
        q.pop();
        
        if(visit.find(current) != visit.end())
            continue;
        
        cout << current << " - ";
        visit[current] = true;
        
        for(int i = 0; i < graph[current].size(); i++)
            if(visit.find(graph[current][i]) == visit.end())
                q.push(graph[current][i]);
    }
    
}

int main()
{
    int V;
    int u;
    int k;
    
    cin >> V;
    
    vector<vector<int>> graph(V);

    for(int i = 0; i < V; i++){
        cin >> k;
        while(k--){
            cin >> u; u;
            graph[i].push_back(u);
        }
    }
    

    imprimirListaAdj(V, graph);
    
    print_bfs(V, graph);

    return 0;
}
