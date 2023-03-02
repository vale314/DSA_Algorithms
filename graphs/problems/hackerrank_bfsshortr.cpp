/*

    Explicacion:
        Dado un grafo, determinar un vector con las distancias para llegar
        a cada uno de los vertices, selecionando un vector de origen con
        el metodo bfs.

    Solucion:
        Dado que no se proporciona una lista de adj, y se proporciona un vector de pares
        con los enlaces entre los vectores.

        Primero se crea la conexion entre los vertices por medio de una lista.

        Se realiza un metodo de bfs normal, con una cola, un vector de visitados.
        
        En este caso tenemso un vector con las distancias, se inicializa en -1.

        Todos los que no este dentro del grafo o no esten conexos. deberan de regresar
        un valor -1

        Todo es normal, pero en el momento de insertar a los nodos vecinos en la cola,
        la distancia de cada vecino es igual a la distancia del nodo actual + 6.

        // 6 por el problema, cada peso debe ser 6 para la suma.

        Operador ternario dentro tiene si es -1, ponga 0, y luego suma 6.
        (es por que es el primero, el nodo de busqueda)

        Al final se elimina el nodo de busqueda del vector de distancias.

*/


#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'bfs' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER m
 *  3. 2D_INTEGER_ARRAY edges
 *  4. INTEGER s
 */

vector<int> bfs(int n, int m, vector<vector<int>> edges, int s) {
    queue<int> q;
    map<int, bool> visit;
    vector<int> distance(n, -1);
    vector <vector<int>> adj(n);
    
    for(int i = 0; i < m; i++){
            int u = edges[i][0] - 1;
            int v = edges[i][1] - 1;
            
            adj[u].push_back(v);
            adj[v].push_back(u);
    }
    
    // cout <<edges[0][0] << endl;
    q.push(s - 1);
    while(!q.empty()){
        int current = q.front();
        q.pop();
        
        if(visit.find(current) != visit.end())
            continue;
        
        visit[current] = true;
        
        for(int i = 0; i < adj[current].size(); i++){
            int vecino = adj[current][i];
            
            if(visit.find(vecino) == visit.end()){
                
                distance[vecino] = (distance[current] == -1 ? 0 : 
                    distance[current]) + 6;
                    
                q.push(vecino);
            }
        }
        
    }
    
    distance.erase(distance.begin() + s - 1);
    return distance;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string first_multiple_input_temp;
        getline(cin, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        int n = stoi(first_multiple_input[0]);

        int m = stoi(first_multiple_input[1]);

        vector<vector<int>> edges(m);

        for (int i = 0; i < m; i++) {
            edges[i].resize(2);

            string edges_row_temp_temp;
            getline(cin, edges_row_temp_temp);

            vector<string> edges_row_temp = split(rtrim(edges_row_temp_temp));

            for (int j = 0; j < 2; j++) {
                int edges_row_item = stoi(edges_row_temp[j]);

                edges[i][j] = edges_row_item;
            }
        }

        string s_temp;
        getline(cin, s_temp);

        int s = stoi(ltrim(rtrim(s_temp)));

        vector<int> result = bfs(n, m, edges, s);

        for (size_t i = 0; i < result.size(); i++) {
            fout << result[i];

            if (i != result.size() - 1) {
                fout << " ";
            }
        }

        fout << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
