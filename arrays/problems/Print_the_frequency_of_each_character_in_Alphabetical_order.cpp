/*

    Explciacion del problema:
        [g e e k s f o r g e e k s]
    
        Impromir la cantidad de veces que se encuentra cada letra dentro
        del arreglo y de manera ordenada.

        Ejemplo: 
             [g e e k s f o r g e e k s]

             e4f1g2k2o1r1s2

        Solucion:

            Crear un arreglo de 25 campos int, para guardar cada repeticion
            de cada letra, para posicionar la letra dentro del 25 solo hacer:
                [x - 'a']
            
            y su inverso:
                (char) (x + 'a')
            
            [x = letter (char) a buscar]
        
        Otra solucion:
            Crear un map, el cual solo guarda el caracter y la frecuencia.


*/

#include <iostream>
#include <map>

using namespace std;

void print(string &s, int n, int maxChar[]){
    for(int i = 0; i <= 25; i++){
        
        if(maxChar[i] > 0){
            int current = maxChar[i];
            char letter = (char) (i + 'a');
            
            cout <<letter<<current;
        }
        
    }
    
    cout << endl;
}

void aux(string s, int n){
    int maxChar [25] = { 0 };
    
    for(int i = 0; i < n; i++){
        char current = s[i];
        maxChar[current - 'a']++;
    }
    
    print(s,n,maxChar);
}

void aux2(string s, int n){
    
    map <char, int> maxChar; 
    
    for(int i = 0; i < n; i++)
        maxChar[s[i]]++;
    
    for(auto it:maxChar)
        cout << it.first << it.second;
    
    cout << endl;
}


int main()
{
    
    string s = "zgeeksforgeeksz";
    int n = s.length();
 
    // aux(s, n);
    aux2(s, n);

    return 0;
}


// https://www.geeksforgeeks.org/print-the-frequency-of-each-character-in-alphabetical-order/

// Valentin Alejandro Ruiz Ortiz