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

// void solve(string &s){

//     for(int i = 0; i < s.length(); i++){
//         string aux = ""; 
//         aux.push_back(s[i]);
        
//         cout << aux << endl;
        
//         for(int j = i+1; j < s.length(); j++){
//             aux.push_back(s[j]);
            
//             cout << aux << endl;
//         }
//     }
// }

// Recursivo
// Vamos elimnado el ultimo elemento cuando llega a 1, eliminamos el priemro y volvemos.
void solve(string s, string o){
    cout << s << endl;
    
    if(s.length() <= 1){
        if(o.length() <= 1)
            return;
        else {
            o.erase(0, 1);
            solve(o, o);
        }
    }
    else
    {
        s.pop_back();
        solve(s, o);
    }
}

int main()
{
    string s;
    getline(cin, s);
    
    // solve(s);
    // solve(s, s);

    return 0;
}

// Valentin Alejandro Ruiz Ortiz

// https://www.geeksforgeeks.org/program-print-substrings-given-string/