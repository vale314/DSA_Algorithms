/*

    Explicacion:
        Dadas dos string, retornar el numero de eliminacion de caracteres
        en ambos string para que queden iguales.

        Ejemplo:
            sea, eat

            OUTPUT: 2 // se debe de eliminar la s, y la t, quedando ea en ambas en comun

        Explicacion:
            Se realiza un longest common subsequence, con el sabemos la cantidad de 
            caracteres en comun, respetando en secuencia.

            El resultado son los carcateres que ambos tienen mas grande en comun.

            Acomulamos el resultado de la diferencia de:
                string1.length - lcs
                string2.length - lcs
            
            y mostramos el resultado.

*/

class Solution {
public:
    int minDistance(string word1, string word2) {
        
        int lcs[word1.length() + 1][word2.length() + 1];

        for(int i = 0; i < word1.length() + 1; i++)
            for(int j = 0; j < word2.length() + 1; j++)
                lcs[i][j] = 0;
        
        for(int i = 1; i < word1.length() + 1; i++){
            for(int j = 1; j < word2.length() + 1; j++){
                if(word1[i - 1] == word2[j - 1])
                    lcs[i][j] = lcs[i - 1][j - 1] + 1;
                else
                    lcs[i][j] = max(lcs[i][j - 1], lcs[i - 1][j]);
            }
        }

        int res = word1.length() - lcs[word1.length()][word2.length()];
        res += word2.length() - lcs[word1.length()][word2.length()];

        return res;
    }
};