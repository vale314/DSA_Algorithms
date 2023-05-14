/*

    Explciacion:
        Dado un vector con varios numeros, al realizar la suma de extraCandies
        debe de pasar del mayor numero encontrado en el arreglo.
        y generar un vector bool si pasa true, si no false.

    Solucion:
        Buscar el maximo elemento dentro del vector.

        y preguntar uno por uno.

*/

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        auto max_ele = max_element(std::begin(candies), std::end(candies)); 

        vector<bool> b;
        
        for(int i: candies){
            if(i + extraCandies >= *max_ele )
                b.push_back(true);
            else
                b.push_back(false);
        }

        return b;
    }
};