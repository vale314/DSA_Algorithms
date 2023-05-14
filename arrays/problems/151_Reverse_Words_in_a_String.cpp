/*

    Explicacion:
        Debemos de voltear una cadena o un string solo las palabras
        sin contar los espacio iniciales y finales.

        Ejemplo:
            "  hello world  "
        
        Outout:
            "world hello"
        
    Solucion:
        Iterar el string e ir concatenado caracteres, e ignorar todos los espacios
        cada espacio que se detecte si la llevamos algo, lo agregamos
        a nuestro arreglo de palabras.

        iteramos al reves el vector y agregamos espacios.

*/


class Solution {
public:
    string reverseWords(string s) {

        vector<string> x;
        
        string aux = "";

        for(int i = 0; i < s.length(); i++){
            
            if(s[i] == ' '){ 
                
                if(aux.length() > 0)
                    x.push_back(aux);

                aux = "";

                continue;
            }
            
            aux.push_back(s[i]);

        }

        if(aux.length() > 0)
            x.push_back(aux);

        aux = "";

        for(int i = x.size()-1; i >= 0; i--){
            aux.append(x[i]);
            if(i > 0)
                aux.append(" ");
        }

        return aux;
    }
};

//https://leetcode.com/problems/reverse-words-in-a-string/description/?envType=study-plan-v2&id=leetcode-75

// Valentin Alejandro Ruiz Ortiz