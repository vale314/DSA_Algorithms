/*

    Explicacion:
        Con un string binario, retornar cual es la cantidad minima de cambios
        un numero 0 por un 1, o un 1 por un 0.

        para dejar toda la cadena con puros 1 o 0.
        No contar los caracteres si no los bloques de cambio.

        Ejemplo:
            00011110001110
            
            000 - 1111 - 000 - 111 - 0

            En este caso debemos de cambiar el numero menor de bloques.

        Solucion:
            
            Solo debemos de contar la cantidad de bloques y el menor es el resultado.

            se contaran si el anterior es diferente se aumenta en uno de lo contrario
            solo seguimos.

            El resultado que nos de sera cuantos bloques exiten, pero como sabemos
            que si al dividir entre 2, no queda un numero entero, solo tendremos el bloque
            menor.


        00011110001110 -> 5(diferentes) / 2 = 2(el bloque de 1).

*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    string num = "";
    
    getline(cin, num);
    
    const char* num3 = num.c_str();
    
    char prev = ' ';
    int res = 0;
    
    for(int i = 0; i < strlen(num3); i++){
        if(num3[i] != prev)
            res++;
        
        prev = num3[i];
    }
    
    cout << res/2 << endl;
    return 0;
}
