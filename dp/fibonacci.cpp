/*

    Explicacion:
        Realizar la secuencia de los numeros 0 1 1 2 3 4 5 8 13
        //es la secuencia de los numeros anteriores en sumatoria.

        Solucion por dp.

        Realizar un vector de tamano n+2
            (+1 porque se empieza en 0, +2 por el ultimo elemento se ocupa llegar)
        
        Solucion:

            Realizar un vector de tam n+2
            inicilizar los dos primeros valores. 0 y 1 respectivamente.

            realizar la iteracion de todo el vector.
                realizando el calculo de pos i
                    suma de [pos - 1] + [pos - 2];

            retornamos n (numero a buscar dentro de la secuencia)

            Complejidad: O(1)
            
            Espacio: O(N)

*/


class Solution {
public:
    int fib(int n) {

        // 0 1 1 2 3 5 8 13
        int m = n + 2;
        vector <int> dpa(m, 0);

        dpa[0] = 0;
        dpa[1] = 1;

        for(int i = 2; i <= n; i++)
            dpa[i] = dpa[i - 1] + dpa[i - 2];
        
        return dpa[n];


    }
};

// Valentin Alejandro Ruiz Ortiz

// https://leetcode.com/problems/fibonacci-number/description/
