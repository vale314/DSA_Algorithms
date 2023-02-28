/*

    Explicacion: 
        Dada un arreglo de numeros enteros, encontrar la subsecuencia mas grande (solo el tam)

        Las subsecuencias deben ser incrementales.

        Ejemplo:

            [0 1 0 3 2 3 ]
        POS: 0 1 2 3 4 5

            Subsequencias validas:
                
                0. [0]
                1. [0,1] [1]
                2. [0]
                3. [3] [0,1,3]
                4. [0,1,2] [1,2] [0,2]
                5. [0,3] [1,3] [0,1,3] [2,3] [0,1,2,3]


            La subsecuencia mas larga es [0,1,2,3] = 4

            return: 4

        Solucion:
            Realizamos programcion dinamica.
            
            En este caso notamos que si el numero anterior es menor a nosotros,
            solo aumentamos la secuencia + 1 del numero anterior, pues agregamos
            al numero actual y sabemos que es correcto.

            Creamos un arreglo con 1 de tam (arr.nums)
            // 1 es porque todos almenos tienen 1 secuencia ellos mismos

            se realiza un recorrido log. 

            todos los numeros hasta el actual y se pregunta se es menor:
                en la posicion de current = 
                    si es mayor, nos quedamos con el mayor entre,
                        el current dp, o iterador en dp.

*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        int dp[nums.size()];

        for(int i = 0; i < nums.size(); i++)
            dp[i] = 1;

        for(int i = 0; i < nums.size(); i++){
            for(int j = 0; j < i; j++){
                if(nums[j] < nums[i])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
        }

        return *max_element(dp, dp + nums.size());
    }
};


// Valentin Alejandro Ruiz Ortiz

// https://leetcode.com/problems/longest-increasing-subsequence/description/