/*

    Explicacion del problema:
        retornar la suma maxima de un sub-arr, donde
        los elementos del sub-arr sean consecutivos.

        Ejemplo:

        [10,20,30,5,10,50]

        [10,20,30] = 60

        [5,10,50] = 65

        Solucion:
        
        Algorimto usado Kadanes (dp)
        Se realiza la toma del primer elemento,
        iteramos sobre el arr, si el siguiente es mayor sumamos en current
        si no
        elminamos lo anterior y es ahora el current

        nos quedamos con elmayor entre maxCurrent y maxGlobal.

*/

class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        
        int maxCurrent = nums[0];
        int maxGlobal = nums[0];

        for(int i = 1; i < nums.size(); i++){
            if(nums[i - 1] < nums[i])
                maxCurrent += nums[i];
            else
                maxCurrent = nums[i];

            maxGlobal = max(maxCurrent, maxGlobal);
        }

        return maxGlobal;
    }
};

// https://leetcode.com/problems/maximum-ascending-subarray-sum/description/

// Valentin Alejandro Ruiz Ortiz