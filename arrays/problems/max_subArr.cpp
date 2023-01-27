// Buscar el maximo sub-arr, con la mayor suma se sus elementos
// Solucion O(N3)
// No funciona para Leetcode, se busca O(N)

/*

    arr = {1,2,3,4,5}

    *Sub-arreglos de arr*

    For element at 0th index	{1}, {1,2}, {1,2,3}, {1,2,3,4}, {1,2,3,4,5}
    For element in 1st index	{2}, {2,3}, {2,3,4}, {2,3,4,5}
    For element in 2nd index	{3}, {3,4}, {3,4,5}
    For element in 3rd index	{4}, {4,5}
    For element in 4th index	{5}

    La suma mas alta del sub-arr para este ejemplo es {1,2,3,4,5}
    (Porque sus elementos son +, siempre sera el mas largo)


    (Para el ejemplo de Leetcode son + y -)

    Solucion planteada -> bruta

    Generar cada uno de los sub-arreglos y realizar la suma, el resultado
    se guarda en un vector y regresamos la suma mayor.

*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size(); // tam de arr original

        vector<int> results; // guardar los resultados

        // recorrer todos los elementos, marca la pauta de inicio
        for(int i = 0; i < n; i++){ 

            // marca la pauta de fin del sub-arr
            for(int j = i; j < n; j++){

                int temp_sum = 0;
                
                // recorre desde i del sub-arr hasta el elemento fin del sub-arr para hacer la suma
                for(int k = i; k <= j; k++){
                    temp_sum += nums[k]; 
                }
                
                // guardamos el resultado
                results.push_back(temp_sum);
            }
        }
        
        //imprimir todos los resultados
        for (int i = 0; i < nums.size(); i++)
            cout << results[i] << " ";
        cout << endl;

        //retornar solo el elemento mayor
        return (*max_element(results.begin(), results.end()));
    }
};


// https://leetcode.com/problems/maximum-subarray/

// Valentin Alejandro Ruiz Ortiz