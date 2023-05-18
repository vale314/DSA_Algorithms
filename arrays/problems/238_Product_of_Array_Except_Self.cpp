/*

    Explicacion:
        Obtener el resultado de la multiplicacion de todos los numeros
        excepto el numero.

        Ejemplo:
            [1, 2, 3, 4]

        Output:
            [1, 2, 6, 24]
        
    Solucion:
        Obtener el prefix de la multiplicacion 
            [1, 2, 6, 24]

            Todos los numeros anterior a el numero son la multiplcacion prefix
        
        Obtener el postfix de la multiplicacion
            [24, 24, 12, 4]
            
            Es lo mismo pero al reves
        
        Salida:
            Multiplicamos la posicion anterior le prefix X porfix y nos da el 
            resultado.

            prefix[pos+1] * posfix[pos-1]

*/


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefix;
        vector<int> posfix;
        vector<int> res;

        int aux = 1;
        for(int i = 0; i < nums.size(); i++){
            prefix.push_back(nums[i] * aux);
            aux = prefix[i];
        }
        
        aux = 1;
        for(int i = nums.size() - 1; i >= 0; i--){
            posfix.push_back(nums[i] * aux);
            aux = nums[i] * aux;
        }

        reverse(posfix.begin(), posfix.end());

        // for(auto i: prefix)
        //     cout << i << " - ";
        // cout << endl;


        // for(auto i: posfix)
        //     cout << i << " - ";
        // cout << endl;

        int n = nums.size()-1;
        for(int i = 0; i < nums.size(); i++){
            if(i == 0){ res.push_back(posfix[i + 1]); continue;}
            if(i == n){ res.push_back(prefix[n - 1]); continue;}

            // cout << prefix[i - 1] << " * " << posfix[n - i] << endl;
            res.push_back(prefix[i - 1] * posfix[i + 1]);
        }

        return res;
    }
};

// https://leetcode.com/problems/product-of-array-except-self/description/?envType=study-plan-v2&id=leetcode-75


// Valentin Alejandro Ruiz Ortiz