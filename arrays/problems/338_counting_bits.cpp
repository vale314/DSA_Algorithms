/*

    Explicacion:
        Se proporciona un numero n

        generar un arreglo de tamano n + 1, donde cada elemento dentro
        sea la cantidad de 1 que se encuentran en dicho numero (el numero
        es la poscion del arreglo).

        Ejemplo:

            n = 5
            [0, 1,  1,  2,  1,  2]
            0   1   2   3   4   5

            Output:
            
            [0, 1,  1,  2,  1,  2]

        El anterior es la salida y nos muestra la cantidad de 1 que tiene esa
        poscion en binario.

        Solucion:
            Para realizar la solucion de e ste problema, se usara programacion dinamica

            creamos un vector de respuestas y agregamos el 0.

            obtenemos el log2 del numero para tener el 1 mas significativo de nuestro
            numero actual a buscar

            Elevamos dos a la el resultado de log2()
            Son los numeros anteriores a el que solo iteramos y agregaremos uno

            Debemos obtener la diferencia del actual - menos el calculo.

            // https://leetcode.com/problems/counting-bits/discussion/

*/

class Solution {
public:
    vector<int> countBits(int n) {
        vector <int> ans;
        ans.push_back(0);

        for(int i = 1; i <= n; i++){
            int bitMax = log2(i);
            int currentPow = pow(2, bitMax);

            ans.push_back(1 + ans[i - currentPow]);
        }

        return ans;
    }
};

// Valentin Alejandro Ruiz Ortiz

// https://leetcode.com/problems/counting-bits/description/
