/*

    Explicacion:
        Dado un arreglo de numeros, [1,2,3]
        retornar true si el numero de ocurrencias de cada numero
        es diferente entre ellos.

        Ejemplo:
            [1,2,2,1,1,3]
            [1,2]
        
        Output:
            True
            False

            El primero es true porque el 1:3, 2:2, 3:1
            el segundo es false porque 1:1, 2:1
        
        Solucion:
            Realizamos unordered_map (Hash)
            para tomar el numero de veces

            iteramos sobre el hash, y creamos otro donde el hash sea
            el numero de ocurrencias si ya esta esa ocurrencia se retorna false,
            de lo contrario se hashea.
*/

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map <int, int> hash;
        for(int i = 0; i < arr.size(); i++){

            if(hash.find(arr[i]) != hash.end())
                hash[arr[i]] = hash.at(arr[i]) + 1;
            else
                hash[arr[i]] = 1;
        }

        unordered_map <int, int> aux;

        for(auto i = hash.begin(); i != hash.end(); i++){
            if(aux.find(i->second) != hash.end())
                return false;
            else
                aux[i->second] = 1;
        }

        return true;
    }
};