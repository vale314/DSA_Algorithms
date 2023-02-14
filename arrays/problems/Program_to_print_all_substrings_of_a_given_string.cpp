/*

    Explicacion del problema:
        Generar todos los substring de una cadena.

        Ejemplo:
            abcd

        Output:
                a 
                b
                c
                d
                ab
                bc
                cd
                abc
                bcd
                abcd
        
        Solucion:

            Dos cilcos for y recorrer cada substring y concatenar y mostrar

            Tiempo Computacional: O(N2)
            Memoria: O(1)

*/

#include <iostream>
#include <vector>

using namespace std;

void solve(string &s){

    for(int i = 0; i < s.length(); i++){
        string aux = ""; 
        aux.push_back(s[i]);
        
        cout << aux << endl;
        
        for(int j = i+1; j < s.length(); j++){
            aux.push_back(s[j]);
            
            cout << aux << endl;
        }
    }
}

int main()
{
    string s;
    getline(cin, s);
    
    solve(s);

    return 0;
}

// Valentin Alejandro Ruiz Ortiz

// https://www.geeksforgeeks.org/program-print-substrings-given-string/