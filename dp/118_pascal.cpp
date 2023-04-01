/*

    Explicacion:
        El triangulo de pascal es una suma de los numeros anteriores
        cuyo perimetro tiene un valor de 1 por definicion.

        Ejemplo:                
                    1
                1       1
            1       2       1
        1       3       3       1


    Solucion:
        Solucion por Programacion dinamica.

        Realizamos un vector de vectores

        donde iteramos el vector anterior n-1.

        Anexamos el 1 al inicio y al final.

        y hacemos push back de la suma de los elementos vector anterior.

        retornar: el vector <vector>

*/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> aux;

        aux.push_back({1});


        for(int i = 0; i < numRows - 1; i++){
            vector <int> aux1;
            aux1.push_back(1);
            for(int j = 0; j < aux[i].size()-1; j++){
                int sum = aux[i][j] + aux[i][j + 1];
                aux1.push_back(sum);
            }
            aux1.push_back(1);
            aux.push_back(aux1);
        }

        return aux;
    }
};

// https://leetcode.com/problems/pascals-triangle/description/

// Valentin Alejandro Ruiz Ortiz