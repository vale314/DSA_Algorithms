/*

    Explicacion:
        Dado un vector de enteros positivos incluido el 0
        mover todos lo ceros al final del vector
        sin mover la poscion relativa de los elementos.


        No copiar ningun elemento.

        Ejemplo:
            [1, 0, 2, 0, 3]
        
        Outout:
            [1, 2, 3, 0, 0]

    Solucion:
        Iterar todo el vector y cuando se encuntre un 0
        iterar despues de el para encontrar el siguiente 0.

    Tiempo: O(N2)
    Memoria: O(1)

*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        

        
        for(int i = 0; i < nums.size(); i++){
            
            if(nums[i] == 0){
                for(int j = i + 1; j < nums.size(); j++){
                    if(nums[j] != 0){
                        swap(nums[i], nums[j]);
                        break;
                    }
                }
            }
        }
    }
};



// https://leetcode.com/problems/move-zeroes/description/

// Valentin Alejandro Ruiz Ortiz