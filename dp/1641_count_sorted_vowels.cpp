/*

    TIEMPO COMPUTACIONAL: O(N*5)
    MEMORIA: O(1)

    Explicacion:
        dado un numero N, determinar cuales son las combinaciones posibles para ese numero
        con las vocales en orden.

        vocales  = { a e i o u }

        n determina los espacios: 
            ejemplo:
                
                n = 1
                    _ _ _ _ _
                    a e i o u

                n = 2
                    __ __ __ __ __
                    aa ae ai ao au = 5 
                       ee ei eo eu = 4
                          ii io iu = 3
                             oo ou = 2
                                oo = 1
    
    Solucion:
        Para solucionar el problema se realiza programacion dinamica en este caso
        se crea un arreglo de 5 valores, donde todos son 1, por el primer caso.

        Primer caso las vocales solo pueden tener 1 combinacion, n = 1.

        Para el segundo caso y n casos iteramos n veces sobre el arreglo a la inversa.

        Ejemplo:
                    a e i o u
            caso 1: 1 1 1 1 1 = 5
            caso 2: 5 4 3 2 1 = 15
            caso 3: 15 10 6 3 1 = 35
            caso 4: 35 20 10 4 1 = 70

        En cada iteracion es posicion actual = posicion actual + posicion menos 1.

        
        retornar:
            
            - sumatoria de arreglo.
*/

class Solution {
public:
    int countVowelStrings(int n) {
        int arr[] = {1, 1, 1, 1, 1};
        
        int length = sizeof(arr)/sizeof(int);

        for(int i = 1; i < n; i++){
            for(int j = length - 2; j >= 0; j--){
                arr[j] = arr[j] + arr[j + 1];
            }
        }

        int num = 0;
        for(int i = 0; i < length; i++)
            num += arr[i];
        
        return num;
    }
};

// https://leetcode.com/problems/count-sorted-vowel-strings/description/

// Valentin Alejandro Ruiz Ortiz