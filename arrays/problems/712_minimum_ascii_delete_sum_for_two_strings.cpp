/*

    Explicacion:
        Dados 2 strings, s1 y s2. encontrar el lcs y convertirlo en ascii.

        y con el tomar la diferencia de cada string s1, s2. 

        Ejemplo:
            s1 = sea
            s2 = eat

            //lcs = ea = 198(ascii)

            Output:
                231 (s + t (ascii))

        Solucion:
            LCS, de ambos string y en vez de tomar el valor de la diagonal
            incremtenado en 1 cuando son iguales ambos caracteres, realizar
            la suma y conversion de este caracter a ascii.

            Al final tendremos el ascii del lcs.

            Para cada string, realizamos la sumatoria de sus caracteres en ascii,
            se hace una funcion y queda lineal.

            A lo que solo faltara realizar la diferencia con cada string.
            y al resultado hacer la sumatoria de las cadenas.

            Complejidad Tiempo: O(N*M)

            Memoria: O(1)


*/

class Solution {
public:
    int returnAscii (string &s){
        
        int aux = 0;

        for(int i = 0; i < s.length(); i++){
            aux += int(s[i]);
        }

        return aux;
    }

    int minimumDeleteSum(string s1, string s2) {
        
        int length1 = s1.length()+1;
        int length2 = s2.length()+1;

        int lcs [length1][length2];

        for(int i = 0; i < length1; i++)
            for(int j = 0; j < length2; j++)
                lcs[i][j] = 0;

        for(int i = 1; i < length1; i++){
            for(int j = 1; j < length2; j++){
                if(s1[i - 1] == s2[j - 1]){
                    lcs[i][j] = lcs[i - 1][j - 1] + int(s1[i - 1]);
                }
                else
                    lcs[i][j] = max(lcs[i][j - 1], lcs[i - 1][j]);
            }
        }

        int ans = returnAscii(s1) - lcs[length1 - 1][length2 - 1];
        ans += returnAscii(s2) - lcs[length1 - 1][length2 - 1];

        return ans;
    }
};