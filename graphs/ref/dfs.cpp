/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <bits/stdc++.h>

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

void dfs(vector<vector<int>> &graph, map<int, bool> &visit, int current){
    
    cout << current << endl;
    
    visit[current] = true;
    
    for(int i = 0; i < graph[current].size(); i++){
        
        int neig = graph[current][i];
        
        if(visit[neig] == false)
            dfs(graph, visit, neig);
    }
    
}

int main()
{
    int V;
    int u;
    int k;
    
    cin >> V;
    
    vector<vector<int>> graph(V);
    map<int, bool> visit;

    for(int i = 0; i < V; i++){
        cin >> k;
        while(k--){
            cin >> u; u;
            graph[i].push_back(u);
        }
    }

    // imprimirListaAdj(V, graph);
    
    dfs(graph, visit, 0);
    

    return 0;
}
