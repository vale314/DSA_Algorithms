/*

    Explicacion:
        Dado un conjunto de strings de un vector, encontrar el prefijo minimo
        de todos esos string en comun.

        Ejemplo:
            [flower, flow, flight]
        
        Res:
            fl
        
    Solucion:
        Ordenar Lexicograficamente.

        Se realiza esto para tomar el primero y el ultimo string del vector.
        (Pues todos los string medios tendran el prefijo si el ultimo lo tiene)

        recorremos al primero y el ultimo min(first.size(), second.size())

        si son diferente se manda la solucion actual,
        si son iguales se concatena el caracter a la respuesta.

*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        int n = strs.size();
        
        string first = strs[0];
        string second = strs[n-1];

        string res = "";

        for(int i = 0; i < min(first.size(), second.size()); i++){
            if(first[i] != second[i])
                return res;
            res.push_back(first[i]);
        }
        return res;
    }
};