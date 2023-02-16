/*

    Explicacion: 
        Encontrar si s es un sub-sequence de t

        Ejemplo:
            s = abc
            t = ahbgdc

            s = abh
            t = ahbgdc

        --------------------
        
        Output
            true

            false
        --------------------
        
        Sub-sequence es una palabra que deriva de la combinacion de otra respetando
        la posicion.

        se pueden hacer combinaciones siempre y cuando la letra este despues
        de en la palabra original



*/

class Solution {
public:
    bool isSubsequence(string s, string t) {
        
        if(s.length() == 0) return true;

        int j = 0;
        char current = s[j];
        string aux = "";

        for(int i = 0; i < t.length(); i++){
            
            if(j > s.length() - 1) break;

            if(current == t[i]){
                aux.push_back(t[i]);
                j++;
                current = s[j];
            }
        }

        cout << aux << endl;

        if(aux == s)
            return true;
        else
            return false;
    }
};