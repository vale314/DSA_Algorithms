class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int max_global = nums[0];
        int max_product = nums[0];
        int min_product = nums[0];

        for(int i = 1; i < nums.size(); i++){

            int a = nums[i] * max_product;
            int b = nums[i] * min_product;

            max_product = max(max(a,b), nums[i]);
            min_product = min(min(a,b), nums[i]);

            max_global = max(max_product, max_global);

            // cout << "Num: " << nums[i] << endl;
            // cout << "min_product: "<< min_product << endl;
            // cout << "max_product: "<< max_product << endl;
            // cout << "max_global: "<< max_global << endl << endl;

        }
        
        return max_global;
    }
};


// https://leetcode.com/problems/maximum-product-subarray/description/

// Valentin Alejandro Ruiz Ortiz