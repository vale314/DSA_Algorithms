/*

    Expliacion:
        Dada una cadena de char en binario, (string) determinar cual es el 
        siguiente numero en binario.

        Ejemplo:
            10011 -> 19
            
            Correct Answer:
                10100 -> 20

            1111 -> 15
            10000 -> 16

        Solucion:

            Recorrer el arreglo desde la base hasta el final
            en busca del primer 0 y hacerlo 1 y se finaliza.

            Y en el camino ir cambiando todos los 1 por 0.
        
*/

#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int sum = 0;
    string a = "";
    
    getline(cin, a);
    
    int i = 0;
    for(i = a.length() - 1; i >= 0; i--){
        if(a[i] == '0'){
            a[i] = '1';
            break;
        }
        else
            a[i] = '0';
    }
    
    if(i <= 0)
        a = "1" + a;
    
    cout << a << endl;

    return 0;
}
