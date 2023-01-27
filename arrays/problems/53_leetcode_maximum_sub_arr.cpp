/*

    Explicacion:

        Funciona con el algoritmo de Kadanes, solo con una diferencias
        
        // Inciamos con el incial elemento como nuestro mayor de la iteracion y nuestro mayor global

        // Y vamos iterando obtenemos el mas grande entre el (maximo iterativo + el elemento actual) y el elemento actual
        // el el global entre el nuevo acomulado de max iterativo y el max global.

        // retornamos el max global

*/


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_global = nums[0];
        int max_iterativo = nums[0];

        for(int i = 1; i < nums.size(); i++){
            
            int actual =  nums[i];

            max_iterativo = max(max_iterativo + actual, actual);
            max_global = max(max_iterativo, max_global);

        }

        return max_global;
        
    }
};




// https://leetcode.com/problems/maximum-subarray/description/

// Valentin Alejandro Ruiz Ortiz