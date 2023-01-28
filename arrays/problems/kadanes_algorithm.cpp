/*

    Se realiza el algoritmo de Kadanes

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


// https://practice.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/1

// Valentin Alejandro Ruiz Ortiz