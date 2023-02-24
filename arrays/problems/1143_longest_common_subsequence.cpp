/*

    Explicacion:
        Encontrar la secuencia mas larga en comun de dos textos.

        Ejemplo: 
            abcdef
            acef
        
        Salida:
            4
        
        Solucion:
            Solucion por manera recursiva:
                si alguno de los textos, en sus punteros ya se
                pasaron de la longitud se regresa 0.

                si ambos son iguales, se llama a la funcion y se avanza 1,
                ademas se retorna sumando 1.

                Si no, se avanza por la derecha y por la izquierda.

            Solucion por manera dinamica:
                Se crea una matriz de m+1 x n+1, donde la fila 0 y columna 0 = 0.
                Se avanza columa y fila, y en sus diagonales nos quedamos con el mayor.
                Si son iguales se toma el numero de la diagonal + 1.

*/

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2, int x = 0, int y = 0) {
        
    //     if(x >= text1.length() || y >= text2.length())
    //         return 0;
        
    //     if(text1[x] == text2[y])
    //         return (1 + longestCommonSubsequence(text1, text2, x+1, y+1));

    //     else 
    //         return max(longestCommonSubsequence(text1, text2, x+1, y), longestCommonSubsequence(text1, text2, x, y+1));

    // }

        const int length1 = text1.length();
        const int length2 = text2.length();

        int arr[length1+1][length2+1];

        for(int i = 0; i < length1 + 1 ; i++){
            for(int j = 0; j < length2 + 1; j++)
                arr[i][j] = 0;
        }

        for(int i = 1; i < length1 + 1; i++){
            for(int j = 1; j < length2 + 1; j++){
                if(text1[i-1] == text2[j-1]){
                    arr[i][j] = arr[i - 1][j - 1] + 1;
                }
                else
                    arr[i][j] = max(arr[i][j - 1], arr[i - 1][j]);
            }
        }
        return arr[length1][length2];
    }
};





